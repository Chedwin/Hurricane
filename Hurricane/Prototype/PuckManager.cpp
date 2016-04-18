#include <Debug.h>
#include "PuckManager.h"
using namespace GAME;


PuckManager::~PuckManager() {
	while (!puckList.empty()) {
		delete puckList.front();
		puckList.pop_front();
	}
	puckList.clear();
}


void PuckManager::UpdatePuckManager(const float _deltaTime) {
	if (!puckList.empty()) {

		for (Puck* p : puckList) {
			p->FixedUpdate(_deltaTime);
		}

		if (puckList.front()->lifeTime >= puckList.front()->lifeSpan) {
			delete puckList.front();
			puckList.pop_front();
			Debug::ConsoleLog("Puck timed out and destroyed!");
		}
	}
} // end UpdatePuckManager()


void PuckManager::RenderPucks(const MATH::Matrix4& _proj) {
	if (!puckList.empty()) {
		for (Puck* p : puckList) {
			p->Render(_proj);
		}
	}
} // end RenderPucks()


void PuckManager::ForcePuck() {
	puckList.push_back(new Puck(wRef));
	Debug::ConsoleLog("Created puck!");
}