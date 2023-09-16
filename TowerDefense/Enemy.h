#pragma once

#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

enum EnemyState {
	NORMAL,
	ATACK
};

class Enemy : public Object {
private:
	TileSet* tileset;
	Animation* animation;
	uint state = NORMAL;
public:

	Enemy();
	~Enemy();

	void Update();
	void Draw();
	void OnCollision();

};

inline void Enemy::Draw() {
	animation->Draw(x, y, z);
}
