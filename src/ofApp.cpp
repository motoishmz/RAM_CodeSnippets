#include "ofApp.h"
#include "Extractor.h"
#include "CameraMove.h"

#pragma mark - oF methods
//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	
	//! ram setup
	rdtk::Initialize(10000, true);
  
  
  //! scenes setup
  rdtk::SceneManager& sceneManager = rdtk::SceneManager::instance();
  sceneManager.addScene<Extractor>();
  sceneManager.addScene<CameraMove>();
}

//--------------------------------------------------------------
void ofApp::update() {
	
}

//--------------------------------------------------------------
void ofApp::draw() {
	
}



#pragma mark - ram methods
//--------------------------------------------------------------
void ofApp::drawActor(const rdtk::Actor &actor) {
}

//--------------------------------------------------------------
void ofApp::drawRigid(const rdtk::RigidBody &rigid) {
	
}

#pragma mark - ram Events

//--------------------------------------------------------------
void ofApp::onActorSetup(const rdtk::Actor &actor) {
	cout << "[ofApp::onActorSetup] called with an actor - " << actor.getName() << endl;
  
  //! example: rdtk::SceneManager
  const int numScenes = rdtk::SceneManager::instance().getNumScenes();
  for (int i=0; i<numScenes; i++) {
    auto scene = rdtk::SceneManager::instance().getScene(i);
    if (scene->isEnabled()) {
      // setup again if the scene is enabled
      scene->setup();
    }
  }
  
  //! example: rdtk::ActorManager
  // we don't have getNumActors() in ActorManager because we originally use both "bvh formated human body" and "rigidbody", and they both are treated as an `nodearray`. you can fetch Actors from nodearray with the hook `isActor()`
  const int numNodeArray = rdtk::ActorManager::instance().getNumNodeArray();
  for (int i=0; i<numNodeArray; i++) {
    auto & nodeArray = rdtk::ActorManager::instance().getNodeArray(i);
    if (nodeArray.isActor()) {
      // do something here
    }
  }
  
//  // or you can get spesific Actor by name which is defined in Perception Neuron Axis
//  const std::string theActorName = "Clarence";
//  auto & clarence = rdtk::ActorManager::instance().getNodeArray(theActorName);
//  assert(clarence.isActor());
}

//--------------------------------------------------------------
void ofApp::onActorExit(const rdtk::Actor &actor) {
  cout << "Actor [" << actor.getName() << "] exit" << endl;
}

//--------------------------------------------------------------
void ofApp::onRigidSetup(const rdtk::RigidBody &rigid) {
  // in RAMCAMP2017, we don't take RigidBody with Perception Neuron Axis
}

//--------------------------------------------------------------
void ofApp::onRigidExit(const rdtk::RigidBody &rigid) {
  // in RAMCAMP2017, we don't take RigidBody with Perception Neuron Axis
}



#pragma mark - of Event
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  if (key == 'e') {
    // enable all scenes
    const int numScenes = rdtk::SceneManager::instance().getNumScenes();
    for (int i=0; i<numScenes; i++) {
      auto scene = rdtk::SceneManager::instance().getScene(i);
      scene->enable();
    }
  }
  
  else if (key == 'd') {
    // disable all scenes
    const int numScenes = rdtk::SceneManager::instance().getNumScenes();
    for (int i=0; i<numScenes; i++) {
      auto scene = rdtk::SceneManager::instance().getScene(i);
      scene->disable();
    }
  }
  
  else if ('s') {
    // enable scene 1, 2 if they are exists
    // note that the scene named `Actors` is built-in 0th scene, the first scene you add to rdtk::SceneManager is the 1th scene
    // in this example, `EmptyScene` and `CameraMove` will be enabled when you pressed [s] key
    // if you want to disable specific scenes, replace `enable` to `disable` in the lambda named `applyToSceneManager`
    std::vector<int> combination = {1, 2};
    
    auto applyToSceneManager = [](int i){
      const int numScene = rdtk::SceneManager::instance().getNumScenes();
      if (i >= numScene) {
        return;
      }
      
      auto scene = rdtk::SceneManager::instance().getScene(i);
      if (scene) {
        scene->enable(); // <--
      }
    };
    
    std::for_each(combination.begin(),
                  combination.end(),
                  applyToSceneManager);
    
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
	
}
