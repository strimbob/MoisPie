#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	
	bSendSerialMessage = false;
	ofBackground(255);	
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	font.loadFont("DIN.otf", 64);
	
	serial.listDevices();
	vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
	
	// this should be set to whatever com port your serial device is connected to.
	// (ie, COM4 on a pc, /dev/tty.... on linux, /dev/tty... on a mac)
	// arduino users check in arduino app....
	int baud = 9600;
	serial.setup(0, baud); //open the first device
	//serial.setup("COM4", baud); // windows example
	//serial.setup("/dev/tty.usbserial-A4001JEC", baud); // mac osx example
	//serial.setup("/dev/ttyUSB0", baud); //linux example
    serial.flush(true,true);
	
	nTimesRead = 0;
	nBytesRead = 0;
	readTime = 0;
	memset(bytesReadString, 0, 4);
    
//    string temp = "1c255w";
//    unsigned char * myNumChars = (unsigned char *) temp.c_str();
//    serial.writeBytes(myNumChars, temp.length());
    	gui.setup("panel");
    gui.add(color.set("color",ofColor(100,100,140),ofColor(0,0),ofColor(255,255)));
    
    gui.add(colourtoChange.set("colourtoChange",0,0,9));
    gui.add(dir.set(1));
    gui.add(actvie.set(1));
    gui.add(fade.set("fade",200,0,255));
    
    gui.add(offset.set("offset",0,0,255));
    
    gui.add(interval.set("interval",0,0,30));
    
    gui.add(roationStart.set("roationStart",0,0,8));
    
    gui.add(roationEnd.set("roationEnd",8,0,8));
    
    gui.add(jumpedLed.set("jumpedLed",1,1,200));
    
    
    gui.add(startLimit.set("startLimit",1,1,180));
    
    gui.add(endLimt.set("endLimt",1,1,180));

    
    ofxPanel gui;

}

//--------------------------------------------------------------
void testApp::update(){
    
    

    
}

