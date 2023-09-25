#pragma once

#include "Object.h"
#include "Animation.h"
#include "TileSet.h"
#include "Timer.h"
#include "Enemy.h"
#include <unordered_set>

enum PowerState {
	YELLOWNORMAL,
	YELLOWEXPLOSION
};

class TowerPower : public Object {

private:

	TileSet* tileset;
	Animation* animation;
	uint powerState = YELLOWNORMAL;
	int vel;
	int dstX;
	int dstY;
	int imX;
	int imY;
	Timer hitedTimer;
	bool auxHit = false;
	int contEnemy;
	Enemy* firstEnemy;
	std::unordered_set<Enemy*> enemies;

public:
	static int cdr;
	bool canHit;

	int Frame();

	TowerPower(int posX, int posY, int toX, int toY, uint twrType);
	~TowerPower();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void TowerPower::Draw() {
	animation->Draw(x, y, z, scale, rotation);
}

inline int TowerPower::Frame() {
	return animation->Frame();
}