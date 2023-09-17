#include "Rain.h"

Rain::Rain(TileSet* tset) {
	animation = new Animation(tset, 1.0f, true);
	vel = 10;

	MoveTo(300, 100);
}

Rain::~Rain() {
	delete animation;
}

void Rain::Update() {

	animation->NextFrame();

	Translate(-vel * gameTime, vel * gameTime);
}

void Rain::OnCollision() {

}