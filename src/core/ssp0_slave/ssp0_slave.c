/**************************************************************************/
/*!
    @file     ssp0_slave.c
    @author   K. Townsend (microBuilder.eu)

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2012, K. Townsend (microBuilder.eu)
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

#include "core/gpio/gpio.h"
#include "core/ssp0_slave/ssp0_slave.h"

static uint8_t* ssp0_recv_buff;
static uint32_t ssp0_recv_remainlen;
static SSP_CALLBACK ssp0_recv_callback;

/**************************************************************************/
/*!

*/
/**************************************************************************/
void SSP0_IRQHandler(void)
{
  uint32_t status_register = LPC_SSP0->MIS;
  if(status_register & SSP0_RX_INTERRUPT_MASK)
  {
#if 0
    if((ssp0_recv_buff != NULL))
    {
      if(ssp0_recv_remainlen > 0)
      {
        *ssp0_recv_buff = LPC_SSP0->DR;
        ssp0_recv_buff++;
        ssp0_recv_remainlen--;
      }
      else
      {
        /* disable rx interrupt. */
        LPC_SSP0->IMSC &= ~SSP0_RX_INTERRUPT_MASK;
        /* call done callback function. */
        ssp0_recv_callback();
        /* reset internal variable. */
        ssp0_recv_buff = NULL;
        ssp0_recv_remainlen = 0;
      }
    }
    else
    {
      uint32_t Dummy = LPC_SSP0->DR;
      (void)Dummy;
    }
#else
    LPC_SSP0->DR = spi_DL_slave_state_machine(LPC_SSP0->DR);
#endif
  }

  if(status_register & SSP0_RX_INTERRUPT_CLEAR_MASK)
  {
    LPC_SSP0->ICR = status_register;
  }
}

/**************************************************************************/
/*!
    Set SSP clock to 6.0 MHz
*/
/**************************************************************************/
void ssp0_slaveSetupClock()
{
  /* Divide by 1 for SSPCLKDIV */
  LPC_SYSCON->SSP0CLKDIV = SCB_CLKDIV_DIV1;

  /* (PCLK / (CPSDVSR * [SCR+1])) = (72,000,000 / (2 * [5 + 1])) = 6.0 MHz */
  LPC_SSP0->CR0 = ( (7u << 0)     // Data size = 8-bit  (bits 3:0)
           | (0 << 4)             // Frame format = SPI (bits 5:4)
           #if CFG_SSP_CPOL0 == 1
           | (1  << 6)            // CPOL = 1           (bit 6)
           #else
           | (0  << 6)            // CPOL = 0           (bit 6)
           #endif
           #if CFG_SSP_CPHA0 == 1
           | (1 << 7)             // CPHA = 1           (bit 7)
           #else
           | (0 << 7)             // CPHA = 0           (bit 7)
           #endif
           | SSP0_SCR_5);         // Clock rate = 5     (bits 15:8)

  /* Clock prescale register must be even and at least 2 in master mode */
  LPC_SSP0->CPSR = 2;
}

