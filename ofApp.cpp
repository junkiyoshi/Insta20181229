#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 240;
	for (int x = span * 0.5; x <= ofGetWidth() - span * 0.5; x += span) {

		for (int y = span * 0.5; y <= ofGetHeight() - span * 0.5; y += span) {

			this->draw_noise_circle(glm::vec2(x, y), span * 0.3);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw_noise_circle(glm::vec2 location, float radius) {

	ofPushMatrix();
	ofTranslate(location);

	float lenght = radius * 0.3;
	for (int deg = 0; deg < 360; deg += 10) {

		glm::vec2 noise_point = location + glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));

		float tmp_radius = radius + ofMap(ofNoise(noise_point.x * 0.015, noise_point.y * 0.015, ofGetFrameNum() * 0.03), 0, 1, -lenght, lenght);
		glm::vec2 start = glm::vec2((tmp_radius - lenght) * cos(deg * DEG_TO_RAD), (tmp_radius - lenght) * sin(deg * DEG_TO_RAD));
		glm::vec2 end = glm::vec2((tmp_radius + lenght) * cos(deg * DEG_TO_RAD), (tmp_radius + lenght) * sin(deg * DEG_TO_RAD));

		ofDrawLine(start, end);
		ofDrawCircle(start, 3);
		ofDrawCircle(end, 3);
	}

	ofPopMatrix();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}