#include "Ghost.h"
#include "TowerDefense.h"

Ghost::Ghost(TileSet* tset) {
	animation = new Animation(tset, 0.1f, false);

}

Ghost::~Ghost() {
	delete animation;
}

void Ghost::Update() {
	animation->NextFrame();

	if (animation->Frame() == 9) {
		TowerDefense::scene->Delete();
	}
}