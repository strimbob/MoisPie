#include "ofApp.h"



float theta = -.11;//angle variable
int numberOf = 13;
float incrNum = TWO_PI/numberOf;
float circleDiameter = 280;
float gotoRoation;
int minColorOne = 5;
int maxColorOne = 30;
int minColorTwo = 0;
int maxColorTwo = 15;
int ledNumberStrip = 60;
int number = 9;
int stripHeight = 8;      // pixel height of strip
int stripsPerPort = 8;    // total number of strips per port
int numPorts = 1;         // total number of teensy ports?
bool solo;
ofColor * ben;

bool teesnyLed = true;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    end = 1; // tweener end
  //  numberOf = 9;
    mesh = ofMesh::plane(200, 200);
    vbo = mesh;
    int q;
    int spaceing;
        cam.setFarClip(-4000);
    for(float x =theta;x<TWO_PI+theta;x+=incrNum,q ++,spaceing ++){
        
        
        vector<ofVec3f> ledsTemp;
        vector<ofColor>tempColor;
        for(int q =0;q<ledNumberStrip;q++){
            float xa = ((sin(x)*(circleDiameter*q)));
            float ya =  (cos(x)*(circleDiameter*q));
            float za = 0;
            
            ledsTemp.push_back(ofVec3f(xa ,ya ,za));
            tempColor.push_back(ofColor(0,0,0));
            
        }
        color.push_back(tempColor);
        leds.push_back(ledsTemp);
        ledsFactored.push_back(ledsTemp);
    }
    
    
    
    for(float x =0;x<numberOf;x++,q ++,spaceing ++){
        vector<ofVec3f> ledsTemp;
        vector<ofColor>tempColor;
        for(int q =0;q<ledNumberStrip;q++){
//            float xa = ((sin(x)*(circleDiameter*q)));
//            float ya =  (cos(x)*(circleDiameter*q));
            float za = 0;
            ledsTemp.push_back(ofVec3f((x*210)-circleDiameter*40 ,(q*210)-circleDiameter*20 ,za));
        //    tempColor.push_back(ofColor(0,0,0));
        }

      //  color.push_back(tempColor);
        ledsSquare.push_back(ledsTemp);

    }

    presetActive = 0;



    for(int t = 0;t<numberOf;t++){
        
                colorFor.push_back(color);
        

        
    }
    
    
     for(int t = 0;t<number;t++){

         fadeTime.push_back(10);
         tween.push_back(0);
         tweenTime.push_back(1);
         _red.push_back(ofRandom(255));
         _blue.push_back(ofRandom(255));
         _green.push_back(ofRandom(255));
         _redTween.push_back(ofRandom(255));
         _blueTween.push_back(ofRandom(255));
         _greenTween.push_back(ofRandom(255));
         _tweenTime.push_back(ofRandom(255));
         _active.push_back((int)ofRandom(2));
         _rotRL.push_back((int)ofRandom(2) );
         _rotUpDown.push_back((int)ofRandom(2) );
         _ledPosX.push_back(0);
         _ledPosY.push_back(0);
         __widthLed.push_back(numberOf/4);
         __hightLed.push_back(ledNumberStrip/4);
         
         __widthLedTween.push_back(numberOf);
         __hightLedTween.push_back(ledNumberStrip);
         _ledPosXTween.push_back(numberOf);
         _ledPosYTween.push_back(ledNumberStrip);
         _rotRLTween.push_back(ofRandom(2));
         _rotUpDownTween.push_back(ofRandom(2));
         
         _RLStop.push_back((int)ofRandom(2) );
         _rotUpStop.push_back((int)ofRandom(2) );
         
         
         pingPongUpDown.push_back((int)ofRandom(2) );
         pingPongLeftRight.push_back((int)ofRandom(2) );
         tempactive.push_back(0);
         
     }

    
  //  bb = 255;
  
  //  aa.set(bb, bb, bb);
    gui  = new ofxUISuperCanvas("Live ", OFX_UI_FONT_MEDIUM);
    gui1 = new ofxUISuperCanvas("Preset", OFX_UI_FONT_MEDIUM);
    gui2  = new ofxUISuperCanvas("screen Control", OFX_UI_FONT_MEDIUM);

    //  gui->setRetinaResolution();
       gui1->addSpacer();
    gui->setGlobalButtonDimension(24);
    gui1->setGlobalButtonDimension(24);
    gui2->setGlobalButtonDimension(24);
    //gui->setColorOutlineHighlight(aa);
    gui->addSpacer();
    gui->addToggleMatrix("select Color", 3, 3);

    ofxUIToggleMatrix* mtx = (ofxUIToggleMatrix *) gui->getWidget("select Color");
    mtx->setAllowMultiple(false);
    
gui->addWidgetRight(new ofxUILabel(".          Active", OFX_UI_FONT_SMALL), OFX_UI_ALIGN_LEFT );
//      gui->setPadding(50);
    gui->addWidgetRight(new ofxUIToggle("'" ,&active, 75, 75,10,110));
    
    //    gui->setPadding(2);
    
    
    
    
