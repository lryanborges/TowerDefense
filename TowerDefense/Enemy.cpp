#include "Enemy.h"

Enemy::Enemy() {
	//tileset = new TileSet("Resources/plantMonster.png", 32, 37, 8, 8);
	tileset = new TileSet("Resources/cenoura.png", 112, 112, 6, 8);

	uint normal[6] = { 0, 1, 2, 3, 4, 5 };
	uint atack[3] = { 6, 7};

	animation = new Animation(tileset, 0.15f, true);
	animation->Add(NORMAL, normal, 6);
	animation->Add(ATACK, atack, 2);

	MoveTo(0, window->CenterY());
}

Enemy::~Enemy() {
	delete tileset;
	delete animation;
}

void Enemy::Update() {
	animation->Select(state);
	animation->NextFrame();

	if (window->KeyPress('R')) {
		state = ATACK;
	}

	Translate(200 * gameTime, 0);
}

void Enemy::OnCollision() {

}