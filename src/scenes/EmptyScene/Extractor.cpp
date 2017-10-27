#include "Extractor.h"

void Extractor::setup() {
  cout << "Start scene setup: " << getName() << endl;
  mEx.setup(this);
  cout << "Done scene setup: " << getName() << endl;
}

void Extractor::update() {
	mEx.update();
}

void Extractor::draw() {
  
  rdtk::BeginCamera(); {
    //! Debug preview
    mEx.draw();
    
    for (int i = 0;i < mEx.getNumPort();i++) {
      //! Get extractor informations
      const ofMatrix4x4 mat = mEx.getNodeAt(i).getGlobalTransformMatrix();
      const ofVec3f pos = mEx.getPositionAt(i);
      const ofVec3f next = mEx.getPositionAt((i+1) % mEx.getNumPort());
      const ofVec3f vel = mEx.getVelocityAt(i);
      
      
      //! Draw Primitives
      ofPushMatrix(); {
        ofMultMatrix(mat);
        
        ofSetColor(255);
        ofDrawBox(0, 0, 0, vel.length() * 10.0);
        ofNoFill();
        ofSetColor(0);
        ofDrawBox(0, 0, 0, vel.length() * 11.0);
        ofFill();
      } ofPopMatrix();
      
      ofSetColor(0, 255, 150);
      ofDrawLine(pos, next);
    }
  } rdtk::EndCamera();
}

void Extractor::drawImGui()
{
	mEx.drawImGui();
}
