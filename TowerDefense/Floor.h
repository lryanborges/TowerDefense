#pragma once

#include "Object.h"
#include "Sprite.h"

class Floor : public Object {
private:

	Sprite* sprite;

public:

	Floor(int posX, int posY);
	~Floor();

	void Update();
	void Draw();
	void OnCollision(Object* obj);
};

inline void Floor::Draw() {
	sprite->Draw(x, y, z);
}
