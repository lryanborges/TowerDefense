#pragma once

#include "Object.h"
#include "Sprite.h"

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

public:

	Tower();
	~Tower();

	void Update();
	void Draw();
	void OnCollision();

};
