#include "CameraMove.h"

void CameraMove::setup() {
}

void CameraMove::update() {
  if (ofGetFrameNum() % 90 == 0) {
    target.x = ofRandom(-size * 2, size * 2);
    target.y = ofRandom(-size * 2, size * 2);
    target.z = ofRandom(-size * 2, size * 2);
  }
  
  auto & cam = rdtk::CameraManager::instance().getActiveCamera();
  const float lowpass = 0.05f;
  const ofVec3f new_eye_pos = (target * lowpass) + (cam.getPosition() * (1.f - lowpass));
  cam.setPosition(new_eye_pos);
  cam.lookAt(ofVec3f::zero());
}

void CameraMove::draw() {
  
  rdtk::BeginCamera(); {
    const int numSpheres = 10;
    const float time = ofGetElapsedTimef() * 0.4;
    auto & cam = rdtk::CameraManager::instance().getActiveCamera();
    cam.begin(); {
      ofDrawAxis(100);
      for (int i=0; i<numSpheres; i++) {
        ofPoint p;
        p.x = ofSignedNoise(i, 0, 0, time) * size;
        p.y = ofSignedNoise(0, i, 0, time) * size;
        p.z = ofSignedNoise(0, 0, i, time) * size;
        ofDrawSphere(p, 10);
      }
      
      ofNoFill();
      ofDrawBox(0, 0, 0, size * 2);
    } cam.end();

  } rdtk::EndCamera();
}

void CameraMove::drawImGui()
{
}
