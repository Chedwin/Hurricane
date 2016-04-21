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


void PuckManager::ForcePuck(const SDL_RendererFlip& sf) {
	Puck* n = new Puck(wRef);
	pmPos -= Vec3(-0.5f, 0.7f, 0.0f);
	n->SetStartPos(pmPos);
	n->PlayerDir(sf);
	puckList.push_back(n);
	Debug::ConsoleLog("Created puck!");
}

void PuckManager::Puck_Window_Collision() {
	int winWidth = 25.0f;
	//int winHeight = wRef.GetHeight();

	for (Puck* p : puckList) {
		if (p->pos.x > 25.0f) {
			p->vel = -1.0f * p->vel;
		}
		else if (p->pos.x <= 0.0f) {
			p->vel = -1.0f * p->vel;
		}
	}
}