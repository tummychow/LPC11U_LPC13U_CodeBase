#PSU
The PSU is just the power supply block of my final project design. If you're curious about my design decisions, documentation follows. I'm building this part on its own first, for a number of reasons:

- power supply is pretty important so I want to make sure it works in a controlled environment. The fewer other pieces on the board, the easier it is to test.
- I need a power supply for breadboarding, and to date I've been using a dreadful old LM3940 with whatever 5V pins I can find on my current toys. If this board works, I can use it as a general 3V3 supply for any project.
- practice some PCB layout. This board is really simple (like a dozenish parts, four of which are connectors) so I can familiarize myself with the Eagle PCB layout workflow before doing a bigger board.

## Regulator
The supply uses a [TLV1117LV33](http://www.ti.com/product/tlv1117lv33) as its main regulator. It's a 3.3V @ 1A part in a SOT-223 and takes up to 5.5Vin, nothing special there. Mostly notable is that it can use ceramic capacitors and I think it was a good price (I did the price research a while ago and now I forget). A lot of regulators, eg the aforementioned LM3940, need electrolytic/tantalum caps because the higher ESR dampens ringing in the regulator's control loop. Those might be cheaper, but the cost of the caps negates the price benefits (at least in small order quantities). You could also put small resistors in series with the caps, but that's an ugly solution if you ask me. Sometimes people use those regulators with ceramic caps. I'm not going to say they're wrong, but I'll stick to the datasheet for my projects.

## Protection circuitry
Big disclaimer: I hardly know anything about ESD and overcurrent protection devices. I've tried to do my research, but expert opinions are always welcome. I designed the board layout so I could easily remove the TVS and short the polyfuse footprint, if they screwed things up and I wanted to test without them.

The protection circuitry is a polyfuse and TVS. The polyfuse is a [Bel Fuse 0ZCJ](http://www.belfuse.com/pdfs/0ZCJ.pdf) rated for 1.1A hold current - probably more than my project needs, but for general use, this PSU should work all the way up to 1A. On the final board, I'll probably shrink it to a smaller one once I know how much current my design consumes.

The TVS is a [Vishay GSOT05C](http://www.vishay.com/docs/85824/gsot03c.pdf). It has a standoff of 5V (matches the USB line of 5V). It's actually two parts in one package, so they're being used in parallel. The TVS comes after the polyfuse so that, if it catches a prolonged overvoltage condition and shorts, the current will eventually trip the polyfuse as well to cut off the entire circuit.

## Bypassing and smoothing
After the TVS is a small [1.5A ferrite bead](http://search.murata.co.jp/Ceramy/image/img/PDF/ENG/L0110S0100BLM18S.pdf). I added it because [Dangerous Prototypes](http://dangerousprototypes.com/2011/08/10/partlist-wednesday-ferrite-bead/) said they generally aren't a big deal. If it causes a problem, short out the footprint and move on.

After that, some bypass caps. Maybe overkill, maybe not, but we'll find out when I test the board. The 10uF caps are X5R 0805, and the 1uF caps are X5R 0603. [Smaller packages are important; they reduce ESL which is the main limiting factor for bypassing effectiveness.](http://electronics.stackexchange.com/questions/15369/characterization-of-bypass-capacitors) They're Samsung right now, because of the price, but I doubt it'll make much difference if you use a different brand.

## Connectors
The USB B jack is the main input. Plenty of USB mains-to-5V@1A adapters on the market due to the smartphone industry. I figure I should use the biggest jack if I have the room, because of mechanical durability. It's a [Samtec](http://www.samtec.com/ftppub/pdf/usb_b.pdf) part right now. Other companies probably have similar footprints but I'm not sure if they'll be drop-in replacements, so use those at your own risk. Samtec has been generous when sending samples to me, so thumbs up for them!

The other connectors are all pieces of standard 0.1" header, two pins each. One header provides a raw connection to USB 5V, another header provides the same connection but after the protective circuitry, and the last header provides the 3V3 which matters the most. I intentionally put the other two on the corners so they would be easier to plug into a breadboard.
