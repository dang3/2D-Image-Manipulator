#pragma once

#include "ofMain.h"
#include "Image.h"
#include "Frame.h"
#include "Utils.h"


class ofApp : public ofBaseApp{
	private:
		Frame frame;
		bool bScale = false;
		bool bTranslate = false;
		glm::vec3 mousePressedLocation;

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		vector<Image> images;
		ofImage image;
		bool bImageLoaded = false;
		bool bImageSelected = false;
		ofRectangle selectionRect;
		Image *selectedImg;
		void swap(Image&, Image&);
		void deleteSelectedImage();

	private:
		bool isInsideImage(glm::vec3 point);
		void moveImageUpStack();
		void moveImageDownStack();

		int count = 0; // used to identify where image is placed in vector
		glm::vec3 lastMouse;
		void swapImages(int, int);
		int index = 0;

};

