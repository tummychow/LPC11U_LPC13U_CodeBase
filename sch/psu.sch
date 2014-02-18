<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="6.5.0">
<drawing>
<settings>
<setting alwaysvectorfont="yes"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="14" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="14" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="sjunglib">
<description>&lt;p&gt;Stephen Jung&lt;/p&gt;</description>
<packages>
<package name="0603">
<description>&lt;b&gt;0603 (1608 Metric)&lt;/b&gt;

&lt;p&gt;Pads: 0.7x 1.0mm&lt;br&gt;
Center-center spacing: 1.5mm&lt;br&gt;
Inner edge spacing: 0.8mm&lt;br&gt;
Outer edge spacing: 2.2mm&lt;/p&gt;

&lt;p&gt;Documented dims: 1.6 x 0.8mm (0.06 x 0.03")&lt;/p&gt;

&lt;p&gt;http://www.panasonic.com/industrial/components/pdf/AOA0000CE1.pdf&lt;/p&gt;</description>
<smd name="2" x="0.75" y="0" dx="0.7" dy="1" layer="1"/>
<smd name="1" x="-0.75" y="0" dx="0.7" dy="1" layer="1"/>
<rectangle x1="-0.8" y1="-0.4" x2="0.8" y2="0.4" layer="51"/>
<text x="-1.8" y="0.9" size="0.8128" layer="25">&gt;NAME</text>
<text x="-1.8" y="-1.5" size="0.6096" layer="27">&gt;VALUE</text>
<wire x1="-1.3" y1="0.7" x2="1.3" y2="0.7" width="0.127" layer="21"/>
<wire x1="1.3" y1="-0.7" x2="-1.3" y2="-0.7" width="0.127" layer="21"/>
</package>
<package name="0805">
<description>&lt;b&gt;0805 (2012 Metric)&lt;/b&gt;

&lt;p&gt;Pads: 1.1 x 1.4mm&lt;br&gt;
Center-center spacing: 2.1mm&lt;br&gt;
Inner edge spacing: 1mm&lt;br&gt;
Outer edge spacing: 3.2mm&lt;/p&gt;

&lt;p&gt;Documented dims: 2.0 x 1.25mm (0.08 x 0.05")&lt;/p&gt;

&lt;p&gt;http://www.panasonic.com/industrial/components/pdf/AOA0000CE1.pdf&lt;/p&gt;</description>
<smd name="2" x="1.05" y="0" dx="1.1" dy="1.4" layer="1"/>
<smd name="1" x="-1.05" y="0" dx="1.1" dy="1.4" layer="1"/>
<rectangle x1="-1" y1="-0.625" x2="1" y2="0.625" layer="51"/>
<wire x1="-1.8" y1="0.9" x2="1.8" y2="0.9" width="0.127" layer="21"/>
<wire x1="1.8" y1="-0.9" x2="-1.8" y2="-0.9" width="0.127" layer="21"/>
<text x="-1.8" y="1.1" size="0.8128" layer="25">&gt;NAME</text>
<text x="-1.8" y="-1.7" size="0.6096" layer="27">&gt;VALUE</text>
</package>
<package name="SOT223-3">
<description>&lt;b&gt;SOT223-3&lt;/b&gt;

&lt;p&gt;Small pads: 1.0 x 2.2 mm&lt;br&gt;
Big pad: 3.4 x 2.2 mm&lt;br&gt;
Pitch between small pads: 2.3mm&lt;br&gt;
Center-center spacing: 5.8mm&lt;/p&gt;

&lt;p&gt;Documented dims: 6.6 x 3.6 mm&lt;br&gt;
Documented small leads: 0.8 x 1.8 mm&lt;br&gt;
Documented big lead: 3.0 x 1.8 mm&lt;/p&gt;

&lt;p&gt;JEDEC: TO-261AA&lt;br&gt;
EIA: &lt;/p&gt;</description>
<wire x1="2" y1="-3.5" x2="-2" y2="-3.5" width="0.127" layer="21"/>
<wire x1="-2" y1="3.5" x2="2" y2="3.5" width="0.127" layer="21"/>
<smd name="1" x="-2.9" y="2.3" dx="1" dy="2.2" layer="1" rot="R270"/>
<smd name="2" x="-2.9" y="0" dx="1" dy="2.2" layer="1" rot="R270"/>
<smd name="3" x="-2.9" y="-2.3" dx="1" dy="2.2" layer="1" rot="R270"/>
<smd name="4" x="2.9" y="0" dx="3.4" dy="2.2" layer="1" rot="R270"/>
<text x="-1.802" y="3.7068" size="0.8128" layer="25">&gt;NAME</text>
<text x="-1.802" y="-4.2768" size="0.6096" layer="27">&gt;VALUE</text>
<rectangle x1="1.2" y1="-0.9" x2="4.2" y2="0.9" layer="51" rot="R270"/>
<rectangle x1="-3.1" y1="-0.9" x2="-2.3" y2="0.9" layer="51" rot="R270"/>
<rectangle x1="-3.1" y1="1.4" x2="-2.3" y2="3.2" layer="51" rot="R270"/>
<rectangle x1="-3.1" y1="-3.2" x2="-2.3" y2="-1.4" layer="51" rot="R270"/>
<wire x1="1.8" y1="3.3" x2="1.8" y2="-3.3" width="0.127" layer="51"/>
<wire x1="1.8" y1="-3.3" x2="-1.8" y2="-3.3" width="0.127" layer="51"/>
<wire x1="-1.8" y1="-3.3" x2="-1.8" y2="3.3" width="0.127" layer="51"/>
<wire x1="-1.8" y1="3.3" x2="1.8" y2="3.3" width="0.127" layer="51"/>
<wire x1="2" y1="3.5" x2="2" y2="2.2" width="0.127" layer="21"/>
<wire x1="2" y1="-3.5" x2="2" y2="-2.2" width="0.127" layer="21"/>
</package>
<package name="USB-B-ONSHORE">
<description>&lt;b&gt;USB-B1HSB6&lt;/b&gt;

&lt;p&gt;Footprint for On-Shore Technologies USB-B1HSB6 USB B jack&lt;/p&gt;

&lt;p&gt;Shield pin drill dia: 2.4mm&lt;br&gt;
Shield pin pad dia: 3.8mm&lt;br&gt;
Bus pin drill dia: 1mm&lt;br&gt;
Bus pin pad dia: 1.6mm&lt;/p&gt;</description>
<pad name="5" x="-6" y="0" drill="2.4" diameter="3.8"/>
<pad name="3" x="-1.25" y="2.7" drill="1" diameter="1.6"/>
<pad name="6" x="6" y="0" drill="2.4" diameter="3.8"/>
<pad name="4" x="1.25" y="2.7" drill="1" diameter="1.6"/>
<pad name="2" x="-1.25" y="4.7" drill="1" diameter="1.6"/>
<pad name="1" x="1.25" y="4.7" drill="1" diameter="1.6"/>
<wire x1="-6" y1="-10.3" x2="-6" y2="6.2" width="0.127" layer="51"/>
<wire x1="6" y1="-10.3" x2="6" y2="6.2" width="0.127" layer="51"/>
<wire x1="-6" y1="6.2" x2="6" y2="6.2" width="0.127" layer="51"/>
<wire x1="-6" y1="-10.3" x2="6" y2="-10.3" width="0.127" layer="51"/>
<wire x1="-6.3" y1="2.2" x2="-6.3" y2="6.5" width="0.127" layer="21"/>
<wire x1="-6.3" y1="6.5" x2="6.3" y2="6.5" width="0.127" layer="21"/>
<wire x1="6.3" y1="6.5" x2="6.3" y2="2.2" width="0.127" layer="21"/>
<text x="2.6" y="4.1" size="0.8128" layer="51">VCC</text>
<text x="-3.9" y="4.1" size="0.8128" layer="51">D-</text>
<text x="2.6" y="2.1" size="0.8128" layer="51">GND</text>
<text x="-3.9" y="2.1" size="0.8128" layer="51">D+</text>
<text x="6.6" y="5.7" size="0.8128" layer="25">&gt;NAME</text>
<text x="6.6" y="4.7" size="0.6096" layer="27">&gt;VALUE</text>
</package>
<package name="USB-B-SAMTEC">
<description>&lt;b&gt;USB-B-S-X-X-TH-X-XX&lt;/b&gt;

&lt;p&gt;Footprint for Samtec USB-B-S-X-X-TH-X-XX USB B jack&lt;/p&gt;

&lt;p&gt;Shield pin drill dia: 2.3mm&lt;br&gt;
Shield pin pad dia: 3.8mm&lt;br&gt;
Bus pin drill dia: 0.9mm&lt;br&gt;
Bus pin pad dia: 1.6mm&lt;/p&gt;</description>
<pad name="5" x="-6.02" y="0" drill="2.3" diameter="3.8"/>
<pad name="6" x="6.02" y="0" drill="2.3" diameter="3.8"/>
<pad name="3" x="-1.25" y="2.7" drill="0.9" diameter="1.6"/>
<pad name="4" x="1.25" y="2.7" drill="0.9" diameter="1.6"/>
<pad name="2" x="-1.25" y="4.7" drill="0.9" diameter="1.6"/>
<pad name="1" x="1.25" y="4.7" drill="0.9" diameter="1.6"/>
<text x="2.5" y="4" size="1.27" layer="51">VCC</text>
<text x="2.5" y="2" size="1.27" layer="51">GND</text>
<text x="-4.5" y="4" size="1.27" layer="51">D-</text>
<text x="-4.5" y="2" size="1.27" layer="51">D+</text>
<wire x1="-6" y1="5.8" x2="-6" y2="-10.4" width="0.127" layer="51"/>
<wire x1="6" y1="-10.4" x2="-6" y2="-10.4" width="0.127" layer="51"/>
<wire x1="6" y1="5.8" x2="6" y2="-10.4" width="0.127" layer="51"/>
<wire x1="-6" y1="5.8" x2="6" y2="5.8" width="0.127" layer="51"/>
<wire x1="-6.3" y1="2.2" x2="-6.3" y2="6.1" width="0.127" layer="21"/>
<wire x1="-6.3" y1="6.1" x2="6.3" y2="6.1" width="0.127" layer="21"/>
<wire x1="6.3" y1="6.1" x2="6.3" y2="2.2" width="0.127" layer="21"/>
<text x="6.7" y="5" size="0.8128" layer="25">&gt;NAME</text>
<text x="6.7" y="4" size="0.6096" layer="27">&gt;VALUE</text>
</package>
<package name="SOT23-3">
<description>&lt;b&gt;SOT23-3&lt;/b&gt;

&lt;p&gt;Pads: 0.6 x 1.1 mm&lt;br&gt;
Pitch: 0.95mm&lt;br&gt;
Center-center spacing: 2.6mm&lt;/p&gt;

&lt;p&gt;Documented dims: 3.0 x 1.4 mm&lt;br&gt;
Documented leads: 0.5 x 0.6 mm&lt;/p&gt;

&lt;p&gt;JEDEC: TO-236AA/AB (identical except for height)&lt;br&gt;
EIA: SC-59&lt;/p&gt;

&lt;p&gt;Warning: This footprint is not directly compatible with footprints specified by IPC 7351B.&lt;/p&gt;</description>
<circle x="-0.3" y="0.95" radius="0.1" width="0" layer="21"/>
<smd name="1" x="-1.3" y="0.95" dx="0.6" dy="1.1" layer="1" rot="R270"/>
<smd name="2" x="-1.3" y="-0.95" dx="0.6" dy="1.1" layer="1" rot="R270"/>
<smd name="3" x="1.3" y="0" dx="0.6" dy="1.1" layer="1" rot="R270"/>
<text x="-0.697" y="-2.472" size="0.6096" layer="27" ratio="10">&gt;VALUE</text>
<text x="-0.697" y="1.902" size="0.8128" layer="25" ratio="10">&gt;NAME</text>
<rectangle x1="-1.25" y1="0.65" x2="-0.75" y2="1.25" layer="51" rot="R270"/>
<rectangle x1="-1.25" y1="-1.25" x2="-0.75" y2="-0.65" layer="51" rot="R270"/>
<rectangle x1="0.75" y1="-0.3" x2="1.25" y2="0.3" layer="51" rot="R270"/>
<wire x1="0.9" y1="-1.7" x2="-0.9" y2="-1.7" width="0.127" layer="21"/>
<wire x1="-0.9" y1="1.7" x2="0.9" y2="1.7" width="0.127" layer="21"/>
<wire x1="0.7" y1="1.5" x2="0.7" y2="-1.5" width="0.127" layer="51"/>
<wire x1="0.7" y1="-1.5" x2="-0.7" y2="-1.5" width="0.127" layer="51"/>
<wire x1="-0.7" y1="-1.5" x2="-0.7" y2="1.5" width="0.127" layer="51"/>
<wire x1="-0.7" y1="1.5" x2="0.7" y2="1.5" width="0.127" layer="51"/>
</package>
<package name="1206">
<description>&lt;b&gt;1206 (3216 Metric)&lt;/b&gt;

&lt;p&gt;Pads: 1.4 x 1.8mm&lt;br&gt;
Center-center spacing: 3.4mm&lt;br&gt;
Inner edge spacing: 2mm&lt;br&gt;
Outer edge spacing: 4.8mm&lt;/p&gt;

&lt;p&gt;Documented dims: 3.2 x 1.6 mm (0.13 x 0.06")&lt;/p&gt;

&lt;p&gt;http://www.panasonic.com/industrial/components/pdf/AOA0000CE1.pdf&lt;/p&gt;</description>
<smd name="2" x="1.7" y="0" dx="1.4" dy="1.8" layer="1"/>
<smd name="1" x="-1.7" y="0" dx="1.4" dy="1.8" layer="1"/>
<rectangle x1="-1.6" y1="-0.8" x2="1.6" y2="0.8" layer="51"/>
<wire x1="-1.8" y1="1.1" x2="1.8" y2="1.1" width="0.127" layer="21"/>
<wire x1="1.8" y1="-1.1" x2="-1.8" y2="-1.1" width="0.127" layer="21"/>
<text x="-1.8" y="1.3" size="0.8128" layer="25">&gt;NAME</text>
<text x="-1.8" y="-1.9" size="0.6096" layer="27">&gt;VALUE</text>
</package>
<package name="HEADER_100MIL_1ROW_2">
<description>&lt;b&gt;0.1" header single-row x2&lt;/b&gt;&lt;br&gt;
Fits standard 0.025" square pins

&lt;p&gt;Drill dia: 0.05"&lt;br&gt;
Pad dia: 0.075"&lt;br&gt;
Rows: 1&lt;br&gt;
Positions: 2&lt;/p&gt;</description>
<pad name="1" x="-1.27" y="0" drill="1.27" diameter="1.905" shape="square"/>
<pad name="2" x="1.27" y="0" drill="1.27" diameter="1.905"/>
<text x="-2.54" y="2.54" size="0.8128" layer="25">&gt;NAME</text>
<text x="-2.54" y="-2.54" size="0.6096" layer="27">&gt;VALUE</text>
<wire x1="0" y1="0.762" x2="-0.508" y2="1.27" width="0.127" layer="51"/>
<wire x1="-0.508" y1="1.27" x2="-2.032" y2="1.27" width="0.127" layer="51"/>
<wire x1="-2.032" y1="1.27" x2="-2.54" y2="0.762" width="0.127" layer="51"/>
<wire x1="-2.54" y1="0.762" x2="-2.54" y2="-0.762" width="0.127" layer="51"/>
<wire x1="-2.54" y1="-0.762" x2="-2.032" y2="-1.27" width="0.127" layer="51"/>
<wire x1="-2.032" y1="-1.27" x2="-0.508" y2="-1.27" width="0.127" layer="51"/>
<wire x1="-0.508" y1="-1.27" x2="0" y2="-0.762" width="0.127" layer="51"/>
<wire x1="0" y1="-0.762" x2="0" y2="0.762" width="0.127" layer="51"/>
<wire x1="2.54" y1="0.762" x2="2.032" y2="1.27" width="0.127" layer="51"/>
<wire x1="2.032" y1="1.27" x2="0.508" y2="1.27" width="0.127" layer="51"/>
<wire x1="0.508" y1="1.27" x2="0" y2="0.762" width="0.127" layer="51"/>
<wire x1="0" y1="-0.762" x2="0.508" y2="-1.27" width="0.127" layer="51"/>
<wire x1="0.508" y1="-1.27" x2="2.032" y2="-1.27" width="0.127" layer="51"/>
<wire x1="2.032" y1="-1.27" x2="2.54" y2="-0.762" width="0.127" layer="51"/>
<wire x1="2.54" y1="-0.762" x2="2.54" y2="0.762" width="0.127" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="C">
<pin name="1" x="-2.54" y="0" visible="off" length="point" direction="pas"/>
<pin name="2" x="2.54" y="0" visible="off" length="point" direction="pas" rot="R180"/>
<wire x1="-0.381" y1="0" x2="-2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="0.381" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<text x="-2.54" y="2.54" size="1.778" layer="95">&gt;NAME</text>
<text x="-2.54" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<wire x1="-0.381" y1="1.27" x2="-0.381" y2="0" width="0.2032" layer="94"/>
<wire x1="-0.381" y1="0" x2="-0.381" y2="-1.27" width="0.2032" layer="94"/>
<wire x1="0.381" y1="1.27" x2="0.381" y2="0" width="0.2032" layer="94"/>
<wire x1="0.381" y1="0" x2="0.381" y2="-1.27" width="0.2032" layer="94"/>
</symbol>
<symbol name="PWR_3V3">
<pin name="3V3" x="0" y="0" visible="off" length="short" direction="sup" rot="R90"/>
<wire x1="1.27" y1="2.54" x2="-1.27" y2="2.54" width="0.254" layer="94"/>
<text x="0" y="3.048" size="1.27" layer="95" align="bottom-center">3V3</text>
</symbol>
<symbol name="PWR_DGND">
<pin name="GND" x="0" y="0" visible="off" length="point" direction="sup" rot="R270"/>
<wire x1="-1.27" y1="0" x2="1.27" y2="0" width="0.1524" layer="94"/>
<wire x1="1.27" y1="0" x2="0" y2="-1.27" width="0.1524" layer="94"/>
<wire x1="0" y1="-1.27" x2="-1.27" y2="0" width="0.1524" layer="94"/>
</symbol>
<symbol name="IC_TLV1117LV33">
<pin name="IN" x="-12.7" y="2.54" length="middle" direction="pwr"/>
<pin name="GND" x="0" y="-10.16" length="middle" direction="pwr" rot="R90"/>
<pin name="OUT" x="12.7" y="2.54" length="middle" direction="pwr" rot="R180"/>
<wire x1="-7.62" y1="-5.08" x2="-7.62" y2="5.08" width="0.254" layer="94"/>
<wire x1="-7.62" y1="5.08" x2="7.62" y2="5.08" width="0.254" layer="94"/>
<wire x1="7.62" y1="5.08" x2="7.62" y2="-5.08" width="0.254" layer="94"/>
<wire x1="7.62" y1="-5.08" x2="-7.62" y2="-5.08" width="0.254" layer="94"/>
<text x="-7.62" y="7.62" size="1.778" layer="95">&gt;NAME</text>
<text x="2.54" y="7.62" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
<symbol name="PWR_5V">
<pin name="5V" x="0" y="0" visible="off" length="short" direction="sup" rot="R90"/>
<wire x1="1.27" y1="2.54" x2="-1.27" y2="2.54" width="0.254" layer="94"/>
<text x="0" y="3.048" size="1.27" layer="95" align="bottom-center">5V</text>
</symbol>
<symbol name="USB_B">
<pin name="VBUS" x="10.16" y="5.08" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="D-" x="10.16" y="-5.08" visible="pin" length="middle" rot="R180"/>
<pin name="D+" x="10.16" y="-2.54" visible="pin" length="middle" rot="R180"/>
<pin name="GND" x="10.16" y="2.54" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="SHLD" x="5.08" y="0" visible="pin" length="point" direction="pwr" rot="R180"/>
<text x="-5.08" y="10.16" size="1.778" layer="95">&gt;NAME</text>
<text x="0" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<wire x1="-5.08" y1="7.62" x2="5.08" y2="7.62" width="0.254" layer="94"/>
<wire x1="5.08" y1="7.62" x2="5.08" y2="-7.62" width="0.254" layer="94"/>
<wire x1="5.08" y1="-7.62" x2="-5.08" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-7.62" x2="-5.08" y2="7.62" width="0.254" layer="94"/>
</symbol>
<symbol name="TVS_DUAL_COMMON_ANODE">
<wire x1="2.032" y1="3.302" x2="3.048" y2="3.302" width="0.127" layer="94"/>
<pin name="A" x="0" y="-2.54" visible="off" length="point" direction="pas" rot="R180"/>
<pin name="C1" x="2.54" y="5.08" visible="off" length="point" direction="pas"/>
<polygon width="0.127" layer="94">
<vertex x="2.54" y="3.302"/>
<vertex x="1.778" y="1.778"/>
<vertex x="3.302" y="1.778"/>
</polygon>
<wire x1="2.54" y1="5.08" x2="2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="-3.048" y1="3.302" x2="-2.032" y2="3.302" width="0.127" layer="94"/>
<polygon width="0.127" layer="94">
<vertex x="-2.54" y="3.302"/>
<vertex x="-3.302" y="1.778"/>
<vertex x="-1.778" y="1.778"/>
</polygon>
<wire x1="-2.54" y1="5.08" x2="-2.54" y2="0" width="0.1524" layer="94"/>
<pin name="C2" x="-2.54" y="5.08" visible="off" length="point" direction="pas"/>
<wire x1="2.54" y1="0" x2="0" y2="0" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="0" x2="0" y2="0" width="0.1524" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="-3.048" y1="3.302" x2="-3.302" y2="3.556" width="0.127" layer="94"/>
<wire x1="-2.032" y1="3.302" x2="-1.778" y2="3.048" width="0.127" layer="94"/>
<wire x1="2.032" y1="3.302" x2="1.778" y2="3.556" width="0.127" layer="94"/>
<wire x1="3.048" y1="3.302" x2="3.302" y2="3.048" width="0.127" layer="94"/>
<text x="5.08" y="2.54" size="1.778" layer="95">&gt;NAME</text>
<text x="5.08" y="0" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
<symbol name="PTC_THERMISTOR">
<pin name="1" x="-2.54" y="0" visible="off" length="point" direction="pas"/>
<pin name="2" x="2.54" y="0" visible="off" length="point" direction="pas" rot="R180"/>
<text x="-2.54" y="2.54" size="1.778" layer="95">&gt;NAME</text>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<wire x1="-1.27" y1="0" x2="-2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="2.54" y1="0" x2="1.27" y2="0" width="0.1524" layer="94"/>
<wire x1="-0.9525" y1="-0.9525" x2="-1.5875" y2="-0.9525" width="0.127" layer="94"/>
<wire x1="-0.9525" y1="-0.9525" x2="0.9525" y2="0.9525" width="0.127" layer="94"/>
<wire x1="0.9525" y1="0.9525" x2="1.5875" y2="0.9525" width="0.127" layer="94"/>
<wire x1="1.27" y1="0" x2="1.27" y2="0.3175" width="0.1524" layer="94"/>
<wire x1="1.27" y1="0.3175" x2="-1.27" y2="0.3175" width="0.1524" layer="94"/>
<wire x1="-1.27" y1="0.3175" x2="-1.27" y2="-0.3175" width="0.1524" layer="94"/>
<wire x1="-1.27" y1="-0.3175" x2="1.27" y2="-0.3175" width="0.1524" layer="94"/>
<wire x1="1.27" y1="-0.3175" x2="1.27" y2="0" width="0.1524" layer="94"/>
</symbol>
<symbol name="L">
<pin name="1" x="-2.54" y="0" visible="off" length="point" direction="pas"/>
<pin name="2" x="2.54" y="0" visible="off" length="point" direction="pas"/>
<wire x1="0" y1="0" x2="0.79375" y2="0" width="0.1524" layer="94" curve="-180"/>
<wire x1="0.79375" y1="0" x2="1.5875" y2="0" width="0.1524" layer="94" curve="-180"/>
<wire x1="-0.79375" y1="0" x2="0" y2="0" width="0.1524" layer="94" curve="-180"/>
<wire x1="-1.5875" y1="0" x2="-0.79375" y2="0" width="0.1524" layer="94" curve="-180"/>
<wire x1="-1.5875" y1="0" x2="-2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="1.5875" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<text x="-2.54" y="2.54" size="1.778" layer="95">&gt;NAME</text>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
<symbol name="HEADER_2">
<pin name="1" x="7.62" y="2.54" length="middle" direction="pas" rot="R180"/>
<pin name="2" x="7.62" y="0" length="middle" direction="pas" rot="R180"/>
<wire x1="2.54" y1="5.08" x2="2.54" y2="-2.54" width="0.254" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="-2.54" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-2.54" x2="-2.54" y2="5.08" width="0.254" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="2.54" y2="5.08" width="0.254" layer="94"/>
<text x="-2.54" y="7.62" size="1.778" layer="95">&gt;NAME</text>
<text x="-2.54" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="C" prefix="C" uservalue="yes">
<description>&lt;b&gt;Capacitor&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="C" x="0" y="0"/>
</gates>
<devices>
<device name="0603" package="0603">
<connects>
<connect gate="G$1" pin="1" pad="2"/>
<connect gate="G$1" pin="2" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="0805" package="0805">
<connects>
<connect gate="G$1" pin="1" pad="2"/>
<connect gate="G$1" pin="2" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="3V3">
<gates>
<gate name="G$1" symbol="PWR_3V3" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="DGND">
<gates>
<gate name="G$1" symbol="PWR_DGND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="TLV1117LV33" prefix="U" uservalue="yes">
<description>&lt;b&gt;TLV1117LV33&lt;/b&gt; 3.3V LDO regulator

&lt;p&gt;Manufacturer: TI&lt;/p&gt;

&lt;p&gt;Output: 3.3V @ 1A&lt;br&gt;
Dropout: 455mV @ 1A&lt;br&gt;
Input: Up to 5.5V&lt;br&gt;
Max quiescent current: 100uA&lt;/p&gt;

&lt;p&gt;Stable with ceramic output caps&lt;br&gt;
Stable with 0mA load current&lt;/p&gt;</description>
<gates>
<gate name="G$1" symbol="IC_TLV1117LV33" x="0" y="0"/>
</gates>
<devices>
<device name="DCY" package="SOT223-3">
<connects>
<connect gate="G$1" pin="GND" pad="1"/>
<connect gate="G$1" pin="IN" pad="3"/>
<connect gate="G$1" pin="OUT" pad="2 4" route="any"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="5V">
<gates>
<gate name="G$1" symbol="PWR_5V" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="USB-B" prefix="J" uservalue="yes">
<description>&lt;b&gt;USB B jack&lt;/b&gt;

&lt;p&gt;Manufacturer: On-Shore Technologies&lt;br&gt;
Part number: USB-B1HSB6&lt;/p&gt;

&lt;p&gt;Manufacturer: Samtec&lt;br&gt;
Part number: USB-B-S-X-X-TH-X-XX&lt;/p&gt;</description>
<gates>
<gate name="G$1" symbol="USB_B" x="0" y="0"/>
</gates>
<devices>
<device name="-ONSHORE" package="USB-B-ONSHORE">
<connects>
<connect gate="G$1" pin="D+" pad="3"/>
<connect gate="G$1" pin="D-" pad="2"/>
<connect gate="G$1" pin="GND" pad="4"/>
<connect gate="G$1" pin="SHLD" pad="5 6" route="any"/>
<connect gate="G$1" pin="VBUS" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-SAMTEC" package="USB-B-SAMTEC">
<connects>
<connect gate="G$1" pin="D+" pad="3"/>
<connect gate="G$1" pin="D-" pad="2"/>
<connect gate="G$1" pin="GND" pad="4"/>
<connect gate="G$1" pin="SHLD" pad="5 6" route="any"/>
<connect gate="G$1" pin="VBUS" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="GSOT05C" prefix="TVS" uservalue="yes">
<description>&lt;b&gt;GSOTxxC&lt;/b&gt; dual TVS diodes (common anode)

&lt;p&gt;Manufacturer: Vishay&lt;/p&gt;

&lt;p&gt;Peak pulse current: 30A each&lt;br&gt;
Reverse standoff voltage: 3.3V, 4V, 5V, 8V, 12V, 15V, 24V, 36V&lt;/p&gt;</description>
<gates>
<gate name="G$1" symbol="TVS_DUAL_COMMON_ANODE" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SOT23-3">
<connects>
<connect gate="G$1" pin="A" pad="3"/>
<connect gate="G$1" pin="C1" pad="1"/>
<connect gate="G$1" pin="C2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="POLYFUSE" prefix="F" uservalue="yes">
<description>&lt;b&gt;Polyfuse&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="PTC_THERMISTOR" x="0" y="0"/>
</gates>
<devices>
<device name="-1206" package="1206">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="FERRITE_BEAD" prefix="L" uservalue="yes">
<description>&lt;b&gt;Ferrite bead&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="L" x="0" y="0"/>
</gates>
<devices>
<device name="-0603" package="0603">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="HEADER_100MIL_1ROW_2" prefix="J" uservalue="yes">
<description>0.1" header single-row x2</description>
<gates>
<gate name="G$1" symbol="HEADER_2" x="0" y="0"/>
</gates>
<devices>
<device name="" package="HEADER_100MIL_1ROW_2">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U1" library="sjunglib" deviceset="TLV1117LV33" device="DCY" value="TLV1117LV33"/>
<part name="U$36" library="sjunglib" deviceset="DGND" device=""/>
<part name="C3" library="sjunglib" deviceset="C" device="0603" value="1uF"/>
<part name="C4" library="sjunglib" deviceset="C" device="0805" value="10uF"/>
<part name="U$37" library="sjunglib" deviceset="3V3" device=""/>
<part name="C2" library="sjunglib" deviceset="C" device="0603" value="1uF"/>
<part name="C1" library="sjunglib" deviceset="C" device="0805" value="10uF"/>
<part name="U$38" library="sjunglib" deviceset="5V" device=""/>
<part name="J1" library="sjunglib" deviceset="USB-B" device="-SAMTEC" value="USB-B-S-F-B-TH "/>
<part name="D1" library="sjunglib" deviceset="GSOT05C" device="" value="GSOT05C"/>
<part name="F1" library="sjunglib" deviceset="POLYFUSE" device="-1206" value="0ZCJ0110FF2E"/>
<part name="L1" library="sjunglib" deviceset="FERRITE_BEAD" device="-0603" value="BLM18SG33"/>
<part name="J2" library="sjunglib" deviceset="HEADER_100MIL_1ROW_2" device=""/>
<part name="J3" library="sjunglib" deviceset="HEADER_100MIL_1ROW_2" device=""/>
<part name="U$1" library="sjunglib" deviceset="3V3" device=""/>
<part name="U$2" library="sjunglib" deviceset="5V" device=""/>
<part name="U$3" library="sjunglib" deviceset="DGND" device=""/>
<part name="U$4" library="sjunglib" deviceset="DGND" device=""/>
<part name="J4" library="sjunglib" deviceset="HEADER_100MIL_1ROW_2" device=""/>
<part name="U$5" library="sjunglib" deviceset="DGND" device=""/>
</parts>
<sheets>
<sheet>
<plain>
<wire x1="116.84" y1="50.8" x2="-5.08" y2="50.8" width="0.1524" layer="97"/>
<wire x1="-5.08" y1="50.8" x2="-5.08" y2="88.9" width="0.1524" layer="97"/>
<wire x1="-5.08" y1="88.9" x2="116.84" y2="88.9" width="0.1524" layer="97"/>
<wire x1="116.84" y1="88.9" x2="116.84" y2="50.8" width="0.1524" layer="97"/>
<text x="-2.54" y="83.82" size="2.54" layer="97">POWER SUPPLY BLOCK</text>
<text x="27.94" y="78.74" size="1.778" layer="97" align="top-center">1.1A polyfuse</text>
<text x="43.18" y="55.88" size="1.778" layer="97" align="bottom-center">TVS (5V standoff)</text>
<text x="55.88" y="78.74" size="1.778" layer="97" align="top-center">ferrite bead</text>
<text x="88.9" y="81.28" size="1.778" layer="97" align="top-center">3.3V @ 1A regulator</text>
<text x="5.08" y="78.74" size="1.778" layer="97" align="top-center">USB B input</text>
<text x="25.4" y="33.02" size="1.778" layer="97" align="top-center">5V header</text>
<text x="45.72" y="33.02" size="1.778" layer="97" align="top-center">3V3 header</text>
<text x="68.58" y="33.02" size="1.778" layer="97" align="top-center">Raw USB header</text>
</plain>
<instances>
<instance part="U1" gate="G$1" x="88.9" y="68.58" smashed="yes">
<attribute name="NAME" x="88.9" y="78.74" size="1.778" layer="95" align="top-center"/>
<attribute name="VALUE" x="88.9" y="76.2" size="1.778" layer="96" align="top-center"/>
</instance>
<instance part="U$36" gate="G$1" x="88.9" y="55.88"/>
<instance part="C3" gate="G$1" x="101.6" y="63.5" smashed="yes" rot="R90">
<attribute name="NAME" x="97.79" y="60.96" size="1.778" layer="95" rot="R90" align="top-left"/>
<attribute name="VALUE" x="105.41" y="60.96" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="C4" gate="G$1" x="111.76" y="63.5" smashed="yes" rot="R90">
<attribute name="NAME" x="107.95" y="60.96" size="1.778" layer="95" rot="R90" align="top-left"/>
<attribute name="VALUE" x="115.57" y="60.96" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="U$37" gate="G$1" x="111.76" y="71.12"/>
<instance part="C2" gate="G$1" x="76.2" y="63.5" smashed="yes" rot="R90">
<attribute name="NAME" x="72.39" y="60.96" size="1.778" layer="95" rot="R90" align="top-left"/>
<attribute name="VALUE" x="80.01" y="60.96" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="C1" gate="G$1" x="66.04" y="63.5" smashed="yes" rot="R90">
<attribute name="NAME" x="62.23" y="60.96" size="1.778" layer="95" rot="R90" align="top-left"/>
<attribute name="VALUE" x="69.85" y="60.96" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="U$38" gate="G$1" x="66.04" y="71.12"/>
<instance part="J1" gate="G$1" x="5.08" y="66.04" smashed="yes">
<attribute name="NAME" x="5.08" y="76.2" size="1.778" layer="95" align="top-center"/>
<attribute name="VALUE" x="-2.54" y="66.04" size="1.778" layer="96" rot="R90" align="top-center"/>
</instance>
<instance part="D1" gate="G$1" x="43.18" y="66.04" smashed="yes">
<attribute name="NAME" x="43.18" y="76.2" size="1.778" layer="95" align="top-center"/>
<attribute name="VALUE" x="43.18" y="73.66" size="1.778" layer="96" rot="R180" align="bottom-center"/>
</instance>
<instance part="F1" gate="G$1" x="27.94" y="71.12" smashed="yes">
<attribute name="NAME" x="27.94" y="73.66" size="1.778" layer="95" align="top-center"/>
<attribute name="VALUE" x="27.94" y="68.58" size="1.778" layer="96" align="bottom-center"/>
</instance>
<instance part="L1" gate="G$1" x="55.88" y="71.12" smashed="yes">
<attribute name="NAME" x="55.88" y="73.66" size="1.778" layer="95" align="top-center"/>
<attribute name="VALUE" x="55.88" y="68.58" size="1.778" layer="96" align="bottom-center"/>
</instance>
<instance part="J2" gate="G$1" x="22.86" y="38.1"/>
<instance part="J3" gate="G$1" x="43.18" y="38.1"/>
<instance part="U$1" gate="G$1" x="50.8" y="40.64"/>
<instance part="U$2" gate="G$1" x="30.48" y="40.64"/>
<instance part="U$3" gate="G$1" x="30.48" y="35.56"/>
<instance part="U$4" gate="G$1" x="50.8" y="35.56"/>
<instance part="J4" gate="G$1" x="66.04" y="38.1"/>
<instance part="U$5" gate="G$1" x="73.66" y="35.56"/>
</instances>
<busses>
</busses>
<nets>
<net name="3V3" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="OUT"/>
<pinref part="C3" gate="G$1" pin="2"/>
<wire x1="101.6" y1="71.12" x2="101.6" y2="66.04" width="0.1524" layer="91"/>
<pinref part="C4" gate="G$1" pin="2"/>
<wire x1="101.6" y1="71.12" x2="111.76" y2="71.12" width="0.1524" layer="91"/>
<wire x1="111.76" y1="71.12" x2="111.76" y2="66.04" width="0.1524" layer="91"/>
<junction x="101.6" y="71.12"/>
<pinref part="U$37" gate="G$1" pin="3V3"/>
<junction x="111.76" y="71.12"/>
</segment>
<segment>
<pinref part="J3" gate="G$1" pin="1"/>
<pinref part="U$1" gate="G$1" pin="3V3"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="U$36" gate="G$1" pin="GND"/>
<pinref part="U1" gate="G$1" pin="GND"/>
<wire x1="88.9" y1="55.88" x2="88.9" y2="58.42" width="0.1524" layer="91"/>
<pinref part="C3" gate="G$1" pin="1"/>
<wire x1="101.6" y1="60.96" x2="101.6" y2="58.42" width="0.1524" layer="91"/>
<wire x1="101.6" y1="58.42" x2="88.9" y2="58.42" width="0.1524" layer="91"/>
<junction x="88.9" y="58.42"/>
<pinref part="C4" gate="G$1" pin="1"/>
<wire x1="111.76" y1="60.96" x2="111.76" y2="58.42" width="0.1524" layer="91"/>
<wire x1="111.76" y1="58.42" x2="101.6" y2="58.42" width="0.1524" layer="91"/>
<junction x="101.6" y="58.42"/>
<pinref part="C1" gate="G$1" pin="1"/>
<wire x1="88.9" y1="58.42" x2="76.2" y2="58.42" width="0.1524" layer="91"/>
<wire x1="76.2" y1="58.42" x2="66.04" y2="58.42" width="0.1524" layer="91"/>
<wire x1="66.04" y1="58.42" x2="66.04" y2="60.96" width="0.1524" layer="91"/>
<pinref part="C2" gate="G$1" pin="1"/>
<wire x1="76.2" y1="60.96" x2="76.2" y2="58.42" width="0.1524" layer="91"/>
<junction x="76.2" y="58.42"/>
<wire x1="17.78" y1="66.04" x2="17.78" y2="58.42" width="0.1524" layer="91"/>
<wire x1="17.78" y1="58.42" x2="43.18" y2="58.42" width="0.1524" layer="91"/>
<junction x="66.04" y="58.42"/>
<pinref part="D1" gate="G$1" pin="A"/>
<wire x1="43.18" y1="58.42" x2="66.04" y2="58.42" width="0.1524" layer="91"/>
<wire x1="43.18" y1="63.5" x2="43.18" y2="58.42" width="0.1524" layer="91"/>
<junction x="43.18" y="58.42"/>
<pinref part="J1" gate="G$1" pin="SHLD"/>
<wire x1="17.78" y1="66.04" x2="15.24" y2="66.04" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$1" pin="GND"/>
<wire x1="15.24" y1="66.04" x2="10.16" y2="66.04" width="0.1524" layer="91"/>
<wire x1="15.24" y1="68.58" x2="15.24" y2="66.04" width="0.1524" layer="91"/>
<junction x="15.24" y="66.04"/>
</segment>
<segment>
<pinref part="J2" gate="G$1" pin="2"/>
<pinref part="U$3" gate="G$1" pin="GND"/>
<wire x1="30.48" y1="38.1" x2="30.48" y2="35.56" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="J3" gate="G$1" pin="2"/>
<pinref part="U$4" gate="G$1" pin="GND"/>
<wire x1="50.8" y1="38.1" x2="50.8" y2="35.56" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="J4" gate="G$1" pin="2"/>
<pinref part="U$5" gate="G$1" pin="GND"/>
<wire x1="73.66" y1="38.1" x2="73.66" y2="35.56" width="0.1524" layer="91"/>
</segment>
</net>
<net name="5V" class="0">
<segment>
<wire x1="66.04" y1="66.04" x2="66.04" y2="71.12" width="0.1524" layer="91"/>
<pinref part="U1" gate="G$1" pin="IN"/>
<wire x1="66.04" y1="71.12" x2="76.2" y2="71.12" width="0.1524" layer="91"/>
<pinref part="C2" gate="G$1" pin="2"/>
<wire x1="76.2" y1="66.04" x2="76.2" y2="71.12" width="0.1524" layer="91"/>
<junction x="76.2" y="71.12"/>
<pinref part="U$38" gate="G$1" pin="5V"/>
<junction x="66.04" y="71.12"/>
<pinref part="L1" gate="G$1" pin="2"/>
<wire x1="58.42" y1="71.12" x2="66.04" y2="71.12" width="0.1524" layer="91"/>
<pinref part="C1" gate="G$1" pin="2"/>
</segment>
<segment>
<pinref part="J2" gate="G$1" pin="1"/>
<pinref part="U$2" gate="G$1" pin="5V"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="J1" gate="G$1" pin="D+"/>
<pinref part="J1" gate="G$1" pin="D-"/>
<wire x1="15.24" y1="63.5" x2="15.24" y2="60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="F1" gate="G$1" pin="2"/>
<pinref part="D1" gate="G$1" pin="C1"/>
<pinref part="D1" gate="G$1" pin="C2"/>
<wire x1="40.64" y1="71.12" x2="45.72" y2="71.12" width="0.1524" layer="91"/>
<junction x="40.64" y="71.12"/>
<wire x1="40.64" y1="71.12" x2="30.48" y2="71.12" width="0.1524" layer="91"/>
<pinref part="L1" gate="G$1" pin="1"/>
<wire x1="53.34" y1="71.12" x2="45.72" y2="71.12" width="0.1524" layer="91"/>
<junction x="45.72" y="71.12"/>
</segment>
</net>
<net name="VBUS" class="0">
<segment>
<pinref part="F1" gate="G$1" pin="1"/>
<pinref part="J1" gate="G$1" pin="VBUS"/>
<wire x1="25.4" y1="71.12" x2="15.24" y2="71.12" width="0.1524" layer="91"/>
<label x="12.7" y="71.12" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="J4" gate="G$1" pin="1"/>
<wire x1="73.66" y1="40.64" x2="78.74" y2="40.64" width="0.1524" layer="91"/>
<label x="73.66" y="40.64" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
