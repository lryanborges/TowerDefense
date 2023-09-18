#include "Enemy.h"
#include "Ghost.h"
#include "TowerDefense.h"
#include "Tower.h"

Enemy::Enemy(TileSet* tset, uint enType = 0) {

	tileset = tset;
	enemyType = enType;

	vel = 100;
	life = 1;
	lastFrameDeath = 23;
	lastFrameAtack = 15;

	ghost = new TileSet("Resources/ghost.png", 32, 32, 10, 10);

	int walkSize = 8;
	int atackSize = 8;
	int deathSize = 8;

	uint walking[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	uint atack[8] = { 8, 9, 10, 11, 12, 13, 14, 15 };
	uint death[8] = { 16, 17, 18, 19, 20, 21, 22, 23 };
	uint inverted[8] = {31, 30, 29, 28, 27, 26, 25, 24 };

	if (enemyType == BATATA) {
		walkSize = 6;
		life = 1;
	}
	if (enemyType == COUVEFLOR) {
		walkSize = 6;
		deathSize = 6;
		lastFrameDeath = 21;
		lastFrameAtack = 13;
	}
	if (enemyType == ALFACE) {
		walkSize = 6;
		atackSize = 6;
		deathSize = 6;
		lastFrameDeath = 21;
		lastFrameAtack = 13;
	}
	
	animation = new Animation(tileset, 0.15f, true);
	animation->Add(WALKING, walking, walkSize);
	animation->Add(INVERTED, inverted, walkSize);
	animation->Add(ATACK, atack, atackSize);
	animation->Add(DEATH, death, deathSize);
	
	uint dead[1] = { lastFrameDeath };
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

	if (window->KeyPress('R')) {
		state = ATACK;
		direction = STOPPED;
	}
	if (window->KeyPress('Q') || life <= 0) {
		state = DEATH;
		direction = STOPPED;
		life = 1; // valor > que 0 só pra não entrar mais nesse if e deixar o deathTime chegar em 2.0f pra poder excluir o objeto
	}
	if (window->KeyPress('D') || direction == GOINGRIGHT) {
		state = WALKING;
		direction = GOINGRIGHT;
	}
	if (window->KeyPress('W') || direction == GOINGUP) {
		direction = GOINGUP;
	}
	if (window->KeyPress('S') || direction == GOINGDOWN) {
		direction = GOINGDOWN;
	}
	if (window->KeyPress('A') || direction == GOINGLEFT) {
		state = INVERTED;
		direction = GOINGLEFT;
	}

	if (direction == GOINGRIGHT && direction != STOPPED) {
		Translate(vel * gameTime, 0);
	}
	if (direction == GOINGUP) {
		Translate(0, -vel * gameTime);
	}
	if (direction == GOINGDOWN) {
		Translate(0, vel * gameTime);
	}
	if (direction == GOINGLEFT) {
		Translate(-vel * gameTime, 0);
	}

	if (animation->Frame() == lastFrameDeath - 1) {
		deathTime.Start();
		BBox()->Scale(-1.0f); // escalar por -1 tá deixando ela sem colisão
		state = DEAD;
		Ghost* newGhost = new Ghost(ghost);
		newGhost->MoveTo(x, y);
		TowerDefense::scene->Add(newGhost, STATIC);
	} 

	if (deathTime.Elapsed(2.0f) && state == DEAD) {
		TowerDefense::scene->Delete();
	}
	
	animation->Select(state);
	animation->NextFrame();

}

void Enemy::OnCollision(Object* obj) {

	// substituir 100 por TOWER ou o objeto que os vegetais forem atacar
	if (obj->Type() == 100) {

		switch (direction) {
		case GOINGRIGHT:
			lastDirection = GOINGRIGHT;
			break;
		case GOINGLEFT:
			lastDirection = GOINGLEFT;
			break;
		case GOINGUP:
			lastDirection = GOINGUP;
			break;
		case GOINGDOWN:
			lastDirection = GOINGDOWN;
			break;
		}

		state = ATACK;
		direction = STOPPED;

		Tower* tower = dynamic_cast<Tower*>(obj);
		if (animation->Frame() == lastFrameAtack) {
			tower->life--;
			if (tower->life > 0) {
				state = WALKING;
			}
			else {
				state = WALKING;
				direction = lastDirection;
			}

		}

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

	if (obj->Type() == POWERGREEN) {
		life--;

		TowerDefense::scene->Delete(obj, POWERGREEN);
	}
}