//      gui->addSpacer()->setColorFill(ofColor(245,2,2));
//    gui->setColorPadded(ofColor(255,2,2));

 //   gui->addWidgetDown(new ofxUISpacer(250,40));
   // gui->setColorFillHighlight(ofColor(255,0,0));
  //  gui->addSpacer()->setColorFill(ofColor(245,2,2));
    //gui->addWidgete(new ofxUILabel("CUSTOM WIDGET LAYOUT", OFX_UI_FONT_LARGE), OFX_UI_ALIGN_RIGHT );
    
//    gui->addWidgetEastOf(new ofxUIToggle("active", &active, 30, 30,200,20), "select Color");
//    
//
    
     gui->addSpacer();
//gui->addWidgetDown(new ofxUIToggle("''     |", &active, 30, 30,200,20));
//    gui->addSpacer();
    


  //  gui->addToggle("Active         solo", &active, 30, 30,200,20);
//    gui->addWidgetRight(new ofxUILabel
//    gui->addWidgetRight(new ofxUILabel ("color"));
    gui->addWidgetDown(new ofxUIToggle("solo", &solo, 30, 30,1,133));
    gui->addSpacer();
//    gui->addLabel(".           solo");
//    gui->addWidgetRight(new ofxUIToggle("", &solo, 30, 30,200,20));
 //   gui->addToggle("solo", &solo, 30, 30,200,20);
    gui->addLabel("color");
	gui->addIntSlider("RED", 0, 255, &red)->setTriggerType(OFX_UI_TRIGGER_ALL);
	gui->addIntSlider("GREEN", 0, 255, &green)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE|OFX_UI_TRIGGER_END);
	gui->addIntSlider("BLUE", 0, 255, &blue)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
    
    gui->addSlider("fade", 0, 255, &fade)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
    gui->addSpacer();
    gui->addLabel("direction");

    
    gui->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);
    
    
  //  gui->addMultiImageButton("IMAGE BUTTON", "arrows/toggle.png", false);
    int sizeButton = 45;
 
    gui->addMultiImageToggle("upDown", "GUI/upDown/toggle.png", false,sizeButton,sizeButton);
    gui->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);
    gui->addToggle("UpDownStartStop", &UpDownstartStop, sizeButton,sizeButton,200,20)->setLabelVisible(false);
    
    //gui->addMultiImageToggle("playPause", "GUI/playPause/toggle.png", false);
    gui->addMultiImageToggle("leftRight", "GUI/leftRight/toggle.png", false,sizeButton,sizeButton);
    gui->addToggle("leftRightStartStop", &leftRightstartStop, sizeButton, sizeButton,200,20)->setLabelVisible(false);

    
    gui->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);
    
//    gui->addToggleMatrix("direction Live", 1,4);
//    ofxUIToggleMatrix* direction = (ofxUIToggleMatrix *) gui->getWidget("direction Live");
//    direction->setAllowMultiple(true);
   // ofImage* aa;
   // gui->getWidget("direction Live(0,0)")->addWidget( ofxUIImage(20, 20, aa , "image"));

    gui->addSpacer();
gui->addLabel("size");
    gui->setDrawWidgetPadding(drawPadding);
//gui->addro
    gui->addRotarySlider("width of light", 0.0, numberOf, &_widthLed,100,75)->setLabelVisible(false);
        gui->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);
    gui->addCircleSlider("height of light", 0, ledNumberStrip, &_hightLed,100,75)->setLabelVisible(false);
    //gui->addIntSlider("ledPosX", 0, 30, &ledPosX)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
   // gui->addIntSlider("ledPosY", 0, numberOf, &ledPosY)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
  //r  gui->addIntSlider("width of light", 0, numberOf, &_widthLed)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
  //  gui->addIntSlider("hieght of light", 0, ledNumberStrip, &_hightLed)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
       gui->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);
    gui->addSpacer();
    
    gui->addButton("Save          load", &liveSave, 30, 30,200,20);
    
   gui->addWidgetRight(new ofxUIButton("|", &liveLoad, 30, 30,200,20));


    gui->addSpacer();
    gui->autoSizeToFitWidgets();
    gui1->addToggleMatrix("Tween to Color", 3, 3);
    
    ofxUIToggleMatrix* preset = (ofxUIToggleMatrix *) gui1->getWidget("Tween to Color");
    preset->setAllowMultiple(false);
    
    gui1->addSpacer();
    gui1->addLabel("Tween - timer");
    gui1->addButton("GO!!", false, 30, 30);
    gui1->addSlider("tween", 2, 10, &_tween)->setTriggerType(OFX_UI_TRIGGER_ALL);
    gui1->addSpacer();
    gui1->addLabel("color");
	gui1->addIntSlider("RED", 0, 255, &redTween)->setTriggerType(OFX_UI_TRIGGER_ALL);
	gui1->addIntSlider("GREEN", 0, 255, &greenTween)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE|OFX_UI_TRIGGER_END);
	gui1->addIntSlider("BLUE", 0, 255, &blueTween)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
    gui1->addSlider("fade", 0, 255, &_fadeTime)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
    
   // ((ofxUIRadio *) guiSC->getWidget("CNODE"))->activateToggle("ALL");
    
    gui1->addLabel("direction / auto change");
