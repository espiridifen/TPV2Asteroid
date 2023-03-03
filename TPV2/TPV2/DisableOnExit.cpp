#include "src/components/DisableOnExit.h"


void DisableOnExit::initComponent() {
	bulletData = ent->getComponent<Transform>();
}

void DisableOnExit::update() {
	Vector2D currentPos=bulletData->getPos();
	if (currentPos.getX() > WIN_WIDTH || currentPos.getY() > WIN_HEIGHT ||
		currentPos.getX() < 0 || currentPos.getY() < 0) {
		ent->setAlive(false);
	}
}