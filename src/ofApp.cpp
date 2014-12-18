#include "ofApp.h"

ofImage image;
ofImage image2;
float zoomFactor;
float radius;
ofVec2f imgPos;
const int numberOfSounds = 10;

int w = image.width;
int h = image.height;


//--------------------------------------------------------------
void ofApp::setup(){

    arraySounds = new ofSoundPlayer[numberOfSounds];
    for(int i=0;i<numberOfSounds;++i){
        arraySounds[i].loadSound("sounds/TheWhole"+ofToString(i+1)+".mp3");
        arraySounds[i].setVolume(0.9f);
    }
    currentSoundIndex = 0;

  ofSetWindowShape(1000, 1000);
    image.loadImage("output_croped.png");
    image.resize(700, 600);
    zoomFactor = 2.0;
    radius = 180;
    imgPos.x = 100;
    imgPos.y = 30;

}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();

    if(arraySounds[currentSoundIndex].getPosition() >= 0.95){
        arraySounds[currentSoundIndex].stop();
        arraySounds[currentSoundIndex].setPosition(0.0f);
        currentSoundIndex++;
        if(currentSoundIndex >= numberOfSounds){
            currentSoundIndex = 0;
        }
        arraySounds[currentSoundIndex].play();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,255,255);

    /* //Another way of zooming
    float zoom = 0.08;
    glPushMatrix();
    glTranslatef(100,50,0);
    glScalef(zoom,zoom,0);
    image.draw(w/8, h/8);
    glPopMatrix();*/

    image.draw(imgPos.x, imgPos.y, image.width, image.height);
    ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());

    ofSetColor(57, 74, 84);
    ofNoFill();
    ofSetLineWidth(10);
    ofSetCircleResolution(500);
    ofCircle(mousePos.x, mousePos.y, radius);

    ofPath magnifierPath;
    ofMesh magnifierMesh;
    magnifierPath.setCircleResolution(100);
    magnifierPath.setFilled(true);
    magnifierPath.circle(mousePos.x, mousePos.y, radius);
    magnifierPath.close();
    magnifierMesh=magnifierPath.getTessellation();

    for (int i=0; i<magnifierMesh.getNumVertices(); i++) {
        ofVec2f vertPos = magnifierMesh.getVertex(i);
        ofVec2f zoomedPos = ((vertPos - mousePos) / zoomFactor) + mousePos;
        ofVec2f uvPos = zoomedPos - imgPos;
        magnifierMesh.addTexCoord(uvPos);
    }


    ofSetColor(255, 255, 255);
    image.bind();
    magnifierMesh.draw();
    image.unbind();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (x >= 300 && x < 400 && y >= 30 && y <130){
        for(int i=0;i<numberOfSounds;++i){
            if(i==0)
                arraySounds[i].play();
            else
                arraySounds[i].stop();

        }
    }
    if (x >= 400 && x < 500 && y >= 30 && y <130){
        for(int i=0;i<numberOfSounds;++i){
            if(i==1)
                arraySounds[i].play();
            else
                arraySounds[i].stop();

        }
    }
    if (x >= 300 && x < 400 && y >= 130 && y <230){
        for(int i=0;i<numberOfSounds;++i){
            if(i==2)
                arraySounds[i].play();
            else
                arraySounds[i].stop();

        }
    }
    if (x >= 500 && x < 600 && y >= 130 && y <230){
        for(int i=0;i<numberOfSounds;++i){
            if(i==3)
                arraySounds[i].play();
            else
                arraySounds[i].stop();

        }
    }
    if (x >= 200 && x < 300 && y >= 230 && y <330){
        for(int i=0;i<numberOfSounds;++i){
            if(i==4)
                arraySounds[i].play();
            else
                arraySounds[i].stop();

        }
    }
     if (x >= 300 && x < 400 && y >= 230 && y <330){
         for(int i=0;i<numberOfSounds;++i){
             if(i==5)
                 arraySounds[i].play();
             else
                 arraySounds[i].stop();

         }
    }
     if (x >= 400 && x < 500 && y >= 230 && y <330){
         for(int i=0;i<numberOfSounds;++i){
             if(i==6)
                 arraySounds[i].play();
             else
                 arraySounds[i].stop();

         }
    }
     if (x >= 500 && x < 600 && y >= 230 && y <330){
         for(int i=0;i<numberOfSounds;++i){
             if(i==7)
                 arraySounds[i].play();
             else
                 arraySounds[i].stop();

         }
    }
     if (x >= 150 && x < 250 && y >= 330 && y <430){
         for(int i=0;i<numberOfSounds;++i){
             if(i==8)
                 arraySounds[i].play();
             else
                 arraySounds[i].stop();

         }
    }
     if (x >= 250 && x < 350 && y >= 430 && y <530){
         for(int i=0;i<numberOfSounds;++i){
             if(i==9)
                 arraySounds[i].play();
             else
                 arraySounds[i].stop();

         }
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
