#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "Player.h"
#include "Enemy.h"

class ofApp : public ofBaseApp{

	public:
		Ball pelota;
		Enemy enemy;
		Player player;

		ofSoundPlayer bounceSound;
		ofTrueTypeFont pongFont;

		void setup();
		void update();
		void draw();

		int enemyPts;
		int playerPts;
		int maxScore;
		bool pause;
		bool gameOver;

		void evaluateScore();
		void testPlayerCollision();
		void testPlayerCollision2();
		void resetBallPosition();
		void displayResults();
		void displayScore();

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
		
};
