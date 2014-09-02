MoisPie
=======

To Insall MoisPieTeensy.ino 
===================================
http://arduino.cc/en/Main/Software

latest teensy Driver
https://www.pjrc.com/teensy/td_download.html   
open up MoisPieTeensy in the ardunio ide

select the teensy3.1 board from the ardunio tools menu.

use MoisPieTeensy.ino 

how to use
===========

you can send serial commands to the teensy to control the algorithm

all the control messages are the same lenght, but not all the ints are used.

for example the colour change uses all three of the ints after the first , 

here are some examples...




 "@C1,255,255,255,endofline"
 this would change the secound colour to white..  
the message is broken down like this

@ = incoming message 

C = change colour

1 = the colour to change

, = end the last message

255 = red to 255

,  = end the last message

255 = blue to 255

,  = end the last message

255 = green to 255

,  = end the last message

endofline = the comannd is finnished


there are other commands you can send too
this is a controls how fast the leds go back to black 
fade this only use one of the ints after the first ,

@F1,20,255,255,endofline


direction of the colour is controlled by a bool after the first ,
 
@D1,1,255,255,endofline 
 
 offset only use the first int after the ,
 
 offset offset the led start postion 

@D1,32,255,255,endofline 

here the  32 mean it will start on the 32 led on the strip

interval is the speed of which the led moves to the next led on the strip
and only use the first int after the ,


@I1,32,255,255,endofline 

you can sel a loop of leds 
so instead of the pulse started at 0 led and move to 260th led
you can set a loop so it start at 30th - and end at the 60th 
this use the first two ints after the first ,

@L1,30,60,255,endofline 

active turns the pulse on or off
this is a bool after the first ,

@A1,1,255,255,endofline 


the numuber after the letter is the colour to change max 8
so..

@C8,0,0,255,endofline

  would set the 8 colour to blue
  
  
  
  the serial speed must be 9600
  
  
  
  
==========================================  
  Serial to Teensy of Mac
==========================================

this is a way of testing the serial commands 

To install Serial to Teensy of Mac

	there is an compiled app in serial To Teensy of MAC/bin
	serialExampleDebug.app
	
to compiled the code you need to 
install xcode
download openframeworks, new version should work, tested with v_0_8_0
http://openframeworks.cc/download/

then put the Serial To Teensy of Mac in to 
of_v0.8.3/apps/myApps

then open the serialExample.xcodeproj

and it should compile 




==========================================  
   Visualisation
==========================================

a way of offline Visualising the way the code works..


	there is an compiled app in serial To Visualisation/bin
	example-ButtonsDebug.app
	
install xcode

download openframeworks,
new version should work, tested with v_0_8_0

http://openframeworks.cc/download/

and download the addon ofxUI and ofxTweener

https://github.com/rezaali/ofxUI

https://github.com/hautetechnique/ofxTweener


place the folder in the addons folder of openframeworks 


then put the Visualisation folder in to 
of_v0.8.3/apps/myApps

then open the example-Buttons.vcxproj

and it should compile 

you would then have to recode it to for the teensy 



Runing video through the leds
==========================================


install
http://processing.org
here is the processing code 		
http://samy.pl/VideoDisplay/Processing/movie2serial/movie2serial.pde


the teensy code is in the ardunio ide 
Examples->OctoW2811-> videoDisplay

int the teensy code you must change this line 


const int config = WS2811_800kHz; // color config is on the PC side
to ->

const int config = WS2811_400kHz; // color config is on the PC side

as the leds are only working at 400khz






 














  
  
  
  
  




 
 
  
