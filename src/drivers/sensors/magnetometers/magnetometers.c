/**************************************************************************/
/*!
    @file     magnetometers.c
    @author   Nguyen Quang Huy, Nguyen Thien Tin
    @ingroup  Sensors

    @brief    Helper functions for magnetometers

    @code

    error_t error;
    sensors_event_t mag_event;
    sensors_vec_t orientation;

    // Initialise the magnetometer
    error = lsm303magInit();

    while (1)
    {
      if (!error)
      {
        // Get sensor data
        error = lsm303magGetSensorEvent(&mag_event);
        if (!error)
        {
          // Calculate the heading (in degrees)
          magGetOrientation(&mag_event, &orientation);

          // Display the mag and orientation data
          printf("Mag X: %f, Y: %f, Z: %f, Heading: %d\r\n",
            magEvent.magnetic.x,
            magEvent.magnetic.y,
            magEvent.magnetic.z,
            (int)orientation.heading);
        }
        // Wait a bit between sensor updates
        delay(100);
      }
    }

    @endcode

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2013, K. Townsend
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**************************************************************************/
#include "projectconfig.h"
#include "magnetometers.h"
#include "core/eeprom/eeprom.h"
#include <math.h>


/**************************************************************************/
/*!
    @brief  Loads the calibration settings from EEPROM, or returns
            ERROR_UNEXPECTEDVALUE if no calibration data was found

    @param  calib_data    The calib parameter placeholder

    @code

    mag_calib_data_t calib_data;
    ...
    if (magLoadCalData(&calib_data))
    {
      // Do something with the cal data
    }
    else
    {
      printf("No calibration data was found in memory");
    }

    @endcode
*/
/**************************************************************************/
error_t magLoadCalData(mag_calib_data_t *calib_data)
{
  /* Try to read the mag config data from the EEPROM memory */
  uint16_t magConfig;
  ASSERT_STATUS(readEEPROM((uint8_t*)CFG_EEPROM_SENSORS_CAL_MAG_CONFIG, (uint8_t*)&magConfig, 2));

  /* Check the config bit first to make sure data is present, and if not return an error! */
  if (magConfig & SENSORS_CAL_MAG_DATA_PRESENT)
  {
    /* If data is present, load calibration data from EEPROM and assign it to calib_data   */
    calib_data->config = magConfig;
    ASSERT_STATUS(readEEPROM((uint8_t*)CFG_EEPROM_SENSORS_CAL_MAG_SENSORID, (uint8_t*)&calib_data->sensorID, 2));
    ASSERT_STATUS(readEEPROM((uint8_t*)CFG_EEPROM_SENSORS_CAL_MAG_X_SCALE, (uint8_t*)&calib_data->x.scale, 4));
    ASSERT_STATUS(readEEPROM((uint8_t*)CFG_EEPROM_SENSORS_CAL_MAG_X_OFFSET, (uint8_t*)&calib_data->x.offset, 4));
    ASSERT_STATUS(readEEPROM((uint8_t*)CFG_EEPROM_SENSORS_CAL_MAG_Y_SCALE, (uint8_t*)&calib_data->y.scale, 4));
    ASSERT_STATUS(readEEPROM((uint8_t*)CFG_EEPROM_SENSORS_CAL_MAG_Y_OFFSET, (uint8_t*)&calib_data->y.offset, 4));
    ASSERT_STATUS(readEEPROM((uint8_t*)CFG_EEPROM_SENSORS_CAL_MAG_Z_SCALE, (uint8_t*)&calib_data->z.scale, 4));
    ASSERT_STATUS(readEEPROM((uint8_t*)CFG_EEPROM_SENSORS_CAL_MAG_Z_OFFSET, (uint8_t*)&calib_data->z.offset, 4));
  }
  else
  {
    return ERROR_UNEXPECTEDVALUE;
  }

  return ERROR_NONE;
}

