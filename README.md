# ARM ALARM #

A project to create a better alarm clock and learn some ARM Cortex-M3 development in the process.

## FEATURES ##
- the brain is a powerful ARM Cortex-M3 microcontroller ([NXP LPC1347 in LQFP48](http://www.nxp.com/pip/LPC1347FBD48.html)) which significantly outweighs the average Arduino. I wasn't sure I could do the GUI on an AVR and I don't have much background tying me to that platform, so I figured it was safer to just target a bigger micro.
- sexy touchscreen interface. I'm working with the [Adafruit 2.8" touch TFT](http://adafru.it/376) which has an ILI9325 controller and an exposed 4-wire resistive touchscreen, which I'm controlling with a TI TSC2007.
- high-precision real time clock - an [NXP PCF2129AT](http://www.nxp.com/pip/PCF2129AT.html), which has an integrated TCXO. The existence of the [ChronoDot](http://macetech.com/store/index.php?main_page=product_info&cPath=5&products_id=8) seems to make the Maxim DS3231 more popular (plus the DS3231 is software-compatible with Maxim's popular DS1307), but the code base already supports the NXP part, and it's also half as expensive.
- loud. The alarm sound comes from a buzzer, possibly multiple buzzers. If I was going to settle for speakers, I'd just use my phone.
- standard Sick of Beige case ([DP10080](http://dangerousprototypes.com/docs/Sick_of_Beige_compatible_cases)). The case will probably be overkill for the PCB size, but it has to be pretty big because the TFT sits on its face.
- various cool software things that I haven't delivered on yet (but plan to eventually)

The schematics are [here](http://github.com/tummychow/arm-alarm/tree/arm-alarm/sch), but the main board schematic is not even vaguely ready to be manufactured, so I'm not going to release it yet. They're in EAGLE 6.5.0 - sorry to KiCAD users. I actually used KiCAD on a school project and might port the schematic there in the future. In the meantime, gerbers and PNG exports are also included for non-EAGLE users.

## STRUCTURE ##
This project is based on a [codebase](http://github.com/microbuilder/LPC11U_LPC13U_CodeBase) by [microbuilder.eu](http://github.com/microbuilder). I've left the `master` and `development` branches of the original repo intact and I won't be doing any work on them, unless I develop something useful that justifies opening a pull request.

My development will take place on the `arm-alarm` branch. I only change the stuff I use, so most of the original code and documentation persists. Any of my dev/feature branches will be prefixed with `aa-` (for example `aa-buzzertest`), so that they don't overlap with the original branches.

The [GitHub page](http://tummychow.github.io/arm-alarm) for the repository serves as a dev blog, so if you really want to know about my progress, you can follow along there. That Jekyll theme is [Lanyon](http://github.com/poole/lanyon) by [Mark Otto](http://github.com/mdo), plus some personal changes from [my fork](http://github.com/tummychow/lanyon).

## BUILDING ##
I'm working with GCC ARM Embedded on a 32-bit Arch Linux virtual machine (installed from the [AUR](http://aur.archlinux.org/packages/gcc-arm-none-eabi/)), so my toolchain is basically the [Makefile](http://github.com/tummychow/arm-alarm/blob/arm-alarm/Makefile) inherited from the original codebase. Refer to the [original documentation](http://github.com/microbuilder/LPC11U_LPC13U_CodeBase/blob/master/doc/toolchain_make.md) for how to use and modify it. Assuming you have everything set up right, `make all` should produce a usable binary. Unless my code is broken, in which case hopefully I'll know.

The board I'm developing for is custom, but in the development process, I'm breadboarding with an LPCXpresso LPC1347 devboard. For $30 with an onboard debugger, you really can't beat the price (unless you use an ST Discovery board - in which case [this](http://github.com/andysworkshop/stm32plus) might help). One caveat you should be aware of, if you intend to use the Makefile for your development like I did, is that the debugger on those boards is closed-source, and to my knowledge, only compatible with one debugging solution (the LPCXpresso IDE, which is free as in beer, but requires registration). You'll have to use the LPCXpresso IDE if you want to use that debugger, even if you aren't developing in that environment.

Since I'm not programming in LPCXpresso and I don't have any other debug hardware, for now I upload the binaries using [Flash Magic](http://www.flashmagictool.com/). A good old FTDI serial adapter will get the job done. The `firmware.hex` binary is the one you want. The LPC1347 also has a ROM bootloader which makes it look like a mass storage device, and you can copy a binary onto it to program the micro. If you do this, you want the `firmware.bin` binary. I believe the Makefile has a `flash` target which does the copying-over; you can program it that way as well.

## CONTRIBUTING ##
I'll cross this bridge when I get to it. But let me say that this project was designed for my very specific alarm-clock-oriented needs, so I doubt it'll be of great interest to others.

## LICENSE ##
My code and schematics are under the [BSD 3-clause license](https://github.com/tummychow/arm-alarm/blob/arm-alarm/License.txt) Refer to the original [README.md](http://github.com/microbuilder/LPC11U_LPC13U_CodeBase/blob/master/README.md) for the licensing terms of the underlying code base (most of which is also BSD 3-clause, but as that readme stipulates, licensing is on a file-by-file basis).
