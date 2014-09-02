#include "ofApp.h"

int ledNumberStrip = 60;
int numberOf = 20;
//--------------------------------------------------------------
void ofApp::setup(){
    
    end = 1; // tweener end
    numberOf = 9;

    for(int x = 0;x<numberOf;x++){
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
        _active.push_back(1);
        _rotRL.push_back(1);
        _rotUpDown.push_back(1);
        __widthLed.push_back(20);
        __hightLed.push_back(ledNumberStrip);
        _ledPosX.push_back(numberOf);
        _ledPosY.push_back(ledNumberStrip);
        __widthLedTween.push_back(numberOf);
        __hightLedTween.push_back(ledNumberStrip);
        _ledPosXTween.push_back(numberOf);
        _ledPosYTween.push_back(ledNumberStrip);
        _rotRLTween.push_back(1);
        _rotUpDownTween.push_back(1);
        
    }

    

    
    gui  = new ofxUISuperCanvas("Live ", OFX_UI_FONT_MEDIUM);
    gui1 = new ofxUISuperCanvas("Preset", OFX_UI_FONT_MEDIUM);
       gui1->addSpacer();
    gui->setGlobalButtonDimension(24);
    gui1->setGlobalButtonDimension(24);

    gui->addSpacer();
    gui->addToggleMatrix("select Color", 3, 3);

    ofxUIToggleMatrix* mtx = (ofxUIToggleMatrix *) gui->getWidget("select Color");
    mtx->setAllowMultiple(false); 

    gui->addSpacer();
    gui->addToggle("Active", &active, 30, 30);
    gui->addLabel("color");
	gui->addIntSlider("RED", 0, 255, &red)->setTriggerType(OFX_UI_TRIGGER_ALL);
	gui->addIntSlider("GREEN", 0, 255, &green)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE|OFX_UI_TRIGGER_END);
	gui->addIntSlider("BLUE", 0, 255, &blue)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
    
    gui->addSlider("fade", 0, 255, &fade)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
    gui->addLabel("direction / auto change");
    gui->addToggleMatrix("direction", 1,4);
    ofxUIToggleMatrix* direction = (ofxUIToggleMatrix *) gui->getWidget("direction");
    direction->setAllowMultiple(true);
    
    gui->setDrawWidgetPadding(drawPadding);
    gui->addIntSlider("width of light", 0, numberOf, &_widthLed)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
    gui->addIntSlider("hieght of light", 0, ledNumberStrip, &_hightLed)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
    gui->addIntSlider("ledPosX", 0, numberOf, &ledPosX)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
    gui->addIntSlider("ledPosY", 0, ledNumberStrip, &ledPosY)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);


    
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
    
    
    
    gui1->addLabel("direction / auto change");
    gui1->addToggleMatrix("directionTeen", 1,4);
    ofxUIToggleMatrix* directionTween = (ofxUIToggleMatrix *) gui1->getWidget("directionTween");
    direction->setAllowMultiple(true);
    
    gui1->setDrawWidgetPadding(drawPadding);
    gui1->addIntSlider("width of light", 0, numberOf, &_widthLedTween)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
    gui1->addIntSlider("hieght of light", 0, ledNumberStrip, &_hightLedTween)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
    gui1->addIntSlider("ledPosX", 0, numberOf, &ledPosXTween)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
    gui1->addIntSlider("ledPosY", 0, ledNumberStrip, &ledPosYTween)->setTriggerType(OFX_UI_TRIGGER_BEGIN|OFX_UI_TRIGGER_CHANGE);
    
    

    gui1->autoSizeToFitWidgets();

    gui1->setDrawWidgetPadding(drawPadding);
    ofAddListener(gui->newGUIEvent,this,&ofApp::guiEvent);
     ofAddListener(gui1->newGUIEvent,this,&ofApp::guiEvent);
    gui->setPosition(0, 0);
    gui1->setPosition(220, 0);
    
  
}




//--------------------------------------------------------------
void ofApp::update(){
    Tweener.update();
    updatePresetActive();
}


