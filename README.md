# Iris
Infrared fingerprinting and collections (IRIS) and other IR collection techniques

A list of equipment and links will be added shortly.

***********************Please download IRISBABY.docx to see full details of connections and equipment with pics. TIR3BUCK2A.ino is the arduino script.*************************************************************************

Please make sure to Follow the research in this area by Mike Ossmann @michaelossmann and Dominic Spill @dominicgs There doing great things.


The Team that helped me are Tim Kuester @bjt2n3904 and Craig Hefner @devttys0 
To the left is the IRIS board it is one tool that can be used to look at and evaluate signals with unknown protocols.
It is powered by a coin cell battery for over 5 days. 

	This tool in its standard format pushes all signals to a digital level.

	Analog can be read with a few modifications to the board. Analog is important to look at for other finger printing techniques not the ones for this github page.

	This page will show the basics for IR collection. The Iris board is a great tool but you can start without it. You can begin with a few dollars worth of equipment. 


*********************download IRISBABY.DOCX for full color photo examples.*****************************

There are many IR receivers that can be purchased. The key is understanding that any IR receiver with three legs has a built in circuit that attempts to push every signal to a digital level. They will have a greatly diminished range and sensitivity also.  

You can also get an Ir network extender and feed the output into the reader. This can help to increased the signal and sensitivity strength.
I’ll include an example of a circuit we use as an OP amp to increase a standard IR receiver just two legs to increase range and sensitivity and also get the analog output along with the digital. We will show more and some easier examples shortly. Please note Craig Hefner is a beast at this and his site             http://www.analogzoo.com can assist you with any questions about OP amps or many other rf and circuit designs. These circuits use a split rail system and increase the power to the receivers. We will show further techniques to increase capabilities of receiving and understanding IR signatures for unknown devices in the future.  The goal is to   get people started as soon as possible and as quickly as possible.   The techniques  can be used interchangeably. 

Yes we have have used optics to increase the range of even weak receivers. 

The example to the left shows IRIS attached to a spotting scope finger printing cellular devices. We have extended the range from 10 to 15 feet indoors to over 50 yds indoors or outdoors at night. That is for cell phones please understand the infrared lights we are targeting are very weak. Its the Proximity detectors attached to the screen.

You can see that this can be run from an Arduino Uno. Lets get to the set up. 
 Equipment needed:

Minimal
Arduino Uno
Ir Receiver (Any device that recieves IR has one in it.)
wires
Computer (maybe)

Bonus:
Logic Analyzer
Network Extender
IRIS Board Design by Craig Hefner BOM and KiCAD designs can be found here 
https://github.com/devttys0/IRis 

Lets look at the two types of set up
Arduino Uno powers as reciever and the version were the receiver receives external power.

VERSION ONE:
Arduino feed power to an Ir receiver. Please note polarity of your reciever may vary. Look up your model. Use low voltage to test. Recommended 3ish volts. Im not an engineer so I spit ball alot (sorry Tim). Note that phones show ir at different times depending on make model and version. Use a remote to test if your receiving signal or at least enough to read. In the majority of my demo’s Red is positive  Black is negative and Yellow is Signal. The red wire should be tried first in the 3 volt output of the arduino. Black at the ground  and the signal at pin 8. This set up when used with the included arduino script will allow you to start finger printing phones and other devices.

VERSION TWO:
Any system that powers the circuit out side of the Arduino Uno. This means 2 leg photo-receiver attached to OP Amp with its own power, IR network extender that is then read at the emitter side or Iris. All of these require only input in the ground of the Arduino and pin 8. 














The arduino script is attached to this page. It has two modes
The first is search mode
This mode searches for devices in the target deck.
The second is Learn mode. (Tim Kuester assisted me in developing this. Lean mode was his idea and its great.)  He assists but likes to make sure I learn so the rough areas are mine and he keeps me limping along and learning. He slowly adjust and corrects my mistakes.) I make stuff so coding is new for me.  I am also very receptive to assistance.  

How to switch from learn mode to search and Vice Versa:
Attach a wire to pin 2 and while receiving an IR signal ground pin 2 the modes will switch be quick. The numbers that begin to appear are the timing or signals. We will continue learning about these. This is the most simple way to target. It is rough but needed to learn the basics. We will get into hierarchy and other technics. You will look at the average spacing on the screen the average is 15443ish so in the script you would name the device then set the parameters. such as 15438 15449  20 this would mean once you get 20 hits of an ir signal between 15438 to 15449 the name you gave will appear in the terminal. In my hack5 video I have done an advance feature that has this not only show in terminal but trigger a IO that activates a relay to power wireless cameras. This script will be release at a later date. It needs touching up to make it able to also target advanced learn modes. Please note this is my first github page. Be patient. 

As this page grows Ill include more about Logic Analyzers. They will be a huge piece of future development. You should also begin to use your android phone (sorry apple lacks the IR filter) to look at proximitry sensors in all areas of your life. IR not only send but recievers.) For ten years its been undistirbed security wise other than TVBGONE. Lets shack it up. I’ll up dates this soon. I wanted to make sure after finding out that this would be on HAK5 any one watching could begin there IR journey. Please follow me twitter @tb69rr. My goal is to make us safer by showing the dangers in easy simple products that never got secured. IR is one of those. Please share this and any other. 
