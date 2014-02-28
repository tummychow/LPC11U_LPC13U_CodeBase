---
layout: post
title: Explanation/Rant about Case Size
tags:
 - case
---

A few minutes ago, I just committed the design files for the first "ready-to-manufacture" version of my project's case. I had said earlier that the case would be a Sick of Beige case, as designed by Dangerous Prototypes. The case I just committed was not a Sick of Beige size. What gives?

I was planning to use the DP10080 as I had specified earlier, but there was a significant cost premium for that standardized choice. Now I'll explain why I didn't use it and why I designed a custom size instead. For starters, let me show you two pictures. The first is the DP10080 design, and the second is the current smaller design. These pictures are not to scale.
<img src="{{ site.baseurl }}/public/DP10080.png" alt="DP10080" width=400><img src="{{ site.baseurl }}/public/shrunken.png" alt="shrunken" width=400>

The size of the Adafruit TFT module is rather unfortunate from the standpoint of Seeed Studio's laser cutting service. The holes are separated by 2.95" the long way, and 2.25" the short way ([specs](http://learn.adafruit.com/2-8-tft-touchscreen/mounting-options)). This is too big to fit on the standard DP9056 size of SoB case (the 56mm dimension is too small). In fact, it won't even fit on the DP10062 size (62mm is still too small). It demands the largest, the DP10080 size, which was my original target.

However, Seeed Studio charges a premium when your design goes above a 10x10cm boundary. Upgrading to 20x20cm incurs a significant price markup. The SoB cases are a bit larger than the PCBs they are designed to enclose, so the DP10080 case is a bit more than 10cm in the long direction - big enough to jump from 10x10cm to 20x20cm. Ouch.

As if that wasn't bad enough, there is also a premium for complexity. Designs which have a longer perimeter will need more cutting, which will take more time on the laser cutter, so naturally those designs should be charged more. I agree with this policy completely. Unfortunately, the bigger case has a longer perimeter which bumps up the total length of the laser cut job. Seeed's "easy" benchmark, the minimum cost bracket, is 60cm or less total length. The DP10080 case, with cutouts to mount the Adafruit TFT, had a cutting length of about 72cm.

As of writing, Seeed charges $7.50 for five clear pieces of acrylic, within a 10x10cm boundary, with up to 60cm of cuts. For another five clear pieces of acrylic, but within a 20x20cm boundary, and with up to 180cm of cuts, the price goes up to $21.50 - nearly triple the cost. **Ouch**. That had to be fixed, so I decided to make a custom case which would use the same design principles as the Sick of Beige templates, but shrunken to the minimum to fit the Adafruit TFT module I was using.

In this design, the acrylic sheet is just large enough to place the four holes for the TFT module. This reduces the size of the design to about 87x69mm, which fits within Seeed's 10x10cm boundary. So that's some significant cost reduction right there. (In the DP10080 version, I was using four holes for the PCB, in the original places shown by the standard size, and then I had another four holes, closer together, for the TFT.)

Both designs also had a large rectangular hole in the center. The TFT uses a ribbon cable to connect to the board, so it needs a routing slot to fit the cable through. This hole adds a fair amount of length to the laser cutting job. However, with the smaller case, the total cutting length dropped to about 58cm, just within Seeed's 60cm limit. So that's some more cost savings.

Overall, the current case design fits within the lowest cost bracket Seeed provides for laser cutting, which was worth the trouble of giving up the standard DP10080 design. It's too bad that there wasn't a Sick of Beige design which was a bit closer to the dimensions I needed, but I guess laser cutting services exist to solve problems like these, so I can live with it.


