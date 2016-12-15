#include "ofApp.h"
#include "ofAppRunner.h"

//--------------------------------------------------------------
void ofApp::setup(){
	pelota.init();
	player.init();
	enemy.init();
	//bounceSound.loadSound("Golpe.mp3");
	pongFont.loadFont("8-BIT WONDER.ttf", 20, true, false);
	maxScore = 10;
	playerPts = 0;
	enemyPts = 0;
	gameOver = false;
	pause = true;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (!pause) {
		pelota.update();
		player.limites();
		enemy.update(pelota);
		testPlayerCollision();
		testPlayerCollision2();
		evaluateScore();
		
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(100, 100, 100);
	pelota.draw();
	player.draw();
	enemy.draw();
	displayScore();
	displayResults();
}

void ofApp::evaluateScore(){
	// Revisa colisión contra borde derecho
	if (pelota.x + pelota.radius > ofGetWidth()) {
		playerPts++;
		resetBallPosition();
		pause = true;
	}
	// Revisa colisión contra borde izquierdo
	else if (pelota.x - pelota.radius < 0) {
		enemyPts++;
		resetBallPosition();
		pause = true;
	}
	// Contador
	if (enemyPts > maxScore || playerPts > maxScore) {
		gameOver = true;
		pause = true;
	}
}

//--------------------------------------------------------------
void ofApp::testPlayerCollision(){
	// Validar si la rapidez en x de la pelota es negativa
	if (pelota.speedX < 0) {
		if (player.y <= pelota.y + pelota.radius) {
			if (player.y + player.height >= pelota.y - pelota.radius) {
				if (player.x + player.width > pelota.x - pelota.radius) {
					// Colision
					pelota.speedX *= -1;
					//pelota.speedX++;
					bounceSound.play();
				}
			}
		}
	}
}

void ofApp::testPlayerCollision2() {
	// Colisión con enemigo
	if (pelota.speedX > 0) {
		if (enemy.y <= pelota.y + pelota.radius) {
			if (enemy.y + enemy.height >= pelota.y - pelota.radius) {
				if (enemy.x < pelota.x + pelota.radius) {
					if (enemy.x + enemy.width > pelota.x + pelota.radius) {
						// Colision
						pelota.x = enemy.x - pelota.radius;
						pelota.speedX *= -1;
					//	pelota.speedX--;
						bounceSound.play();
					}
				}
			}
		}
	}
}

void ofApp::resetBallPosition(){
	pelota.setPosition(ofGetWidth() / 2, ofGetHeight() / 2);
}

void ofApp::displayScore(){
	ofSetColor(255);
	string score = "                        Player:" + ofToString(playerPts) + "" + "  Enemy:" + ofToString(enemyPts);
	pongFont.drawString(score, 0, 32);
}

void ofApp::displayResults(){
	if (gameOver) {
		if (playerPts > enemyPts) {
			pongFont.drawString("Ganaste", ofGetWidth() / 2 - 50, ofGetHeight() / 2);
		}
		else {
			pongFont.drawString("Perdiste", ofGetWidth() / 2 - 50, ofGetHeight() / 2);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'w') {
		player.moveUp();
	}
	if (key == 's') {
		player.moveDown();
	}
	if (key == 'i') {
		enemy.moveUp();
	}
	if (key == 'k') {
		enemy.moveDown();
	}
	if (key == 'p') {
		pause = false;
		if (gameOver) {
			playerPts = 0;
			enemyPts = 0;
		}
	}
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
