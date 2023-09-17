#include "Rain.h"

Rain::Rain(TileSet* tset) {
	animation = new Animation(tset, 0.5f, true);
	vel = 100;

	MoveTo(300, 100);
}

Rain::~Rain() {
	delete animation;
}

void Rain::Update() {


	Translate(0, vel * gameTime);
	Translate(-70 * gameTime, 0);

	animation->NextFrame();

}

void Rain::OnCollision() {

}