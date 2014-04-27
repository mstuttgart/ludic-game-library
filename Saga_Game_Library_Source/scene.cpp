#include "scene.h"

using namespace sgl;

//---------------------------------------------

Scene::Scene() : exitLoop( false ) {}

//--------------------------------------------

Scene::~Scene() {}

//--------------------------------------------

void Scene::setExitLoop(bool exitLoop) {
	this->exitLoop = exitLoop;
}

//---------------------------------------------

bool Scene::isExitLoop() const {
	return exitLoop;
}

//---------------------------------------------