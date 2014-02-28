# Case README
These are the design files for the acrylic case that will accompany my final design. This part is still a work in progress, but some of the preliminary files, which I am planning to order from Seeed sometime soon, have been committed for your viewing pleasure.

The case is not a Sick of Beige standard size. I had a great rant about why, but I put on the GitHub Page to spare you the pain of reading it. Basically, this nonstandard, non-Sick-of-Beige design was a lot cheaper. The SketchUp model is included if you want to edit the original "source". The EPS vector drawing is included if you just want to produce the case at Seeed Studio's laser cutting service or something similar. And a PNG export is also included, if you just want to see what the case looks like.

## Design Parameters
Although this case is not a Sick of Beige standard, it obeys most of the same rules, which makes it look similar.
- 1.6mm radius on the four corner holes (#4 imperial or M3 screw)
- 6mm spacing between the center of a hole and the outer edge of the acrylic (the PCB has 4mm spacing from center of hole to edge of board, so the case is 2mm wider than the PCB on all sides)
- Outer corners rounded with a 4mm radius

However, the holes on my board and case are spaced for exactly 2.25" and 2.95" center-to-center, instead of matching the various golden rectangles that Dangerous Prototypes used. This matches the [mounting points](http://learn.adafruit.com/2-8-tft-touchscreen/mounting-options) on the Adafruit TFT module. The only standard Sick of Beige case size that can contain this TFT is the largest one, DP10080, which was quite expensive to produce compared to this smaller version.

## Formats
I drew the model in SketchUp, because that's where Dangerous Prototypes drew their original Sick of Beige templates. I don't really like SketchUp in general, but I found its Tape Measure tool to be indispensable. Unfortunately, Seeed only takes two formats for laser cutting, EPS (Encapsulated PostScript) or CDR (Corel Draw), inside zip/rar archives. This is probably dictated by the laser cutters they use, but SketchUp's free version doesn't support either of these formats, which is a real pain.

The solution is basically [this](http://www.instructables.com/id/SketchUp-Inkscape-and-Ponoko-Laser-Cutting/). You can use the plugin that this person designed to export an SVG file from SketchUp, and then import the SVG file into Inkscape. Inkscape can export to EPS for free (as in beer and speech), which is what I did. I got a Seeed support tech to look over my EPS file in case it was garbage for the laser cutter, and apparently it was good to go. That EPS file has been included for those who just want to make the case as-is.
