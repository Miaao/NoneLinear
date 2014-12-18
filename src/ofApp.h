#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    int currentSoundIndex;

/*		ofSoundPlayer  synth1;
		ofSoundPlayer  synth2;
		ofSoundPlayer  synth3;
		ofSoundPlayer  synth4;
		ofSoundPlayer  synth5;
		ofSoundPlayer  synth6;
		ofSoundPlayer  synth7;
		ofSoundPlayer  synth8;
		ofSoundPlayer  synth9;
		ofSoundPlayer  synth10;*/
        ofSoundPlayer* arraySounds;
    
};
