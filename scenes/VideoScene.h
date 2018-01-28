#pragma once

#include <ofxAppUtils.h>

class VideoScene : public ofxFadeScene {

public:
	VideoScene() : ofxFadeScene("VideoScene") {
		setSingleSetup(false); // call setup each time the scene is loaded
		setFade(1000, 1000); // 1 second fade in/out
	}
	// scene setup
	void setup() {
		video.load("video/elephant.mov");
	}

	// called when scene is entering, this is just a demo and this
	// implementation is not required for this class
	void updateEnter() {// called on first enter update
		if (isEnteringFirst()) {
			ofLogNotice("VideoScene") << "update enter";
		}

		// fade scene calculates normalized alpha value for us
		ofxFadeScene::updateEnter();

		// finished entering?
		if (!isEntering()) {
			ofLogNotice("VideoScene") << "update enter done";
		}
	}

	// normal update
	void update() {
		video.update();
	}

	// called when scene is exiting, this is just a demo and this
	// implementation is not required for this class
	void updateExit() {

		// called on first exit update
		if (isExitingFirst()) {
			ofLogNotice("VideoScene") << "update exit";
		}

		// fade scene calculates normalized alpha value for us
		ofxFadeScene::updateExit();

		// finished exiting?
		if (!isExiting()) {
			ofLogNotice("VideoScene") << "update exit done";
		}
	}

	// draw
	void draw() {
		//ofEnableAlphaBlending();
		video.draw(0, 0);
	}

	// cleanup
	void exit() {
		video.close();
	}

	void keyPressed(int key) {
		switch (key)
		{
		case 'j':
			video.play();
			break;

		case OF_KEY_LEFT:
			video.previousFrame();
			break;

		case OF_KEY_RIGHT:
			video.nextFrame();
			break;

		case 'k':
			video.stop();
			break;

		default:
			break;
		}
	}


	// VideoScene class		
	class VideoSceneClass {

	public:

		VideoSceneClass(int type) {
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

	/*
	// lines
	vector<VideoSceneClass*> VideoSceneclasses;
	*/
	ofVideoPlayer video;
};
