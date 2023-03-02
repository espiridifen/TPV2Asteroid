#include "Gun.h"
#include "../sdlutils/SDLUtils.h"
#include "../sdlutils/InputHandler.h"
#include "../ecs/Entity.h"
#include "../game/Game.h"

#include "Image.h"
#include "DisableOnExit.h"


Gun::Gun()
{
	
}

Gun::~Gun()
{
	
}

void Gun::initComponent() {
	shipData = ent->getComponent<Transform>();
}

void Gun::handleInput()
{
	if (InputHandler::instance()->isKeyDown(SDLK_s)) {
		if (lastTimeShot > 250)
		{
			// shotSound->play(1);
			Entity* bullet = mngr->addEntity();
			bullet->setGroup(_grp_BULLETS);
			bullet->addComponent<Transform>(shipData->getPos(), Vector2D(0,-1).rotate(shipData->getRotation())*100+shipData->getVel(), 1, 1, 0);
			bullet->addComponent<Image>(Game::getTexture("Bullet"));
			//bullet->addComponent<DisableOnExit>();
			lastTimeShot = 250;
		}
		
	}
	
}

void Gun::update() {
	lastTimeShot++;
}