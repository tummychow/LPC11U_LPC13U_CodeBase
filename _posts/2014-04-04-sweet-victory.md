---
layout: post
title: It Works
tags:
 - hardware
 - status
---

It's been a grim week. The end of lectures approaches, and with it, exams. As usual, I am lazy and not doing my work or studying. But I haven't felt this satisfied in... at least the last two months. My ILI9325 driver is officially functional.

I know I promised a post on breadboarding the LCD but that's not important right now, because the driver works! Let me give you some development background. I think every line of code tells a story, and heaven knows we all love telling stories about ourselves.

The LPC13xx codebase did not have an ILI9325 driver to start, but it did have an HX8347 driver. The chips are *not* compatible, although I often see them referred to in the same breath because they have a similar interface, and because they are among the most common LCD drivers for hobbyists. Generally they're both 2.8" 320x240 with resistive touchscreens, and they feature an 8-bit 8080 interface (or 16-bit, sometimes even 18-bit, depending on the board you get).

TFT drivers are a complicated business so there's a lot of configuration to go around, hence the HX8347 driver couldn't be shoved directly into an ILI9325-driven TFT. Luckily, the predecessor of the LPC13xx codebase (targeting the older LPC1343) did have a driver for this chip. So let me be honest and admit that most of the code I've been working on came from that driver. The logic to drive an 8080 bus, plus the configuration sequences, was in that older driver and my work wouldn't have been possible without it.

The main effort was modifying the GPIO accesses. The LPC1343 and LPC1347 use different GPIO blocks, so the register interfaces are fundamentally incompatible. My contribution to the driver is the use of the LPC1347's GPIO masking feature. This lets you designate a mask over the GPIOs of a port. The mask is paired with a masked port register; reads and writes to this register can only affect bits that are cleared in the mask. This makes it pretty easy to write the 8 data bits in a single move. (Although if you look at my commit history, you'd think I was pretty incompetent, stumbling around this feature. I don't know why it took this long to figure out tbh, I added the masking pretty early on.)

Anyway, as proof of my triumph, check out this fabulous blue color:
<img src="{{ site.baseurl }}/public/beautiful_blue.jpg" alt="bb2" width=600>

You can see the breadboarding for the screen. It's honestly quite straightforward. If you look at `ili9325.h` you'll see the pinouts, clear as day. I might make a schematic fragment to illustrate the connections more clearly later, but right now all I care about is that beautiful blue. (The code is actually alternating blue and red, in sync with the blinky LED, for maximum evidence that it works. You can see the LED is also on in this picture. The cycling between blue and red is pretty quick, and this code is deeply optimized from the previous codebase already, so speed shouldn't be a big problem yet.)