/**************************************************************************/
/*!
    @brief Initialise SSP0
*/
/**************************************************************************/
void ssp0_slaveInit(void)
{
  uint8_t i, Dummy=Dummy;

  /* Reset SSP */
  LPC_SYSCON->PRESETCTRL &= ~0x1;
  LPC_SYSCON->PRESETCTRL |= 0x01;

  /* Enable AHB clock to the SSP domain. */
  LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 11);

  /* Set P0.8 to SSP MISO0 */
  LPC_IOCON->PIO0_8 &= ~0x07;
  LPC_IOCON->PIO0_8 |= 0x01;

  /* Set P0.9 to SSP MOSI0 */
  LPC_IOCON->PIO0_9 &= ~0x07;
  LPC_IOCON->PIO0_9 |= 0x01;

  /* No LPC_IOCON->SCKLOC register on LPC11Uxx/13Uxx? */
  #if (CFG_SSP_SCK0_LOCATION == CFG_SSP_SCK0_1_29)
    /* Set 1.29 to SSP SCK0 (0.6 is often used by USB and 0.10 for SWD) */
    LPC_IOCON->PIO1_29 = 0x01;
  #elif (CFG_SSP_SCK0_LOCATION == CFG_SSP_SCK0_0_10)
    /* Set 0.10 to SSP SCK0 (may be required for SWD!) */
    LPC_IOCON->SWCLK_PIO0_10 = 0x02;
  #elif (CFG_SSP_SCK0_LOCATION == CFG_SSP_SCK0_0_6)
    /* Set 0.6 to SSP SCK0 (may be required for USB!) */
    LPC_IOCON->PIO0_6 = 0x02;
  #else
    #error "Invalid CFG_SSP_SCK0_LOCATION"
  #endif

  /* Set SPI clock to high-speed by default */
  ssp0_slaveSetupClock();

  /* Clear the Rx FIFO */
  for ( i = 0; i < SSP0_FIFOSIZE; i++ )
  {
    Dummy = LPC_SSP0->DR;
  }

  /* Enable device and set it to slave mode, no loopback */
  LPC_SSP0->CR1 = SSP0_CR1_SSE_ENABLED | SSP0_CR1_MS_SLAVE | SSP0_CR1_LBM_NORMAL;

  ssp0_recv_buff = NULL;
  ssp0_recv_remainlen = 0;
  NVIC_EnableIRQ(SSP0_IRQn);
}

/**************************************************************************/
/*!
    @brief Sends and receive a block of data using SSP0

    @param[in]  recvbufbuf
                Pointer to the rx data buffer
    @param[in]  sendbuf
                Pointer to the tx data buffer
    @param[in]  length
                Block length of the data buffer
*/
/**************************************************************************/
void ssp0_slaveTransfer(uint8_t *recvbuf, uint8_t *sendbuf, uint32_t length)
{
  uint32_t i;
  uint32_t Dummy;

  for ( i = 0; i < length; i++ )
  {
    /* Move on only if NOT busy and TX FIFO not full. */
    while ((LPC_SSP0->SR & (SSP0_SR_TNF_NOTFULL | SSP0_SR_BSY_BUSY)) != SSP0_SR_TNF_NOTFULL);
    if(sendbuf != NULL)
    {
      LPC_SSP0->DR = *sendbuf;
      sendbuf++;
    }
    else
    {
      LPC_SSP0->DR = 0xFF;
    }

    while ( (LPC_SSP0->SR & (/*SSP0_SR_BSY_BUSY|*/SSP0_SR_RNE_NOTEMPTY)) != SSP0_SR_RNE_NOTEMPTY );
    /* Whenever a byte is written, MISO FIFO counter increments, Clear FIFO
    on MISO. Otherwise, when this function is called, previous data byte
    is left in the FIFO. */
    if(recvbuf != NULL)
    {
      *recvbuf = LPC_SSP0->DR;
      recvbuf++;
    }
    else
    {
      Dummy = LPC_SSP0->DR;
      (void)Dummy;
    }
  }
}

/**************************************************************************/
/*!
    @brief receive a block of data using SSP0

    @param[in]  buf
                Pointer to the data buffer
    @param[in]  len
                length of the data buffer
    @param[in]  callback
                Function pointer to be called when done.
    @return     Number of received data.
*/
/**************************************************************************/
void ssp0_slaveInterruptRecv(uint8_t* buf, uint32_t len, SSP_CALLBACK callback)
{
  ssp0_recv_buff = buf;
  ssp0_recv_remainlen = len;
  ssp0_recv_callback = callback;
  /* set interrupt on recv. */
  LPC_SSP0->IMSC |= SSP0_RX_INTERRUPT_MASK;
}

/**************************************************************************/
/*!

*/
/**************************************************************************/
void ssp0_slave_send(uint8_t const * buf, uint32_t length)
{
  ssp0_slaveTransfer(NULL, (uint8_t*)buf, length);
}

void ssp0_slave_enable_RXIRQ(void)
{
	LPC_SSP0->IMSC |= SSP0_RX_INTERRUPT_MASK;
}

void ssp0_slave_disable_RXIRQ(void)
{
	LPC_SSP0->IMSC &= ~SSP0_RX_INTERRUPT_MASK;
}