void ofApp::updatePresetActive(){

      //  _active[presetActive] = active;
    
    
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
       _tweenTime[presetActiveTween] = _fadeTime ;
        
        
        
    }
    

    
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(red, green, blue);
    ofRect(0, ofGetHeight()-80,80,80);
    
    ofSetColor(redTween, greenTween, blueTween);
    ofRect(90,ofGetHeight()-80,80,80);
    
    
    for(int x = 0; x < _red.size();x++){
        
        ofSetColor(_red[x], _green[x], _blue[x]);
        ofRect(ofGetWidth()-80,x *80,80,80);
    }
    
    

 //  cout << ofGetMouseX() << " " <<  ofGetMouseY() << endl;

}
//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName(); 
	int kind = e.widget->getKind(); 
    
    if(kind == OFX_UI_WIDGET_TOGGLE){
        cout << name << endl;
        
        
        vector<string> _name = ofSplitString(name, " ");
               ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        if(_name[0] == "select"){
        
        //if(name == "select Color"){
 
       
        presetActive = ((int)(toggle->getID()/2)-1);
        red = _red[presetActive];
        blue = _blue[presetActive];
        green = _green[presetActive];
        fade = fadeTime[presetActive];
        active = _active[presetActive];
            
            rotRL = _rotRL[presetActive];
            rotUpDown = _rotUpDown[presetActive];
            _widthLed = __widthLed[presetActive];
             _hightLed = __hightLed[presetActive];
             ledPosX = _ledPosX[presetActive];
             ledPosY = _ledPosY[presetActive];


            
            
            
            
        }
        else if (_name[0] == "Active"){
            _active[presetActive] =active;
            
        }
        
        else if (_name[0] == "Tween"){
      presetActiveTween =  ((int)(toggle->getID()/2)-1);
            
            
          redTween =   _redTween[presetActiveTween];
          blueTween =   _blueTween[presetActiveTween];
         greenTween =    _greenTween[presetActiveTween];
            _fadeTime = _tweenTime[presetActiveTween];
            
            
            rotRLTween = _rotRLTween[presetActiveTween];
            rotUpDownTween = _rotUpDownTween[presetActiveTween];
            _widthLedTween = __widthLedTween[presetActiveTween];
            _hightLedTween = __hightLedTween[presetActiveTween];
            ledPosXTween = _ledPosXTween[presetActiveTween];
            ledPosYTween = _ledPosYTween[presetActiveTween];
            
            
        }
 
//        if( toggle->getID() == 22){
//
//        }else{
//
//        }

    }
    
    
    
     if(kind == OFX_UI_WIDGET_TOGGLE){
           cout << " problems!" << " " << active << endl;
         

     }
    
    
    if(kind == OFX_UI_WIDGET_BUTTON){
      
        ofxUIButton *button = (ofxUIButton *) e.widget;
        end = 1;
        tween[presetActive] = 0;
        Tweener.addTween(tween[presetActive], end, _tween);
    }
    
   
    if((kind == 4)||(kind == 42)){ // sliders

        
        
        _red[presetActive] = red;
        _blue[presetActive] = blue;
        _green[presetActive] = green;
        
        _redTween[presetActiveTween] = redTween;
        _blueTween[presetActiveTween] =blueTween;
        _greenTween[presetActiveTween] =  greenTween ;
        _tweenTime[presetActiveTween] = _fadeTime ;
        
        __widthLed[presetActive] = _widthLed;
        __hightLed[presetActive] = _hightLed;
        _ledPosX[presetActive] =ledPosX;
        _ledPosY[presetActive] = ledPosY ;
        
        _rotRLTween[presetActiveTween] = rotRLTween ;
        _rotUpDownTween[presetActiveTween] = rotUpDownTween ;
        __widthLedTween[presetActiveTween] =  _widthLedTween ;
        __hightLedTween[presetActiveTween] = _hightLedTween ;
        _ledPosXTween[presetActiveTween] =  ledPosXTween ;
        _ledPosYTween[presetActiveTween] =  ledPosYTween ;
        
    }
    
    if(kind == 3){ /// buttons
        _rotRL[presetActive] =rotRL;
        _rotUpDown[presetActive] = rotUpDown;
        
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
 

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}