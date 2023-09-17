#pragma once

#include "Object.h"
#include "Sprite.h"


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

inline void Tower::Draw() {
	sprite->Draw(x, y, z, 1.0f, 0.0f, {1.3, 1, 1, 1});
	// {2, 35, 212, 1} -> cristal
}