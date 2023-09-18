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
	Timer atackTime;

public:
	int life;

	int Height();
	int Width();

	Tower();
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
