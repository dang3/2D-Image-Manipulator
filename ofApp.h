#pragma once

#include "ofMain.h"

class Image {
	public:
		ofImage img;
		float imageWidth;
		float imageHeight;
		glm::vec3 imagePosition;
		glm::vec3 imageCenter;
		void calculateImageCenter();

	
		Image();
		Image(ofImage img, float imageWidth, float imageHeight, 
			  glm::vec3 imagePosition, int position);
		float getImageWidth();
		float getImageHeight();
		void setPosition(int);
		void setImagePosition(glm::vec3);
		int getPosition();
		void draw();

		int position;

		// Not sure if these will be necessary
		glm::vec3 getImagePosition();
		glm::vec3 getImageCenter();
};

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
		void drawSelectionRect();
		bool isInsideImage(glm::vec3 point);
		void moveSelectedImageUp();
		void moveSelectedImageDown();

		int count = 0; // used to identify where image is placed in vector
		bool bDrag = false;
		glm::vec3 lastMouse;
};
