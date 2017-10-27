#pragma once
#include "ramMain.h"

class CameraMove : public rdtk::BaseScene {
  
public:
  
  CameraMove()
  : size(1000.f)
  {}
  
  //! You must define `getName` to show your scene name in GUI
  std::string getName() const { return "CameraMove"; }
	
  //! Drive your scene with OF event hooks
  void setup();
  void update();
  void draw();
	
  //! For drawing GUI, define `drawImGui()`
  void drawImGui();
  
private:
  
  ofVec3f target;
  float size;
};