//    gui1->addto
   /// gui1->addToggleMatrix("directionTeen", 1,6);
  //  ofxUIToggleMatrix* directionTween = (ofxUIToggleMatrix *) gui1->getWidget("directionTween");
   // direction->setAllowMultiple(true);
    
    gui1->addIntSlider("ledPosX", 0, numberOf, &ledPosXTween)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
    gui1->addIntSlider("ledPosY", 0, ledNumberStrip, &ledPosYTween)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
    
    gui1->setDrawWidgetPadding(drawPadding);
    gui1->addIntSlider("width of light", 0, numberOf, &_widthLedTween)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
    gui1->addIntSlider("height of light", 0, ledNumberStrip, &_hightLedTween)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);

    
    

    gui1->autoSizeToFitWidgets();

    gui1->setDrawWidgetPadding(drawPadding);
    ofAddListener(gui->newGUIEvent,this,&ofApp::guiEvent);
     ofAddListener(gui1->newGUIEvent,this,&ofApp::guiEvent);
    gui->setPosition(0, 0);
    gui1->setPosition(ofGetWidth()-210, 0);
    gui2->setPosition(0, ofGetHeight()-100);

 //   for(int x =0;x<9;x++){
    

//    gui2->addLabel("'1' TO ADD TO LIST", OFX_UI_FONT_SMALL);
//    gui2->addLabel("'2' TO DELETE FROM LIST", OFX_UI_FONT_SMALL);
    
    
    vector<string> names;
    names.push_back("Circle");    names.push_back("Square");
    gui2->setWidgetFontSize(OFX_UI_FONT_MEDIUM);
    ddl = gui2->addDropDownList("Shapes", names);
     ddl->setShowCurrentSelected(2);
//    ((ofxUIToggleMatrix *) gui->getWidget("Square"))->setShowCurrentSelected(1);
//    ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
//    ddl->setShowCurrentSelected(toggle->getValue());
    
    ofAddListener(gui2->newGUIEvent, this, &ofApp::guiEvent);
        gui2->autoSizeToFitWidgets();
//    ((ofxUIToggleMatrix *) gui->getWidget("direction Live"))->setToggle(0, 0, _rotRL[presetActive]);
//    ((ofxUIToggleMatrix *) gui->getWidget("direction Live"))->setToggle(0, 1, _rotUpDown[presetActive]);
//    ((ofxUIToggleMatrix *) gui->getWidget("direction Live"))->setToggle(0, 2, _RLStop[presetActive]);
//    ((ofxUIToggleMatrix *) gui->getWidget("direction Live"))->setToggle(0, 3, _rotUpStop[presetActive]);
//  ((ofxUIToggleMatrix *) gui->getWidget("direction Live"))->setToggle(0, 4, pingPongUpDown[presetActive]);
//    ((ofxUIToggleMatrix *) gui->getWidget("direction Live"))->setToggle(0, 5, pingPongLeftRight[presetActive]);
    
//        cout << _rotRL[x] << " bool " << endl;
   // }
    
     ((ofxUIToggleMatrix *) gui->getWidget("select Color"))->setToggle(0, 0,1);
    cam.disableMouseInput();
    
    
        teensy.setup(ledNumberStrip , stripHeight*stripsPerPort*numPorts);
    
    
    teensy.serialConfigure("tty.usbmodem23781", ledNumberStrip , stripHeight*stripsPerPort, 0, 0, 100, 50, 0);
    //teensy.serialConfigure("tty.usbmodem23781", ledNumberStrip , stripHeight*stripsPerPort, 0, 50, 100, 50, 0);
    
    // allocate our pixels & fbo
    teensy.pixels1.allocate(ledNumberStrip , stripHeight*stripsPerPort*numPorts, OF_PIXELS_RGB);
    // fbo.allocate(ledNumberStrip , stripHeight*stripsPerPort*numPorts, GL_RGB);
    fbo.allocate(ledNumberStrip , stripHeight, GL_RGB);
    
}

//// tried it with matrix - seems to work
//int ofApp::getSelection(ofxUIToggleMatrix* matrix) {
//    vector<ofxUIToggle*> toggles = matrix->getToggles();
//    for(int i = 0; i < toggles.size(); i++) {
//        if(toggles[i]->getValue()) {
//            return i;
//        }
//    }
//    return -1;
//    
//}



