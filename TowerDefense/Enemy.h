#pragma once

#include "Object.h"
#include "TileSet.h"
#include "Animation.h"
#include "Timer.h"
#include "DirectionPoint.h"

enum EnemyState {
	WALKING,
	INVERTED,
	ATACK,
	DEATH,
	DEAD
};

enum EnemyType {
	CENOURA,
	BATATA,
	CEBOLA,
	NABO,
	BROCOLIS,
	CHEIROVERDE,
	MILHO,
	ALFACE,
	COUVEFLOR
};

enum Directions {
	GOINGUP,
	GOINGDOWN,
	GOINGLEFT,
	GOINGRIGHT,
	STOPPED
};

class Enemy : public Object {
private:
	TileSet* tileset;
	Animation* animation;
	uint state = WALKING;
	uint enemyType = CENOURA;	// cenoura é o tipo padrão
	int vel;
	int lastFrameDeath;
	int lastFrameAtack;
	TileSet* ghost;
	Timer deathTime;
	uint direction = GOINGRIGHT;
	uint lastDirection = STOPPED;

public:
	bool hited;
	bool canBeHited;
	int life;
	
	uint State();

	Enemy(TileSet* tset, uint enType, uint nivel = 1);
	~Enemy();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void Enemy::Draw() {
	animation->Draw(x, y, Layer::UPPER, scale);
}

inline uint Enemy::State() {
	return state;
}
