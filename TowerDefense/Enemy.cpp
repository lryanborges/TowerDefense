#include "Enemy.h"

Enemy::Enemy(TileSet* tset, uint enemyType = 0) {

	tileset = tset;
	type = enemyType;

	int walkSize = 8;
	int atackSize = 8;
	int deathSize = 8;

	uint walking[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	uint atack[8] = { 8, 9, 10, 11, 12, 13, 14, 15 };
	uint death[8] = { 16, 17, 18, 19, 20, 21, 22, 23 };


	if (type == BATATA) {
		walkSize = 6;

		BBox(new Rect(-44, -8, 26, 55));
	}
	if (type == COUVEFLOR) {
		walkSize = 6;
		deathSize = 6;
	}
	if (type == ALFACE) {
		walkSize = 6;
		atackSize = 6;
		deathSize = 6;
	}
	
	animation = new Animation(tileset, 0.15f, true);
	animation->Add(WALKING, walking, walkSize);
	animation->Add(ATACK, atack, atackSize);
	animation->Add(DEATH, death, deathSize);

	MoveTo(300, window->CenterY());
}

Enemy::~Enemy() {
	delete tileset;
	delete animation;
}

void Enemy::Update() {

	if (animation->Frame() == 15) {
		state = WALKING;
	}

	if (window->KeyPress('R')) {
		state = ATACK;
	}
	if (window->KeyPress('D')) {
		state = DEATH;
	}
	if (window->KeyPress('W')) {
		state = WALKING;
	}

	if (state == WALKING) {
		Translate(100 * gameTime, 0);
	}

	if (!(animation->Frame() == 23)) {
		animation->NextFrame();
	}

	animation->Select(state);

}

void Enemy::OnCollision() {

}