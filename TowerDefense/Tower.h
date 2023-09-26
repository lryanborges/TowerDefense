#pragma once

#include "Object.h"
#include "Sprite.h"
#include "Timer.h"
#include <sstream>
using std::stringstream;

enum TowerType {
	GREEN,
	RED,
	YELLOW,
	BLUE,
	PURPLE
};

class Tower : public Object {
private:
	Sprite* sprite;
	stringstream text;
	Timer greenAtackTimer;
	Timer yellowAtackTimer;
	Timer blueAtackTimer;
	uint towerType = GREEN;
	bool startAtack;
	int enemyX;
	int enemyY;
	bool hitEnemy;
	bool firstHit;

public:
	int life;

	uint tType();
	int Height();
	int Width();

	Tower(uint twrType = GREEN);
	~Tower();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline int Tower::Height() {
	return sprite->Height();
}

inline int Tower::Width() {
	return sprite->Width();
}

inline uint Tower::tType() {
	return towerType;
}