void ofApp::updateFbo(){
    fbo.begin();
    
    //   ofClear(0,0,0);    // refreshes fbo, removes artifacts
    ofSetColor(255, 255, 255);
 //   if(play){
    //    video.draw(0, 0,ledNumberStrip , stripHeight);
  //  }else{
        // teensy demo draw modes...
        //teensy.drawDebug(brightness, debugScroll);
        
        for(int x = 0;x<leds.size();x++){
            for(int y = 0;y<leds[x].size();y++){
                ofColor temp = ofColor(0,0,0);
                for(int t = 0;t<colorFor.size();t++){
                    temp += colorFor[t][x][y];
                    
                }
                
                // colorFinal[x][y]  = ofColor( ofRandom(255),255,10);
                ofSetColor(temp);
                
                // ofSetColor(ofRandom(255),255,10);
                
                ofRect(y*1, x*1, 1, 1);
                //  cout << colorFinal[x][y] << endl;
            }
        }
   // }
    
    
    fbo.end();
    
    fbo.readToPixels(teensy.pixels1);    // send fbo pixels to teensy
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if( teesnyLed){
    teensy.update();
    updateFbo();
    };
    Tweener.update();
    updatePresetActive();
    //aa.set(244, 0, 0);
 
//    __widthLed[presetActive] = _widthLed;
//    __hightLed[presetActive] = _hightLed;
//    _ledPosX[presetActive] =ledPosX;
//    _ledPosY[presetActive] = ledPosY ;
    
    int clampedY;
    int clampedX;
    
    
    for(int t = 0;t<number;t++){   /// cycle throug different colours
      //  cout << _ledPosX[t] << endl;
        if(_active[t]){
        _ledPosX[t] = poistionLed( _rotUpStop[t], _ledPosX[t],__hightLed[t], ledNumberStrip,_rotUpDown[t]);
            
        _ledPosY[t] = poistionLed(_RLStop[t],_ledPosY[t],__widthLed[t],numberOf,_rotRL[t]);
        
      //  cout << _ledPosX[t] << endl;
        
        
        for(int y = _ledPosY[t];y<_ledPosY[t]+__widthLed[t];y++){
            
            clampedY = clampVals(y,numberOf,__widthLed[t],0);
            
            
            for(int x = _ledPosX[t];x<__hightLed[t]+_ledPosX[t];x++){
                
                clampedX =  clampVals(x,ledNumberStrip, __hightLed[t],0);
                
                colorFor[t][clampedY][clampedX] =  ofColor(_red[t],_green[t],_blue[t]); // store the color in to array
                
            }
            
        }
        }
        
        for(int y = 0;y<colorFor[t].size();y++){   /// fade the colour back down to black
            for(int x = 0;x<colorFor[t][y].size();x++){
                //   colorFor[t][y][x] -= colorFor[t][y][x]/((float)fadetimeFor[t]/5);
                 //    colorFor[t][y][x] -= colorFor[t][y][x]/((float)_tweenTime[t]/10);
                colorFor[t][y][x] -= (int)fadeTime[t];
               // CLAMP(x, 0, totalLed);
                colorFor[t][y][x].r = CLAMP(colorFor[t][y][x].r,0,255);
                colorFor[t][y][x].g = CLAMP(colorFor[t][y][x].g,0,255);
                colorFor[t][y][x].b = CLAMP(colorFor[t][y][x].b,0,255);
             //   cout << fadeTime[t] << endl;
            }
            
            
        }
        
        
    }
    
   //            ((ofxUIToggleMatrix *) gui->getWidget("direction Live"))->getToggle(0, 2)->setColorOutline(ofColor(255,0,0));
//    teensy.update();
//    updateFbo();
    
    cam.setPosition(0, 0, 29000);

    
   // gui->
}



//--------------------------------------------------------------
int ofApp::poistionLed(bool onOff,int _poistion,int _lenght,int totalLed,bool direation){
    
////    onOff = ofRandom(2);
////    direation = ofRandom(2);
    if(direation){
        
        
        if(onOff){
            _poistion --;
            
        }
        
        if(_poistion <= _lenght){
            //_poistion = _lenght;
            _poistion =  totalLed + _lenght;
        }
//
//        
    }
        else{
    
        
        if(onOff){
            _poistion ++;
            
        }
        
        if(abs(_poistion) > totalLed+_lenght){
            _poistion = _lenght;
            
        }
    }
    return _poistion;
    
}

//--------------------------------------------------------------
int ofApp::clampVals(int x,int totalLed,int length,int clamped = 0){
    
    
    clamped  = CLAMP(x, 0, totalLed);   // stay in range of phisaly leds
   // clamped = x;
    if (x >= totalLed) {               // if current poistion greater than totalled leds
        clamped = x - (totalLed + length);   // start to count up from 0
    //    cout << clamped << endl;
        if(clamped <= length){
            clamped = ofMap(clamped, -length, 0, 0, length);
        }
    }
    
    
    //    if(clamped <= length){
    //
    //            clamped = ofMap(clamped, -length, 0, 0, length);
    //
    //
    //    }
    
    return clamped = CLAMP(clamped, 0, totalLed-1);
    
}




