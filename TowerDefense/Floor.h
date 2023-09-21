#pragma once

#include "Object.h"
#include "Sprite.h"

class Floor : public Object {
private:

	Sprite* sprite;
	int posX;
	int posY;

public:

	int Height();
	int Width();

	Floor(Sprite* spt, int posX, int posY);
	~Floor();

	void Update();
	void Draw();
	void OnCollision(Object* obj);
};

inline void Floor::Draw() {
	sprite->Draw(x, y, Layer::LOWER);
}

inline int Floor::Height() {
	return sprite->Height();
}

inline int Floor::Width() {
	return sprite->Width();
}
