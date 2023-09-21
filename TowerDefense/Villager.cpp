#include "Villager.h"

Villager::Villager() {
	tileset = new TileSet("Resources/marnie.png", 18, 32, 4, 28);
	animation = new Animation(tileset, 0.2, true);

	uint walkfront[4] = { 0, 1, 2, 3 };
	uint walkright[4] = { 4, 5, 6, 7 };
	uint walkback[4] = { 8, 9, 10, 11 };
	uint walkleft[4] = { 12, 13, 14, 15 };
	uint resto[12] = { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27 };

	animation->Add(WALKFRONT, walkfront, 4);
	animation->Add(WALKRIGHT, walkright, 4);
	animation->Add(WALKBACK, walkback, 4);
	animation->Add(WALKLEFT, walkleft, 4);
	animation->Add(RESTO, resto, 12);

	MoveTo(400, 400);

}

Villager::~Villager() {
	delete tileset;
	delete animation;
}

void Villager::Update() {
	animation->NextFrame();
	animation->Select(state);
}

void Villager::OnCollision(Object* obj) {

}