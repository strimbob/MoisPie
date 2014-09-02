#ifndef TESTAPP
#define TESTAPP

#include "ofMain.h"
#include "ofxUI.h"
#include "ofxTweener.h"
#include "ofxXmlSettings.h"
#include "ofxTeensyOcto.h"
class ofApp : public ofBaseApp 
{
	public:
	void setup();
	void update();
	void draw();
	void exit(); 

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	void updatePresetActive();
    
    int poistionLed(bool onOff,int _poistion,int _lenght,int totalLed,bool direation);
    int clampVals(int x,int totalLed,int length,int clamped );
    
    
    void updateFbo();
  //  void exit();
    
    void save();
    void load();
	ofxUISuperCanvas *gui;
 	ofxUISuperCanvas  *gui1;
	void guiEvent(ofxUIEventArgs &e);
    bool drawPadding;
    
    bool liveSave;
    bool liveLoad;
    
    int red;
    int blue;
    int green;
    int redTween;
    int blueTween;
    int greenTween;
    
    
    bool rotRL;
    bool rotUpDown;
    float _widthLed;
    float _hightLed;
    float ledPosX;
    float ledPosY;
    int _widthLedTween;
    int _hightLedTween;
    int ledPosXTween;
    int ledPosYTween;
    bool rotRLTween;
    bool rotUpDownTween;
    
    
    
    vector<bool> _rotRL;
    vector<bool> _rotUpDown;
    vector<int> __widthLed;
    vector<int> __hightLed;
    vector<int> _ledPosX;
    vector<int> _ledPosY;
    vector<int> __widthLedTween;
    vector<int> __hightLedTween;
    vector<int> _ledPosXTween;
    vector<int> _ledPosYTween;
    vector<bool> _rotRLTween;
    vector<bool> _rotUpDownTween;
    
    
    vector<int> _red;
    vector<int> _blue;
    vector<int> _green;
    vector<int> _redTween;
    vector<int> _blueTween;
    vector<int> _greenTween;
    vector <float> _tweenTime;
    
    
    
  vector<bool>  _RLStop;
  vector<bool>  _rotUpStop;
    
    
   vector<bool> pingPongUpDown;
   vector<bool> pingPongLeftRight;
    
      vector<bool>  tempactive;
    
    ofColor rgb;
    ofColor rgbTween;

    
    int presetActive;
    int presetActiveTween;
    vector <float> tween;
    vector <float> tweenTime;
    
    vector <bool > _active;
    bool active;
    float end;
    float _tween;
    vector <float> fadeTime;
    float fade;
    float _fadeTime;
    float shapeTween;
    
//    int guiPoistionXLive;
//    int guiPoistionYLive;
//    
//    ofxUISuperCanvas *gui;
//    ofxUISuperCanvas *gui1;
    ofxUISuperCanvas *gui2;
    
    ofMesh mesh;
    ofVboMesh vbo;
    
    ofEasyCam cam;
    vector <  vector< vector<ofColor > > > colorFor;
    vector  < vector  < ofVec3f > > leds;
    vector  < vector  < ofVec3f   > > ledsFactored;
    vector< vector<ofColor > > color;
    vector< vector<  ofVec3f  > >ledsSquare;
    
     ofxUIDropDownList *ddl;
    
    bool UpDownstartStop;
    bool leftRightstartStop;
    
        ofxTeensyOcto teensy;
       ofFbo fbo;
};

#endif