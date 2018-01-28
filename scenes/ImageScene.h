#pragma once

#include <ofxAppUtils.h>

class ImageScene : public ofxFadeScene {

public:
	ImageScene() : ofxFadeScene("ImageScene") {
		setSingleSetup(false); // call setup each time the scene is loaded
		setFade(1000, 1000); // 1 second fade in/out
	}
	// scene setup
	void setup() {
		image.load("images/example.png");
	}

	// called when scene is entering, this is just a demo and this
	// implementation is not required for this class
	void updateEnter() {// called on first enter update
		if (isEnteringFirst()) {
			ofLogNotice("ImageScene") << "update enter";
		}

		// fade scene calculates normalized alpha value for us
		ofxFadeScene::updateEnter();

		// finished entering?
		if (!isEntering()) {
			ofLogNotice("ImageScene") << "update enter done";
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
			ofLogNotice("ImageScene") << "update exit";
		}

		// fade scene calculates normalized alpha value for us
		ofxFadeScene::updateExit();

		// finished exiting?
		if (!isExiting()) {
			ofLogNotice("ImageScene") << "update exit done";
		}
	}

	// draw
	void draw() {
		//ofEnableAlphaBlending();
		image.draw(10, 100);
	}

	// cleanup
	void exit() {
		image.clear();
	}

	// ImageScene class		
	class ImageSceneClass {

	public:

		ImageSceneClass(int type) {
			this->type = (Type) type;
		}

		void update() {

		}

		void draw() {
			
		}

		enum Type {
		};
		int type;

	};

	/*
	// lines
	vector<ImageSceneClass*> ImageSceneclasses;
	*/
	ofImage image;
};
