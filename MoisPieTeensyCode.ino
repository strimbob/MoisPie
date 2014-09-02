#include <OctoWS2811.h>
#include <ctype.h>
  
int interval[9] = {0,0,0,0,0,0,0,0}; 
long previousMillis[9];      
const int ledsPerStrip = 240;
int deadVal1;
int deadVal2;
DMAMEM int displayMemory[ledsPerStrip*6];
int drawingMemory[ledsPerStrip*6];

const int config = WS2811_GRB | WS2811_400kHz;
OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config);

int width = 60;
int height = 8;
int totalNu = width*height;

int rotationStart = 0;
int rotationEnd = 8;

int redShow [ledsPerStrip*8];
int blueShow [ledsPerStrip*8];
int greenShow [ledsPerStrip*8];

int redMain[9] = {255,0,0,0,0,0,0,0};
int blueMain[9]  = {0,0,0,0,0,0,0,0};
int greenMain[9]  = {0,0,0,0,0,0,0,0};

int wX = 0;
int hY = 0;
int fade = 20;
String inString = "";  
int messageIter = 0;
int offset[9] = {0,10,20,30,40,50,60,30,30};
int offsetY[9] = {0,0,0,0,0,0,0,0,0};
int dirUpDown[9] = {0,0,0,0,0,0,0,0,0};
int jumpLed[9] =  {1,1,1,1,1,1,1,3,1};
int computedVal;
int clampedY[9] = {0,0,0,0,0,0,0,0,0};
int limitStartX[9] = {0,0,0,0,0,0,0,0,0};
int limitEndX[9] = {180,180,180,180,180,180,180,180,180};
int activeLed[9] = {1,0,0,0,0,0,0,0,0};
//___________________________________________________________
void setup() {
 

    
   Serial.begin(9600); 
   Serial.println("Glue, Octows2811 ready to start");
  leds.begin();
  leds.show(); 
  
     for (int i=0; i < leds.numPixels(); i++) { // loop through all leds 
       leds.setPixel(i, 0x000000);
   }
   leds.show();
  
}



int clampVals(int x,int totalLed,int length,int clamped = 0){
    
//    
//
//    clamped  = constrain(x, 0, totalLed);  // stay in range of phisaly leds
//   // clamped = x;
//    if (x >= totalLed) {               // if current poistion greater than totalled leds
//        clamped = x - (totalLed + length);   // start to count up from 0
//    //    cout << clamped << endl;
//        if(clamped <= length){
//            clamped = map(clamped, -length, 0, 0, length);
//        }
//    }
//    
//    
//    if(clamped <= length){
//
//            clamped = map(clamped, -length, 0, 0, length);
//
//
//    }
//    
//    return clamped = constrain(clamped, 0, totalLed-1);
    
}

//___________________________________________________________
void poistionLed(int onOff,int *ledPos, int limitStartX_,int limitEndX_,int direation,int _jumpLed,int id){
  
      if(direation){
        if(onOff){
           *ledPos -= _jumpLed;
            
        }
        
        if(*ledPos <= limitStartX_){
            *ledPos =  limitEndX_;
            Serial.print("$E");
            Serial.print(id);
            Serial.println(",eS");

            
        }   
    }
        else{
        if(onOff){
          *ledPos += _jumpLed;
         }
        
        if(*ledPos >= limitEndX_){
            *ledPos = limitStartX_;
            Serial.print("$E");
            Serial.print(id);
            Serial.println(",eE");

             
        }
        }

  
}


