#pragma once

#include <ofxAppUtils.h>

class IntroPageScene : public ofxFadeScene {

public:
	IntroPageScene() : ofxFadeScene("IntroPageScene") {
		setSingleSetup(false); // call setup each time the scene is loaded
		setFade(1000, 1000); // 1 second fade in/out
	}
	// scene setup
	void setup() {
		ofBackground(54, 54, 54, 255);

		//old OF default is 96 - but this results in fonts looking larger than in other programs. 
		ofTrueTypeFont::setGlobalDpi(72);

		verdana14.load("verdana.ttf", 14, true, true);
		verdana14.setLineHeight(18.0f);
		verdana14.setLetterSpacing(1.037);

		verdana30.load("verdana.ttf", 30, true, true);
		verdana30.setLineHeight(34.0f);
		verdana30.setLetterSpacing(1.035);

		verdana14A.load("verdana.ttf", 14, false);
		verdana14A.setLineHeight(18.0f);
		verdana14A.setLetterSpacing(1.037);

		franklinBook14.load("frabk.ttf", 14);
		franklinBook14.setLineHeight(18.0f);
		franklinBook14.setLetterSpacing(1.037);

		franklinBook14A.load("frabk.ttf", 14, false);
		franklinBook14A.setLineHeight(18.0f);
		franklinBook14A.setLetterSpacing(1.037);

	}

	// called when scene is entering, this is just a demo and this
	// implementation is not required for this class
	void updateEnter() {// called on first enter update
		if (isEnteringFirst()) {
			ofLogNotice("IntroPageScene") << "update enter";
		}

		// fade scene calculates normalized alpha value for us
		ofxFadeScene::updateEnter();

		// finished entering?
		if (!isEntering()) {
			ofLogNotice("IntroPageScene") << "update enter done";
		}
	}

	// normal update
	void update() {
	}

	// called when scene is exiting, this is just a demo and this
	// implementation is not required for this class
	void updateExit() {

		// called on first exit update
		if (isExitingFirst()) {
			ofLogNotice("IntroPageScene") << "update exit";
		}

		// fade scene calculates normalized alpha value for us
		ofxFadeScene::updateExit();

		// finished exiting?
		if (!isExiting()) {
			ofLogNotice("IntroPageScene") << "update exit done";
		}
	}

	// draw
	void draw() {


		ofSetColor(29, 29, 29);
		//ofDrawLine(30, 169, ofGetWidth() - 4, 169);

		ofSetColor(225);
		verdana30.drawString("Welcome", 220, 150);
		verdana30.drawString("To", 270, 200);
		verdana30.drawString("Green Screen VFX", 150, 250);

	}

	// cleanup
	void exit() {
	}

	void keyPressed(int key) {

		/*if (key == OF_KEY_DEL || key == OF_KEY_BACKSPACE) {
			typeStr = typeStr.substr(0, typeStr.length() - 1);
		}
		else if (key == OF_KEY_RETURN) {
			typeStr += "\n";
		}
		else {
			if (bFirst) {
				typeStr.clear();
				bFirst = false;
			}
			ofAppendUTF8(typeStr, key);
		}*/
	}


	/*void keyPressed(int key) {
		switch (key)
		{
		case '1':

			if (dir.size() > 0) {
				currentVideo++;
				currentVideo %= dir.size();
				videos[currentVideo].load(dir.getPath(currentVideo));
				videos[currentVideo].play();
				std::cout << dir.getPath(currentVideo);
			}

			break;

		case ']':

			if (dir.size() > 0) {
				currentVideo--;
				currentVideo %= dir.size();
				videos[currentVideo].load(dir.getPath(currentVideo));
				videos[currentVideo].play();
				std::cout << dir.getPath(currentVideo);
			}

			break;


		default:
			break;
		}
	}*/


	// IntroPageScene class		
	class IntroPageSceneClass {

	public:

		IntroPageSceneClass(int type) {
			this->type = (Type)type;
		}

		void update() {

		}

		void draw() {

		}

		enum Type {
		};
		int type;

	};

	//bool bFirst;
	string typeStr;

	ofTrueTypeFont  franklinBook14;
	ofTrueTypeFont	verdana14;
	ofTrueTypeFont	verdana30;

	ofTrueTypeFont  franklinBook14A;
	ofTrueTypeFont	verdana14A;

};
