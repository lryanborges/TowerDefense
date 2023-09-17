#pragma once

#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

enum EnemyState {
	WALKING,
	ATACK,
	DEATH
};

enum EnemyType {
	CENOURA,
	BATATA,
	CEBOLA,
	TOMATE,
	BROCOLIS,
	CHEIROVERDE,
	MILHO,
	ALFACE,
	COUVEFLOR
};

class Enemy : public Object {
private:
	TileSet* tileset;
	Animation* animation;
	uint state = WALKING;
	uint type = CENOURA;	// cenoura é o tipo padrão
public:

	Enemy(TileSet* tset, uint enemyType);
	~Enemy();

	void Update();
	void Draw();
	void OnCollision();

};

inline void Enemy::Draw() {
	animation->Draw(x, y, z);
}
