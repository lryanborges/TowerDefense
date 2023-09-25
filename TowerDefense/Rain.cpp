#include "Rain.h"
#include "TowerDefense.h"

Rain::Rain(TileSet* tset, uint rainTp) {

	state = rainTp;

	animation = new Animation(tset, 0.0f, false);
	vel = 100;

	uint rain1[1] = {0};
	uint rain2[1] = {1};
	uint rain3[1] = {2};

	animation->Add(RAIN1, rain1, 1);
	animation->Add(RAIN2, rain2, 1);
	animation->Add(RAIN3, rain3, 1);

	MoveTo(300, 100);
}

Rain::~Rain() {
	delete animation;
}

void Rain::Update() {
	animation->Select(state);

	Translate(0, vel * gameTime);
	Translate(-40 * gameTime, 0);

	// pra deletar os pingos de chuva caso saiam da tela pra esquerda ou pra baixo (direções que dão translate)
	if (x - 4 < 0)
		TowerDefense::scene->Delete();

	if (y + 4 > window->Height())
		TowerDefense::scene->Delete();

}

void Rain::OnCollision() {

}