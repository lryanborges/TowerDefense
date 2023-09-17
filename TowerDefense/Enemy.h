#pragma once

#include "Object.h"
#include "TileSet.h"
#include "Animation.h"
#include "Timer.h"
#include "DirectionPoint.h"

enum EnemyState {
	WALKING,
	TOPWALKING,
	BOTTOMWALKING,
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
	GOINGRIGHT
};

class Enemy : public Object {
private:
	TileSet* tileset;
	Animation* animation;
	uint state = WALKING;
	uint enemyType = CENOURA;	// cenoura é o tipo padrão
	int vel;
	TileSet* ghost;
	Timer deathTime;
	uint direction = LEFT;

public:

	Enemy(TileSet* tset, uint enType);
	~Enemy();

	void Update();
	void Draw();
	void OnCollision(Object* obj);
	void OnCollision(DirectionPoint* point);

};

inline void Enemy::Draw() {
	animation->Draw(x, y, z);
}
