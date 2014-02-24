---
layout: post
title: Seeed Order Coming Soon
tags:
 - case
---

Should be ordering from Seeed soon. I printed out the PCB layout to scale and checked the footprints with actual parts, so it's ready to be ordered and stuffed. However, I wanted to consolidate that with the laser-cutting order for the case (Sketchup files coming soon), and I encountered some confusion.

Seeed's documentation is not clear about the laser cutter file format. On the specifications, they say to submit EPS/CDR files, but on the actual submission page, they say to submit zip/rar archives (contents unspecified). Below that is an example submission, which is in DWG format. On top of that, an old [Dangerous Prototypes tutorial](http://dangerousprototypes.com/2012/08/01/customizing-sick-of-beige-cases-for-laser-cutting/) uses SVG files in zip archives. I've emailed support and I don't want to order until I get a response. If you've ordered recently and are reading this, I'd love to know what format you used, because I do not want to make a mistake.

In other news, the Arch Linux package for GCC Arm Embedded has recently been moved to [\[community\]](https://www.archlinux.org/packages/community/x86_64/arm-none-eabi-gcc/). The AUR package also contained `binutils` and `gdb`, both of which are now in [separate](https://www.archlinux.org/packages/community/x86_64/arm-none-eabi-binutils/) [packages](https://www.archlinux.org/packages/community/x86_64/arm-none-eabi-gdb/). The old package was a copy-and-paste of the precompiled tarball from [launchpad](https://launchpad.net/gcc-arm-embedded); the new package is compiled from source with newlib.

One consequence of this is that the linker specs for newlib-nano are no longer part of the package, as I [discovered](https://bugs.archlinux.org/task/39004). The reason for not including them is good (newlib-nano is aiming to be merged into newlib, so once that happens, the Arch package will be compiled with it), but that broke my Makefile. So heads up to any other Arch Linux users developing with this toolchain: you will need to compile newlib-nano from source and add it yourself until it gets merged into the newlib upstream repository. Alternatively, you can just keep the old AUR package, or remove `--specs=nano.specs` until the library is included.