//--------------------------------------------------------------
void testApp::draw(){

    gui.draw();

}
void testApp::superLightChange(int grandMaster,int red,int green,int blue){
    
//  //  if(serial.available()){
//
//    ofColor colorSend = color;
//    cout << colorSend << " " << colorSend.getHex() << " get hex " << endl;
//
//  // string temp = "1c"+ ofToString(grandMaster)+ "w"+ "2c"+ ofToString(red)+"w"+"3c"+ ofToString(green)+"w"+"4c"+ ofToString(blue)+"w";
//    
//  string  temp = ofToString(0x800000);
//   //    string temp = "1c"+ ofToString(red)+ "w"+ "2c"+ ofToString(red)+"w"+"3c"+ ofToString(red)+"w"+"4c"+ ofToString(red)+"w";
//   // string temp = "1c"+ ofToString(grandMaster)+ "2c"+ ofToString(red);
//    unsigned char * myNumChars = (unsigned char *) temp.c_str();
//    //if(tempOld != temp){
//    serial.writeBytes(myNumChars, temp.length());
//    //}
//    tempOld = temp;
    //}
    
}
//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    
    serial.drain();
    if(key == 'c'){
        
        ofColor aa;
        aa = color;
        aa.a;
        cout << color << endl;
        
        
        
        
        string temp = "@C"+ofToString((int)colourtoChange)+","+ofToString((int)aa.r)+","+ofToString((int)aa.g)+","+ofToString((int)aa.b)+",endofline";
        //string temp = "2c255w";
        unsigned char * myNumChars = (unsigned char *) temp.c_str();
        serial.writeBytes(myNumChars, temp.length());
        
        
        
    }
    
    
    
    
    if(key == 'f'){
        

        
        
        
        
        string temp = "@F"+ofToString((int)colourtoChange)+","+ofToString((int)fade)+",255,255,endofline";
        //string temp = "2c255w";
        unsigned char * myNumChars = (unsigned char *) temp.c_str();
        serial.writeBytes(myNumChars, temp.length());
        
        
        
    }
    
    
    
    if(key == 'd'){
        
        string temp = "@D"+ofToString((int)colourtoChange)+","+ofToString((int)dir)+",255,255,endofline";
        //string temp = "2c255w";
        unsigned char * myNumChars = (unsigned char *) temp.c_str();
        serial.writeBytes(myNumChars, temp.length());
        
        
        
    }
    
    
    if(key == 'o'){
        
        string temp = "@O"+ofToString((int)colourtoChange)+","+ofToString((int)offset)+",255,255,endofline";
        //string temp = "2c255w";
        unsigned char * myNumChars = (unsigned char *) temp.c_str();
        serial.writeBytes(myNumChars, temp.length());
        
        
        
    }
    
    
    
    
    if(key == 'i'){
        
        string temp = "@I"+ofToString((int)colourtoChange)+","+ofToString((int)interval)+",255,255,endofline";
        //string temp = "2c255w";
        unsigned char * myNumChars = (unsigned char *) temp.c_str();
        serial.writeBytes(myNumChars, temp.length());
        
        
        
    }

    if(key == 'w'){
        
        string temp = "@W"+ofToString((int)colourtoChange)+","+ofToString((int)roationStart)+","+ofToString((int)roationEnd)+",255,endofline";
        //string temp = "2c255w";
        unsigned char * myNumChars = (unsigned char *) temp.c_str();
        serial.writeBytes(myNumChars, temp.length());
        
        
        
    }
    
    
    if(key == 'j'){
        
        string temp = "@J"+ofToString((int)colourtoChange)+","+ofToString((int)jumpedLed)+",255,255,endofline";
        //string temp = "2c255w";
        unsigned char * myNumChars = (unsigned char *) temp.c_str();
        serial.writeBytes(myNumChars, temp.length());
        
        
        
    }
    


    
    if(key == 'l'){
        
        string temp = "@L"+ofToString((int)colourtoChange)+","+ofToString((int)startLimit)+","+ofToString((int)endLimt)+",255,endofline";
        //string temp = "2c255w";
        unsigned char * myNumChars = (unsigned char *) temp.c_str();
        serial.writeBytes(myNumChars, temp.length());
        
        
        
    }
    
    
    if(key == 'a'){
        
        string temp = "@A"+ofToString((int)colourtoChange)+","+ofToString((int)actvie)+",255,255,endofline";
        //string temp = "2c255w";
        unsigned char * myNumChars = (unsigned char *) temp.c_str();
        serial.writeBytes(myNumChars, temp.length());
        
        
        
    }
    
    
    
    
    

    
    
    
//    unsigned char buf[2] = {'c', 'w'};
////    unsigned char bufTest[8] = {'1','c','255', 'w','2','c','255','w'};
//    unsigned char ch1 = 1;
//    unsigned char ch2 = 2;
//    unsigned char ch3 = 3;
//    unsigned char ch4 = 4;
//    unsigned char val1 = 255;
//    unsigned char val2 = 255;
//    unsigned char val3 = 255;
//    unsigned char val4 = 255;
//    
//  //  serial.writeBytes("1c255w2c255w", 8);
//    
//  
//    
//    
//    string temp = "1c255w2c255w";
//    //string temp = "2c255w";
//    unsigned char * myNumChars = (unsigned char *) temp.c_str();
//    serial.writeBytes(myNumChars, temp.length());
//    
//    
//	if(key == OF_KEY_UP){
//        serial.writeByte(ch1);
//        serial.writeBytes(&buf[0], 1);
//       // serial.writeBytes(buf, 3);
//        serial.writeByte(val1);
//        serial.writeBytes(&buf[1], 1);
//
//    }
//    if(key == OF_KEY_LEFT){
//        serial.writeByte(ch2);
//        serial.writeBytes(&buf[0], 1);
//        serial.writeByte(val2);
//        serial.writeBytes(&buf[1], 1);
//    }
//    if(key == OF_KEY_DOWN){
//        serial.writeByte(ch3);
//        serial.writeBytes(&buf[0], 1);
//        serial.writeByte(val3);
//        serial.writeBytes(&buf[1], 1);
//    }
//    if(key == OF_KEY_RIGHT){
////        serial.writeByte('255');
////        serial.writeByte('w');
//        serial.writeByte(ch4);
//        serial.writeBytes(&buf[0], 1);
//        serial.writeByte(val4);
//        serial.writeBytes(&buf[1], 1);
//    }
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    

    
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	bSendSerialMessage = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
	
}

