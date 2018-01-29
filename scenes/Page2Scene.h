#pragma once

#include <ofxAppUtils.h>

class Page2Scene : public ofxFadeScene {

public:
	Page2Scene() : ofxFadeScene("Page2Scene") {
		setSingleSetup(false); // call setup each time the scene is loaded
		setFade(1000, 1000); // 1 second fade in/out
	}
	// scene setup
	void setup() {
		camWidth = 320;  // try to grab at this size.
		camHeight = 240;

		//get back a list of devices.
		vector<ofVideoDevice> devices = vidGrabber.listDevices();

		for (int i = 0; i < devices.size(); i++) {
			if (devices[i].bAvailable) {
				//log the device
				ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
			}
			else {
				//log the device and note it as unavailable
				ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
			}
		}

		vidGrabber.setDeviceID(0);
		vidGrabber.setDesiredFrameRate(60);
		vidGrabber.initGrabber(camWidth, camHeight);

		videoInverted.allocate(camWidth, camHeight, OF_PIXELS_RGB);
		//videoTexture.allocate(videoInverted);
		ofSetVerticalSync(true);
	}

	// called when scene is entering, this is just a demo and this
	// implementation is not required for this class
	void updateEnter() {// called on first enter update


		if (isEnteringFirst()) {
			ofLogNotice("Page2Scene") << "update enter 1";
		}

		// fade scene calculates normalized alpha value for us
		ofxFadeScene::updateEnter();

		// finished entering?
		if (!isEntering()) {
			ofLogNotice("Page2Scene") << "update enter done";
		}
	}

	// normal update
	void update() {
		ofBackground(100, 100, 100);
		vidGrabber.update();

		if (vidGrabber.isFrameNew()) {
			ofPixels & pixels = vidGrabber.getPixels();
			for (int i = 0; i < pixels.size(); i++) {
				//invert the color of the pixel
				videoInverted[i] = 255 - pixels[i];
			}
			//load the inverted pixels
			videoTexture.loadData(videoInverted);
		}
	}

	// called when scene is exiting, this is just a demo and this
	// implementation is not required for this class
	void updateExit() {


		vidGrabber.close();

		// called on first exit update
		if (isExitingFirst()) {
			ofLogNotice("Page2Scene") << "update exit";
		}

		// fade scene calculates normalized alpha value for us
		ofxFadeScene::updateExit();

		// finished exiting?
		if (!isExiting()) {
			ofLogNotice("Page2Scene") << "update exit done";
		}
	}

	// draw
	void draw() {
		ofSetHexColor(0xffffff);
		vidGrabber.draw(20, 20);
		videoTexture.draw(20 + camWidth, 20, camWidth, camHeight);
	}

	// cleanup
	void exit() {

		vidGrabber.close();
	}

	void keyPressed(int key) {

		if (key == 's' || key == 'S') {
			vidGrabber.videoSettings();
		}
	}


	// Page2Scene class		
	class Page2SceneClass {

	public:

		Page2SceneClass(int type) {
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




	ofVideoGrabber vidGrabber;
	ofPixels videoInverted;
	ofTexture videoTexture;
	int camWidth;
	int camHeight;
};