void ofApp::updatePresetActive(){

    
    gui->getWidget("RED")->setColorFill(ofColor(red,green,blue));
    gui->getWidget("RED")->setColorFillHighlight(ofColor(red,green,blue));
    
    gui->getWidget("GREEN")->setColorFill(ofColor(red,green,blue));
    gui->getWidget("GREEN")->setColorFillHighlight(ofColor(red,green,blue));
    
    gui->getWidget("BLUE")->setColorFill(ofColor(red,green,blue));
    gui->getWidget("BLUE")->setColorFillHighlight(ofColor(red,green,blue));
    
    
    
    gui->getWidget("'")->setColorFill(ofColor(red,green,blue));
    gui->getWidget("'")->setColorFillHighlight(ofColor(red,green,blue));
    
    gui->getWidget("width of light")->setColorFill(ofColor(red,green,blue));
    gui->getWidget("height of light")->setColorFill(ofColor(red,green,blue));
gui->getWidget("fade")->setColorFill(ofColor(red,green,blue,ofMap(fade, 0, 255, 255, 100)   ));
    
    int tempNumer = 0;
    for(int y = 0;y<_red.size()/3;y++){
    for(int x = 0;x<_red.size()/3;x++){
        gui->getWidget("select Color(0,0)")->setColorFillHighlight(ofColor(255,255,255));
        
        
//        if(presetActive == tempNumer){
//             gui->getWidget("select Color("+ofToString(x)+","+ofToString(y)+")")->setColorFill(ofColor(_red[tempNumer]*2,_green[tempNumer]*2,_blue[tempNumer]*2,255));
//            
//        }else{
//      gui->getWidget("select Color("+ofToString(x)+","+ofToString(y)+")")->setColorFill(ofColor(_red[tempNumer],_green[tempNumer],_blue[tempNumer],170));
//        }
        

        
        if(!_active[tempNumer]){
    gui->getWidget("select Color("+ofToString(x)+","+ofToString(y)+")")->setColorBack(ofColor(20,20,20,255));
        }else{
            
                          gui->getWidget("select Color("+ofToString(x)+","+ofToString(y)+")")->setColorBack(ofColor(_red[tempNumer],_green[tempNumer],_blue[tempNumer]));
        }
        
        
        if(presetActive == tempNumer){
            if(!active){
              gui->getWidget("select Color("+ofToString(x)+","+ofToString(y)+")")->setColorBack(ofColor(60,60,60));
            }else{
            gui->getWidget("select Color("+ofToString(x)+","+ofToString(y)+")")->setColorBack(ofColor(255,255,255));
            }
        }
        tempNumer ++;
    }
    }
   
    
    
    for(int x = 0;x<leds.size();x++){
        for(int y = 0;y<leds[x].size();y++){
            
 ledsFactored[x][y].x =   ofLerp(leds[x][y].x, ledsSquare[x][y].x, shapeTween);
     ledsFactored[x][y].y =   ofLerp(leds[x][y].y, ledsSquare[x][y].y, shapeTween);
          //  ledsFactored[x][y] =   ofLerp(leds[x][y], ledsSquare[x][y], ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 1));
        }
    }
    
    
    if(tween[presetActive] != end){

    red =    ofLerp(red, redTween,tween[presetActive]);
    blue =   ofLerp(blue, blueTween,tween[presetActive]);
    green =  ofLerp(green, greenTween,tween[presetActive]);
        fade = ofLerp(fade, _fadeTime, tween[presetActive]);
        
        rotRL = rotRLTween;
        rotUpDown = rotUpDownTween;
        _widthLed  = ofLerp(_widthLed, _widthLedTween, tween[presetActive]);
        _hightLed = ofLerp(_hightLed, _hightLedTween, tween[presetActive]);
        ledPosX  = ofLerp(ledPosX, ledPosXTween, tween[presetActive]);
        ledPosY  = ofLerp(ledPosY, ledPosYTween, tween[presetActive]);
        
        _red[presetActive] = red;
        _blue[presetActive] = blue;
        _green[presetActive] = green;
      // _tweenTime[presetActive] = _fadeTime ;
        
        
        
    }
    

    
}
//--------------------------------------------------------------
void ofApp::draw(){
    
//    	ofBackgroundGradient( ofColor::black,ofColor::gray, OF_GRADIENT_CIRCULAR);
//    ofSetColor(red, green, blue);
//    ofRect(129,29,77,77);
    
   // cout << ofGetMouseX() << " " << " " << ofGetMouseY() <<  endl;
//
//    ofSetColor(redTween, greenTween, blueTween);
//    //ofRect(90,ofGetHeight()-80,80,80);
//    cout << ofGetMouseX() << " " << ofGetMouseY() << endl;
//ofSetColor(_red[0], _green[0], _blue[0]);
//      ofRect(5,29,22,24);
//   
//    ofSetColor(_red[1], _green[1], _blue[1]);
//    ofRect(ofGetMouseX()+5,ofGetMouseY()+29,22,24);
//    ofRect(ofGetMouseX(), ofGetMouseY(), 20, 20);
//    
//    cout << ofGetMouseX() << " " << ofGetMouseY() << endl;
    
//    for(int x = 0;x<ledNumberStrip;x++){
//        
//       ofSetColor( colorFor[presetActive][0][x]);
//        //ofSetColor(_red[forColr-1], _green[forColr-1], _blue[forColr-1]);
//        ofRect(x*20,492,19,19);
//    }
//    int _x = 0;
//    int _y = 0;
//    int forColr = 0;
//    for(int xb = 0;xb<3;xb++){
//          for(int yb = 0;yb<3;yb++){
//              forColr ++;
//        ofSetColor(_red[forColr-1], _green[forColr-1], _blue[forColr-1]);
//              ofRect(_y+5,_x+29,22,24);
//              if(!_active[forColr-1]){
//                  ofSetColor(0,0,0);
//                ofRect(_y+8,_x+32,17,19);
//              }
//              _y += 26;
//            //  cout << forColr << " " << _red.size() << " ? ?" <<  endl;
//    }
//        _y = 0;
//        _x += 26;
//    }
    
     //  ofRect(ofGetMouseX(), ofGetMouseY(),80,80);
//    for(int x = 0; x < _red.size();x++){
//        
//        ofSetColor(_red[x], _green[x], _blue[x]);
//        ofRect(ofGetWidth()-80,x *80,80,80);
//    }
    
    
//    for(int x = 0; x < _red.size();x++){
//        
//        ofSetColor(_red[x], _green[x], _blue[x]);
//        ofRect(ofGetWidth()-80,x *80,80,80);
//    }
    
    
    cam.begin();
    for(int x = 0;x<leds.size();x++){
        for(int y = 0;y<leds[x].size();y++){
            ofColor temp = ofColor(0,0,0);
                      //    ofPushMatrix();
            for(int t = 0;t<colorFor.size();t++){
  
                temp += colorFor[t][x][y];
                ofSetColor(temp);
                
              }
          //      ofTranslate(leds[x][y]);
        //    vbo.drawInstanced(OF_MESH_FILL, 1);
                ofRect(ledsFactored[x][y], 200, 200);
            //    ofPopMatrix();
       
            
            
        }
    }
    
    cam.end();
    

 //  cout << ofGetMouseX() << " " <<  ofGetMouseY() << endl;

}
//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs &e)
{

	string name = e.widget->getName();
    
	int kind = e.widget->getKind();
    
    vector<string> _name = ofSplitString(name, " ");
    ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
    
    
    vector<string> _nameB = ofSplitString(name, " ");
    ofxUIButton *Button = (ofxUIToggle *) e.widget;
    
    if(kind == OFX_UI_WIDGET_BUTTON){
        
        
        if(_nameB[0] == "|"){
            if(Button->getValue()){
            cout << "loading  main.xml" << endl;
            load();
            }
            
        }
        if(_nameB[0] == "Save"){
            if(Button->getValue()){
            save();
                    cout << "save  main.xml" << endl;
            }
       
        }
    }
     if(name == "Shapes"){
        ofxUIDropDownList *ddlist = (ofxUIDropDownList *) e.widget;
        vector<ofxUIWidget *> &selected = ddlist->getSelected();
        for(int i = 0; i < selected.size(); i++)
        {
            cout << "SELECTED: " << selected[i]->getName() << endl;

            if(selected[i]->getName() == "Circle"){
                float endy = 0;
                Tweener.addTween(shapeTween, endy , 2);
            }
       
         if(selected[i]->getName() == "Square"){
             float endy = 1;
             Tweener.addTween(shapeTween, endy , 2);
         }
     }
    }
    

    if(kind == OFX_UI_WIDGET_MULTIIMAGETOGGLE){
        cout << name << endl;
         if(name == "upDown"){
          //    _rotu[presetActive] = toggle->getValue();
            _rotUpDown[presetActive] = toggle->getValue();
             cout << " what the fdasfdsaf " << endl;
        }
        
        else if(name == "leftRight"){
            _rotRL[presetActive] = toggle->getValue();
          cout << " what the fdasfdsaf " << endl;
        }
        
    }
    if(kind == OFX_UI_WIDGET_TOGGLE){
        cout << name << " " << e.widget->getKind() << endl;
        
        

        if(_name[0] == "select"){
        
        //if(name == "select Color"){
 
       
        presetActive = ((int)(toggle->getID()/2)-1);
        red = _red[presetActive];
        blue = _blue[presetActive];
        green = _green[presetActive];
        fade = fadeTime[presetActive];
        active = _active[presetActive];
        
            _widthLed = __widthLed[presetActive];
             _hightLed = __hightLed[presetActive];
             ledPosX = _ledPosX[presetActive];
             ledPosY = _ledPosY[presetActive];

 
//            ((ofxUIToggleMatrix *) gui->getWidget("direction Live"))->setToggle(0, 0, _rotRL[presetActive]);
//            ((ofxUIToggleMatrix *) gui->getWidget("direction Live"))->setToggle(0, 1, _rotUpDown[presetActive]);
//            ((ofxUIToggleMatrix *) gui->getWidget("direction Live"))->setToggle(0, 2, _RLStop[presetActive]);
//            ((ofxUIToggleMatrix *) gui->getWidget("direction Live"))->setToggle(0, 3, _rotUpStop[presetActive]);
//            ((ofxUIToggleMatrix *) gui->getWidget("direction Live"))->setToggle(0, 4,  pingPongUpDown[presetActive]);
//            ((ofxUIToggleMatrix *) gui->getWidget("direction Live"))->setToggle(0, 5, pingPongLeftRight[presetActive]);
//            ((ofxUIToggleMatrix *) gui->getWidget("direction Live"))->activateToggle("direction Live(1,0)");
 
            
            
        //    aa.setColorFill(ofColor (22,22,255));
            
            
//            _rotRL[presetActive] = toggle->getValue();
//            
//            
//        }else if (toggle->getID() == 37){
//            _rotUpDown[presetActive]  = toggle->getValue();
//        }
//        else if (toggle->getID() == 39){
//            
//            _RLStop[presetActive]  = toggle->getValue();
//            
//            
//        }
  
       // toggle->setValue(_rotUpStop[presetActive]);
        
            
            
        }
        
        else if(_name[0] == "solo"){
            if(toggle->getValue()){
                  tempactive = _active;
                for(int q = 0;q<number;q++){
                    if(q != presetActive){
                      
                        _active[q] = 0;
                    }
                }
            }else{
                _active = tempactive;
            }
        }
        
        else if (_name[0] == "'"){
            _active[presetActive] =active;
            
        }
        
        else if (_name[0] == "Tween"){
      presetActiveTween =  ((int)(toggle->getID()/2)-1);
            
            
            redTween =   _redTween[presetActiveTween];
            blueTween =   _blueTween[presetActiveTween];
            greenTween =    _greenTween[presetActiveTween];
            
            _widthLedTween = __widthLedTween[presetActiveTween];
            _hightLedTween = __hightLedTween[presetActiveTween];
            ledPosXTween = _ledPosXTween[presetActiveTween];
            ledPosYTween = _ledPosYTween[presetActiveTween];
            
            
        }

        else if(name == "UpDownStartStop"){
            _rotUpStop[presetActive] = toggle->getValue();
        }
        

        
        else if(name == "leftRightStartStop"){
              _RLStop[presetActive]  = toggle->getValue();        }
        
        
//        
//        gui->addMultiImageToggle("leftRight", "GUI/leftRight/toggle.png", false);
//        gui->addToggle("leftRightStartStop", &leftRightstartStop, 20, 20,200,20)->setLabelVisible(false);
//        
        
        
        else if(_name[0] == "direction"){
//             cout << " ll " << " " << toggle->getID() << " " << toggle->getValue() << " " << toggle->getName() <<  endl;
//            
//    // ((ofxUIToggleMatrix *)       gui->getWidget("direction Live"))->gett
//            if(toggle->getID() == 39){
//                    _rotRL[presetActive] = toggle->getValue();
//                cout << " ll " << " " << toggle->getID() << endl;
//
//    
//            }else if (toggle->getID() == 41){
//                
//             _rotUpStop[presetActive]  = toggle->getValue();
//                
//            }
//            else if (toggle->getID() == 43){
//                
//         _rotUpDown[presetActive]  = toggle->getValue();
//                
//            }
//            else if (toggle->getID() == 45){
//                   _RLStop[presetActive]  = toggle->getValue();
//               
//            }
//            
//            else if (toggle->getID() == 43){
//                       pingPongUpDown[presetActive] = toggle->getValue();
//            }
//            
//            else if (toggle->getID() == 45){
//                
//                
//      
//              pingPongLeftRight[presetActive] = toggle->getValue();
//                
// 
//            }
            
          //  if(
      
   
        }
        
//        if( toggle->getID() == 22){
//
//        }else{
//
//        }

    }
    
    

    
    
    if(kind == OFX_UI_WIDGET_BUTTON){
      
        
        if(name == "GO!!"){
        ofxUIButton *button = (ofxUIButton *) e.widget;
        end = 1;
        tween[presetActive] = 0;
        Tweener.addTween(tween[presetActive], end, _tween);
        }

    }
    
   
    if((kind == 4)||(kind == 42)){ // sliders

        if(name == "ledPosX"){
                   _ledPosX[presetActive] =ledPosX;
        }
        
        if(name == "ledPosY"){
              _ledPosY[presetActive] = ledPosY ;
        }
        _red[presetActive] = red;
        _blue[presetActive] = blue;
        _green[presetActive] = green;
    fadeTime[presetActive] = fade ;
        _redTween[presetActiveTween] = redTween;
        _blueTween[presetActiveTween] =blueTween;
        _greenTween[presetActiveTween] =  greenTween ;
       // _fadeTime[presetActiveTween] = _fadeTime ;
        
        __widthLed[presetActive] = _widthLed;
        __hightLed[presetActive] = _hightLed;
        
        

  
        
//        _rotRLTween[presetActiveTween] = rotRLTween ;
//        _rotUpDownTween[presetActiveTween] = rotUpDownTween ;
        __widthLedTween[presetActiveTween] =  _widthLedTween ;
        __hightLedTween[presetActiveTween] = _hightLedTween ;
        _ledPosXTween[presetActiveTween] =  ledPosXTween ;
        _ledPosYTween[presetActiveTween] =  ledPosYTween ;
        
    }
    if((kind == OFX_UI_WIDGET_ROTARYSLIDER)||(kind == OFX_UI_WIDGET_CIRCLESLIDER)){
        _red[presetActive] = red;
        _blue[presetActive] = blue;
        _green[presetActive] = green;
        fadeTime[presetActive] = fade ;
        _redTween[presetActiveTween] = redTween;
        _blueTween[presetActiveTween] =blueTween;
        _greenTween[presetActiveTween] =  greenTween ;
        // _fadeTime[presetActiveTween] = _fadeTime ;
        
        __widthLed[presetActive] = _widthLed;
        __hightLed[presetActive] = _hightLed;
        
        
        
        
        
        //        _rotRLTween[presetActiveTween] = rotRLTween ;
        //        _rotUpDownTween[presetActiveTween] = rotUpDownTween ;
        __widthLedTween[presetActiveTween] =  _widthLedTween ;
        __hightLedTween[presetActiveTween] = _hightLedTween ;
        _ledPosXTween[presetActiveTween] =  ledPosXTween ;
        _ledPosYTween[presetActiveTween] =  ledPosYTween ;
        
    }




}
//--------------------------------------------------------------
void ofApp::exit()
{
    delete gui; 
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    
    if(key == OF_KEY_BACKSPACE){
        ofToggleFullscreen();
    }
    
    if(key == ' '){
        save();
        //cam.enableMouseInput();
    }
    if(key == 'v'){
        load();
    }
    
    switch (key)
    {
        case 'p':
        {
            drawPadding = !drawPadding; 
            gui->setDrawWidgetPadding(drawPadding);          
        }
            break;
            
        case 'g':
        {
            gui->toggleVisible(); 
        }
            break; 
        default:
            break;
    }
}