/**************************************************************************/
/*!
    @brief  Utilize the sensor data from an accelerometer to compensate
            the magnetic sensor measurements when the sensor is tilted
            (the pitch and roll angles are not equal 0°)

    @param  axis          The given axis (SENSOR_AXIS_X/Y/Z) that is
                          parallel to the gravity of the Earth

    @param  mag_event     The raw magnetometer data to adjust for tilt

    @param  accel_event   The accelerometer event data to use to determine
                          the tilt when compensating the mag_event values

    @code

    // Perform tilt compensation with matching accelerometer data
    sensors_event_t accel_event;
    error = lsm303accelGetSensorEvent(&accel_event);
    if (!error)
    {
      magTiltCompensation(SENSOR_AXIS_Z, &mag_event, &accel_event);
    }

    @endcode
*/
/**************************************************************************/
error_t magTiltCompensation(sensors_axis_t axis, sensors_event_t *mag_event, sensors_event_t *accel_event)
{
  /* Make sure the input is valid, not null, etc. */
  ASSERT(mag_event != NULL, ERROR_INVALIDPARAMETER);
  ASSERT(accel_event != NULL, ERROR_INVALIDPARAMETER);

  float32_t accel_X, accel_Y, accel_Z;
  float32_t *mag_X, *mag_Y, *mag_Z;

  switch (axis)
  {
    case SENSOR_AXIS_X:
      /* The X-axis is parallel to the gravity */
      accel_X = accel_event->acceleration.y;
      accel_Y = accel_event->acceleration.z;
      accel_Z = accel_event->acceleration.x;
      mag_X = &(mag_event->magnetic.y);
      mag_Y = &(mag_event->magnetic.z);
      mag_Z = &(mag_event->magnetic.x);
      break;

    case SENSOR_AXIS_Y:
      /* The Y-axis is parallel to the gravity */
      accel_X = accel_event->acceleration.z;
      accel_Y = accel_event->acceleration.x;
      accel_Z = accel_event->acceleration.y;
      mag_X = &(mag_event->magnetic.z);
      mag_Y = &(mag_event->magnetic.x);
      mag_Z = &(mag_event->magnetic.y);
      break;

    case SENSOR_AXIS_Z:
      /* The Z-axis is parallel to the gravity */
      accel_X = accel_event->acceleration.x;
      accel_Y = accel_event->acceleration.y;
      accel_Z = accel_event->acceleration.z;
      mag_X = &(mag_event->magnetic.x);
      mag_Y = &(mag_event->magnetic.y);
      mag_Z = &(mag_event->magnetic.z);
      break;

    default:
      return ERROR_INVALIDPARAMETER;
  }

  float32_t t_roll = accel_X * accel_X + accel_Z * accel_Z;
  float32_t rollRadians = (float32_t)atan2(accel_Y, sqrt(t_roll));

  float32_t t_pitch = accel_Y * accel_Y + accel_Z * accel_Z;
  float32_t pitchRadians = (float32_t)atan2(accel_X, sqrt(t_pitch));

  float32_t cosRoll = (float32_t)cos(rollRadians);
  float32_t sinRoll = (float32_t)sin(rollRadians);
  float32_t cosPitch = (float32_t)cos(pitchRadians);
  float32_t sinPitch = (float32_t)sin(pitchRadians);

  /* The tilt compensation algorithm                            */
  /* Xh = X.cosPitch + Z.sinPitch                               */
  /* Yh = X.sinRoll.sinPitch + Y.cosRoll - Z.sinRoll.cosPitch   */
  *mag_X = (*mag_X) * cosPitch + (*mag_Z) * sinPitch;
  *mag_Y = (*mag_X) * sinRoll * sinPitch + (*mag_Y) * cosRoll - (*mag_Z) * sinRoll * cosPitch;

  return ERROR_NONE;
}

