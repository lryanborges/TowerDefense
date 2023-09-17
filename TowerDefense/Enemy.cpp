#include "Enemy.h"
#include "Ghost.h"
#include "TowerDefense.h"

Enemy::Enemy(TileSet* tset, uint enType = 0) {

	tileset = tset;
	enemyType = enType;

	vel = 100;

	ghost = new TileSet("Resources/ghost.png", 32, 32, 10, 10);

	int walkSize = 8;
	int atackSize = 8;
	int deathSize = 8;

	uint walking[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	uint bottomwalking[8] = { 8, 9, 10, 11, 12, 13, 14, 15 };
	uint topwalking[8] = { 16, 17, 18, 19, 20, 21, 22, 23 };
	uint inverted[8] = {47, 46, 45, 44, 43, 42, 41, 40};
	uint atack[8] = { 24, 25, 26, 27, 28, 29, 30, 31 };
	uint death[8] = { 32, 33, 34, 35, 36, 37, 38, 39 };

	if (enemyType == BATATA) {
		walkSize = 6;
	}
	if (enemyType == COUVEFLOR) {
		walkSize = 6;
		deathSize = 6;
	}
	if (enemyType == ALFACE) {
		walkSize = 6;
		atackSize = 6;
		deathSize = 6;
	}
	
	animation = new Animation(tileset, 0.15f, true);
	animation->Add(WALKING, walking, walkSize);
	animation->Add(TOPWALKING, topwalking, walkSize);
	animation->Add(BOTTOMWALKING, bottomwalking, walkSize);
	animation->Add(INVERTED, inverted, walkSize);
	animation->Add(ATACK, atack, atackSize);
	animation->Add(DEATH, death, deathSize);
	
	uint dead[1] = { 39 };
	animation->Add(DEAD, dead, 1);

	BBox(new Rect(-20, -16, 19, 19));

	MoveTo(0, window->CenterY() + 20);

	type = ENEMY;
}

Enemy::~Enemy() {
	delete ghost;
	delete tileset;
	delete animation;
}

void Enemy::Update() {

	animation->Select(state);
	animation->NextFrame();

	if (animation->Frame() == 31) {
		state = WALKING;
	}

	if (window->KeyPress('R')) {
		state = ATACK;
	}
	if (window->KeyPress('Q')) {
		state = DEATH;
	}
	if (window->KeyPress('D') || direction == GOINGRIGHT) {
		state = WALKING;
		direction = GOINGRIGHT;
	}
	if (window->KeyPress('W') || direction == GOINGUP) {
		state = TOPWALKING;
		direction = GOINGUP;
	}
	if (window->KeyPress('S') || direction == GOINGDOWN) {
		state = BOTTOMWALKING;
		direction = GOINGDOWN;
	}
	if (window->KeyPress('A') || direction == GOINGLEFT) {
		state = INVERTED;
		direction = GOINGLEFT;
	}

	if (state == WALKING) {
		Translate(vel * gameTime, 0);
	}
	if (state == TOPWALKING) {
		Translate(0, -vel * gameTime);
	}
	if (state == BOTTOMWALKING) {
		Translate(0, vel * gameTime);
	}
	if (state == INVERTED) {
		Translate(-vel * gameTime, 0);
	}

	if (animation->Frame() == 38) {
		deathTime.Start();
		state = DEAD;
		Ghost* newGhost = new Ghost(ghost);
		newGhost->MoveTo(x, y);
		TowerDefense::scene->Add(newGhost, STATIC);
	} 

	if (deathTime.Elapsed(2.0f) && state == DEAD) {
		TowerDefense::scene->Delete();
	}
	
}

void Enemy::OnCollision(Object* obj) {

	if (obj->Type() == TOWER) {
		state = ATACK;
		vel = 0;
	}
	if (obj->Type() == DIRECTIONPOINT) {

		DirectionPoint* point = dynamic_cast<DirectionPoint*>(obj);

		if (point->direction == LEFT) {
			direction = GOINGLEFT;
		}
		if (point->direction == UP) {
			direction = GOINGUP;
		}
		if (point->direction == DOWN) {
			direction = GOINGDOWN;
		}
		if (point->direction == RIGHT) {
			direction = GOINGRIGHT;
		}
	}
}

void Enemy::OnCollision(DirectionPoint* point) {
	
	

}