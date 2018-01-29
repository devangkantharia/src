#pragma once

#include <ofxAppUtils.h>

class Page1Scene : public ofxFadeScene {

public:
	Page1Scene() : ofxFadeScene("Page1Scene") {
		setSingleSetup(false); // call setup each time the scene is loaded
		setFade(1000, 1000); // 1 second fade in/out
	}
	// scene setup
	void setup() {
		ofTrueTypeFont::setGlobalDpi(72);
		verdana30.load("verdana.ttf", 30, true, true);
		verdana30.setLineHeight(34.0f);
		verdana30.setLetterSpacing(1.035);

		dir.listDir("videos/bgVideos");
		dir.allowExt("mov");
		dir.sort(); // in linux the file system doesn't return file lists ordered in alphabetical order

					//allocate the vector to have as many ofImages as files
		if (dir.size()) {
			videos.assign(dir.size(), ofVideoPlayer());
		}

		// you can now iterate through the files and load them into the ofImage vector
		for (int i = 0; i < (int)dir.size(); i++) {
			videos[i].load(dir.getPath(i));
		}
		currentVideo = 0;

		ofBackground(ofColor::lightBlue);
	}

	// called when scene is entering, this is just a demo and this
	// implementation is not required for this class
	void updateEnter() {// called on first enter update
		ofBackground(ofColor::lightBlue);
		if (isEnteringFirst()) {
			ofLogNotice("Page1Scene") << "update enter";
		}

		// fade scene calculates normalized alpha value for us
		ofxFadeScene::updateEnter();

		// finished entering?
		if (!isEntering()) {
			ofLogNotice("Page1Scene") << "update enter done";
		}

		videos[currentVideo].draw(300, 50, 200, 200);
		videos[currentVideo].play();
	}

	// normal update
	void update() {
		videos[currentVideo].update();
	}

	// called when scene is exiting, this is just a demo and this
	// implementation is not required for this class
	void updateExit() {

		// called on first exit update
		if (isExitingFirst()) {
			ofLogNotice("Page1Scene") << "update exit";
		}

		// fade scene calculates normalized alpha value for us
		ofxFadeScene::updateExit();

		// finished exiting?
		if (!isExiting()) {
			ofLogNotice("Page1Scene") << "update exit done";
		}
	}

	// draw
	void draw() {
		
		ofSetColor(29, 29, 29);
		//ofDrawLine(30, 169, ofGetWidth() - 4, 169);

		ofSetColor(225);
		verdana30.drawString("Select Background Template", 80, 50);



		if (dir.size() > 0) {
			ofSetColor(ofColor::white);

			videos[currentVideo].draw(300, 50, 200, 200);


			ofSetColor(ofColor::gray);
			string pathInfo = dir.getName(currentVideo) + " " + dir.getPath(currentVideo) + "\n\n" +
				"Press I to change \n\n" +
				"video";
			ofDrawBitmapString(pathInfo, 300, videos[currentVideo].getHeight() + 80);



		}

		ofSetColor(ofColor::gray);
		for (int i = 0; i < (int)dir.size(); i++) {
			if (i == currentVideo) {
				ofSetColor(ofColor::red);
			}
			else {
				ofSetColor(ofColor::black);
			}
			string fileInfo = "file " + ofToString(i + 1) + " = " + dir.getName(i);
			ofDrawBitmapString(fileInfo, 50, i * 20 + 50);
		}
	}

	// cleanup
	void exit() {
	}

	void keyPressed(int key) {
		switch (key)
		{
		case '[':

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
	}


	// Page1Scene class		
	class Page1SceneClass {

	public:

		Page1SceneClass(int type) {
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


	// we will have a dynamic number of videos, based on the content of a directory:
	ofDirectory dir;
	vector<ofVideoPlayer> videos;

	int currentVideo;
	ofTrueTypeFont	verdana30;
};