/**************************************************************************/
/*!
    @brief  Populates the .heading fields in the sensors_vec_t
            struct with the right angular data (0-359°)

            Heading increases when measuring clockwise

    @param  axis          The given axis (SENSOR_AXIS_X/Y/Z)

    @param  event         The raw magnetometer sensor data to use when
                          calculating out heading

    @param  orientation   The sensors_vec_t object where we will
                          assign an 'orientation.heading' value

    @code

    magGetOrientation(SENSOR_AXIS_Z, &mag_event, &orientation);

    @endcode
*/
/**************************************************************************/
error_t magGetOrientation(sensors_axis_t axis, sensors_event_t *event, sensors_vec_t *orientation)
{
  /* Make sure the input is valid, not null, etc. */
  ASSERT(event != NULL, ERROR_INVALIDPARAMETER);
  ASSERT(orientation != NULL, ERROR_INVALIDPARAMETER);

  float32_t const PI = 3.14159265F;

  switch (axis)
  {
    case SENSOR_AXIS_X:
      /* Sensor rotates around X-axis                                                                 */
      /* "heading" is the angle between the 'Y axis' and magnetic north on the horizontal plane (Oyz) */
      /* heading = atan(Mz / My)                                                                      */
      orientation->heading = (float32_t)atan2(event->magnetic.z, event->magnetic.y) * 180 / PI;
      break;

    case SENSOR_AXIS_Y:
      /* Sensor rotates around Y-axis                                                                 */
      /* "heading" is the angle between the 'Z axis' and magnetic north on the horizontal plane (Ozx) */
      /* heading = atan(Mx / Mz)                                                                      */
      orientation->heading = (float32_t)atan2(event->magnetic.x, event->magnetic.z) * 180 / PI;
      break;

    case SENSOR_AXIS_Z:
      /* Sensor rotates around Z-axis                                                                 */
      /* "heading" is the angle between the 'X axis' and magnetic north on the horizontal plane (Oxy) */
      /* heading = atan(My / Mx)                                                                      */
      orientation->heading = (float32_t)atan2(event->magnetic.y, event->magnetic.x) * 180 / PI;
      break;

    default:
      return ERROR_INVALIDPARAMETER;
  }

  /* Normalize to 0-359° */
  if (orientation->heading < 0)
  {
    orientation->heading = 360 + orientation->heading;
  }

  return ERROR_NONE;
}

/**************************************************************************/
/*!
    @brief  Re-scale the sensor event data with the calibration parameter
                calib_output = sensor_output * scale_factor + offset

    @param  axis          The given axis (SENSOR_AXIS_X/Y/Z)

    @param  event         The raw magnetometer sensor data to use when
                          calculating out heading

    @param  calib_data    The calib parameter placeholder

    @code

    sensors_event_t event;
    mag_calib_data_t calib_data;
    ...
     magCalibrateEventData(SENSOR_AXIS_Z, &event, &calib_data);

    @endcode
*/
/**************************************************************************/
error_t magCalibrateEventData(sensors_axis_t axis, sensors_event_t *event, mag_calib_data_t *calib_data)
{
  /* Make sure event and calib_data are valid, not NULL, etc.!*/
  ASSERT(event != NULL, ERROR_INVALIDPARAMETER);
  ASSERT(calib_data != NULL, ERROR_INVALIDPARAMETER);

  switch (axis)
  {
    case SENSOR_AXIS_X:
      event->magnetic.y = event->magnetic.y * calib_data->y.scale + calib_data->y.offset;
      event->magnetic.z = event->magnetic.z * calib_data->z.scale + calib_data->z.offset;
      break;

    case SENSOR_AXIS_Y:
      event->magnetic.x = event->magnetic.x * calib_data->x.scale + calib_data->x.offset;
      event->magnetic.z = event->magnetic.z * calib_data->z.scale + calib_data->z.offset;
      break;

    case SENSOR_AXIS_Z:
      event->magnetic.x = event->magnetic.x * calib_data->x.scale + calib_data->x.offset;
      event->magnetic.y = event->magnetic.y * calib_data->y.scale + calib_data->y.offset;
      break;

    default:
      return ERROR_INVALIDPARAMETER;
  }

  return ERROR_NONE;
}