//___________________________________________________________
void loop() {

  getNumbersFromSerial();
  
 for(int colour = 0;colour<8;colour++){ // loop through the colours 0-8 (max 9)
    unsigned long currentMillis = millis(); // get the current time
    
  //   if(currentMillis - previousMillis[colour] > interval[colour]*100) {  // set the interval time
          if(currentMillis - previousMillis[colour] > interval[colour]) {  // set the interval time
        previousMillis[colour]  = currentMillis;    // set the previous time in realtion to the persife colour  
        
        boolean stopply = 1;
        int lenght = 1;
        poistionLed(activeLed[colour],&offset[colour],limitStartX[colour],limitEndX[colour],dirUpDown[colour],jumpLed[colour],colour);

 //        clampedY[colour] += 1;

        }


      
        //_______________
// for when we around around
  
//  if(clampedY[colour] >7){
//    
//    clampedY[colour] = 0;
//  }


//for(int x = clampedY[colour];x<clampedY[colour]+8;x++){ // loop through the strips Y    (max 8)

      //_______________
      
      
 for(int x = 0;x<8;x++){ // loop through the strips Y    (max 8) 
 
   computedVal = (offset[colour]+(x *ledsPerStrip-1));
      
      if(activeLed[colour]){
    for(int j = 0;j<jumpLed[colour];j++){
      
      if(redShow[computedVal+j] != redMain[colour]){
        redShow[computedVal+j] += redMain[colour]; // set led colour from the 1 of 9 colour
      if( redShow[computedVal+j]>254){
        redShow[computedVal+j] =  254;
      }
     }
            
       if(greenShow[computedVal+j] != greenMain[colour]){     
      greenShow[computedVal+j] += greenMain[colour]; // set led colour from the 1 of 9 colour
        if(greenShow[computedVal+j]>254){
          greenShow[computedVal+j] = 254;
        }
        
       }
  
      if(blueShow[computedVal+j] != blueMain[colour] ){  
     blueShow[computedVal+j]   += blueMain[colour];
       if(blueShow[computedVal+j]>254){  // set led colour from the 1 of 9 colour 
        blueShow[computedVal+j] = 254; 
       }
 
      }
  //  leds.setPixel(computedVal,redShow[offset[colour]],greenShow[offset[colour]],blueShow[offset[colour]]);
     }
    // set the to matrix 
    }
 }
}
 
 
 

  for (int i=0; i < (ledsPerStrip*8); i++) { // loop thourgh all the leds // and fade them to black

    if(redShow[i] > fade){  // fade the red leds, to do make fade in to the vector
    redShow[i] -=  fade;   // fade the leds by fade by amaont 
    }else{
    redShow[i] = 0;    // if lower than fade value, set to 0
    }  
    if(blueShow[i] >  fade){ // fade the red leds, to do make fade in to the vector
    blueShow[i] -=  fade; // fade the leds by fade by amaont 
    }else{
    blueShow[i] = 0;  // if lower than fade value, set to 0
    }     
    if(greenShow[i] >  fade){ // fade the red leds, to do make fade in to the vector
       greenShow[i] -=  fade; // fade the leds by fade by amaont 
      }else{
     greenShow[i] = 0;  // if lower than fade value, set to 0
     }

     leds.setPixel(i,redShow[i],blueShow[i] , greenShow[i]); // set the faded leds
 }
 
 
 for(int yx = 0;yx<8;yx++){// draw the white
  int  tempy = yx * 240;
 for(int xa = 0;xa<60-25;xa ++){
  leds.setPixel((xa+25)+tempy,255,255 ,255); // set the faded leds    
 }
 }
 
 // ----- code for rose only on one teensy // -------------------------
 // code of rose start

int  tempy = 6 * 240;
 for(int xa = 0;xa<60;xa ++){
       leds.setPixel((xa)+tempy,50,50  ,50); // set the faded leds 


if((xa > 19)&&(xa < 40)){
  leds.setPixel((xa)+tempy,0,50  ,37); // set the faded leds 

 }
 }
 
 
 
  for(int xa = 60;xa<120;xa ++){
       leds.setPixel((xa)+tempy,50,50  ,50); // set the faded leds 

if(xa < 9+60){
   leds.setPixel((xa)+tempy,0,50  ,37); // set the faded leds 
}

if((xa > 47+60)&&(xa < 60+60)){
  leds.setPixel((xa)+tempy,0,50  ,37); // set the faded leds 

 }
 }
 
   // --- code for rose end 
  // ----- code for rose only on one teensy // -------------------------

 
    leds.show(); // draw the leds 
    
    

}



//___________________________________________________________


boolean getNumbersFromSerial() { 

  if(Serial.available() > 10){
    

  while (Serial.available() < 11) { ;} 

    if (Serial.read() == '@') {
        char byteRead =  Serial.read();
        char pulseId = Serial.read();
        String pulseIdTemp =  pulseId;
        int pulseIdInt = pulseIdTemp.toInt();
      // Serial.print(Serial.read());
      
      if( byteRead  == 'C'){ // ColourValue
         readValue(pulseId,&redMain[pulseIdInt],&greenMain[pulseIdInt],&blueMain[pulseIdInt]);       
          }
          
            if( byteRead  == 'F'){ // fadeValue
         readValue(pulseId,&fade,&deadVal1,&deadVal2);       
          }
          
        if( byteRead  == 'D'){ //direstion value
        readValue(pulseId,&dirUpDown[pulseIdInt],&deadVal1,&deadVal2); 
 
       }
       
        if( byteRead  == 'O'){ // offect X (max 260)
        readValue(pulseId,&offset[pulseIdInt],&deadVal1,&deadVal2); 
        }
      
       if( byteRead  == 'I'){   // intertval speed
          readValue(pulseId,&interval[pulseIdInt],&deadVal1,&deadVal2);  
           }
           
           

        if( byteRead  == 'W'){   // intertval speed
         readValue(pulseId,&rotationStart,&rotationEnd,&deadVal2);  
           }
           
       if( byteRead  == 'J'){   // speed up
                   
                   
         readValue(pulseId,&jumpLed[pulseIdInt],&deadVal1,&deadVal2);  
           }
           
           
        if( byteRead  == 'L'){   // speed up            
         readValue(pulseId,&limitStartX[pulseIdInt],&deadVal2,&limitEndX[pulseIdInt]);        
           }
           
         if( byteRead  == 'A'){   // speed up      
       //  Serial.print(">A");
         Serial.print( byteRead );
         Serial.print(pulseId);
         
         readValue(pulseId,&activeLed[pulseIdInt],&deadVal2,&deadVal1);  
         offset[pulseIdInt] = limitStartX[pulseIdInt]; // reset offset to startPosion when actived
         Serial.print("got value A  ");
         Serial.println (activeLed[pulseIdInt]);
         }
        
    }
    
  
  }

 
  }
  
//___________________________________________________________  
  
  void readValue(char pulseId,int *val1,int *val2,int *val3){
  
      messageIter = 0;    
    for(int i=0; i < 20; i++) {   
      char c = Serial.read();  
      
       inString += c; 
       if (c == ',') {

        switch (messageIter) {
          case 1:
          *val1 =  inString.toInt();
          Serial.println(dirUpDown[pulseId]);
           inString = "";
           
          break;
         case 3:  
  

         *val2 =  inString.toInt();
          inString = "";
           break;
           case 2:


       *val3 =  inString.toInt();    
       inString = "";
           break;
         
          }
          messageIter++;
          inString = "";
       }
           
    }
    Serial.flush();
  Serial.println(">"); 
}



