#ifndef TESTAPP
#define TESTAPP

#include "ofMain.h"
#include "ofxUI.h"
#include "ofxTweener.h"
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
	ofxUISuperCanvas *gui;
 	ofxUISuperCanvas  *gui1;
	void guiEvent(ofxUIEventArgs &e);
    bool drawPadding;
    
    int red;
    int blue;
    int green;
    int redTween;
    int blueTween;
    int greenTween;
    
    
    bool rotRL;
    bool rotUpDown;
    int _widthLed;
    int _hightLed;
    int ledPosX;
    int ledPosY;
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

    
//    int guiPoistionXLive;
//    int guiPoistionYLive;
//    
    
    
    
};

#endif