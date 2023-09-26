#pragma once

#include "Object.h"
#include "Animation.h"
#include "TileSet.h"
#include "Timer.h"
#include "Enemy.h"
#include <unordered_set>

enum PowerState {
	YELLOWNORMAL,
	YELLOWEXPLOSION,
	REDSTART,
	REDNORMAL,
	REDEXPLOSION,
	PURPLENORMAL,
	PURPLEFINISHED
};

class TowerPower : public Object {

private:

	TileSet* tileset;
	Animation* animation;
	uint powerState;
	int vel;
	int dstX;
	int dstY;
	int imX;
	int imY;
	Timer hitedTimer;
	bool auxHit = false;
	int contEnemy;
	std::unordered_set<Enemy*> enemies;

public:
	static int cdr;
	bool canHit;
	Enemy* firstEnemy;

	int Frame();

	TowerPower(int posX, int posY, int toX, int toY, uint twrType);
	~TowerPower();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline int TowerPower::Frame() {
	return animation->Frame();
}