void ofApp::save(){
    ofxXmlSettings XML;
    
    
    
    for(int s = 0;s<_red.size();s++){
        
    int tagNum = XML.addTag("presetNu");
        XML.setValue("presetNu:fadeTime", fadeTime[s], tagNum);
		XML.setValue("presetNu:tween", tween[s], tagNum);
        XML.setValue("presetNu:tweenTime", tweenTime[s], tagNum);
        XML.setValue("presetNu:_red", _red[s], tagNum);
        XML.setValue("presetNu:_blue", _blue[s], tagNum);
        XML.setValue("presetNu:_green", _green[s], tagNum);
        XML.setValue("presetNu:_active", _active[s], tagNum);
        XML.setValue("presetNu:_rotRL", _rotRL[s], tagNum);
        XML.setValue("presetNu:_rotUpDown", _rotUpDown[s], tagNum);
        XML.setValue("presetNu:_ledPosX", _ledPosX[s], tagNum);
        XML.setValue("presetNu:_ledPosY", _ledPosY[s], tagNum);
        XML.setValue("presetNu:__widthLed", __widthLed[s], tagNum);
        XML.setValue("presetNu:__hightLed", __hightLed[s], tagNum);
        XML.setValue("presetNu:_RLStop", _RLStop[s], tagNum);
        XML.setValue("presetNu:_rotUpStop", _rotUpStop[s], tagNum);
        XML.setValue("presetNu:tempactive", tempactive[s], tagNum);
//        XML.setValue("presetNu:Y", tween[s], tagNum);
//        XML.setValue("presetNu:Y", tween[s], tagNum);
//        XML.setValue("presetNu:Y", tween[s], tagNum);
//        XML.setValue("presetNu:Y", tween[s], tagNum);
//        XML.setValue("presetNu:Y", tween[s], tagNum);
//        XML.setValue("presetNu:Y", tween[s], tagNum);
//        XML.setValue("presetNu:Y", tween[s], tagNum);
//        XML.setValue("presetNu:Y", tween[s], tagNum);
//        XML.setValue("presetNu:Y", tween[s], tagNum);
//        XML.setValue("presetNu:Y", tween[s], tagNum);
//        XML.setValue("presetNu:Y", tween[s], tagNum);
//        XML.setValue("presetNu:Y", tween[s], tagNum);
        
        
        
    }

//    _tweenTime.push_back(ofRandom(255));
//
//
//    __widthLed.push_back(numberOf/4);
//    __hightLed.push_back(ledNumberStrip/4);
//
//    _ledPosXTween.push_back(numberOf);
//    _ledPosYTween.push_back(ledNumberStrip);
//    _rotRLTween.push_back(ofRandom(2));
//    _rotUpDownTween.push_back(ofRandom(2));
//    
//    _RLStop.push_back((int)ofRandom(2) );
//    _rotUpStop.push_back((int)ofRandom(2) );
//    
//    
//    pingPongUpDown.push_back((int)ofRandom(2) );
//    pingPongLeftRight.push_back((int)ofRandom(2) );
//    tempactive.push_back(0);
    
    
    
    
  //  if( XML.pushTag("STROKE", lastTagNumber) ){
    
		//now we will add a pt tag - with two
		//children - X and Y
    

        
        
        
        
    //}
    
    
    XML.saveFile("live.xml");
    
    
    
}
void ofApp::load(){
    
    ofxXmlSettings XML;
    XML.load("live.xml");
    
    
    int numPtTags = XML.getNumTags("presetNu");
    
    
    for(int s = 0;s<_red.size();s++){
        
        
        fadeTime[s] = XML.getValue("presetNu:fadeTime", 0, s);
   
        tween[s] = XML.getValue("presetNu:tween", 0, s);
        tweenTime[s] = XML.getValue("presetNu:tweenTime", 0, s);
        _red[s] = XML.getValue("presetNu:_red", 0, s);
        _blue[s] = XML.getValue("presetNu:_blue", 0, s);
        _green[s] = XML.getValue("presetNu:_green", 0, s);
        _active[s] = XML.getValue("presetNu:_active", 0, s);
        _rotRL[s] = XML.getValue("presetNu:_rotRL", 0, s);
        _rotUpDown[s] = XML.getValue("presetNu:_rotUpDown", 0, s);
        _ledPosX[s] = XML.getValue("presetNu:_ledPosX", 0, s);
        _ledPosY[s] = XML.getValue("presetNu:_ledPosY", 0, s);
        __widthLed[s] = XML.getValue("presetNu:__widthLed", 0, s);
         __hightLed[s] = XML.getValue("presetNu:__hightLed", 0, s);
        _RLStop[s] = XML.getValue("presetNu:_RLStop", 0, s);
        _rotUpStop[s] = XML.getValue("presetNu:_rotUpStop", 0, s);
        tempactive[s] = XML.getValue("presetNu:tempactive", 0, s);
        
        
        
    }
    
    
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{ 
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
 
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
 
gui1->setPosition(ofGetWidth()-210, 0);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}