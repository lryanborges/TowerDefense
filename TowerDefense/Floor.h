#pragma once

#include "Object.h"
#include "Sprite.h"

class Floor : public Object {
private:

	Sprite* sprite;
	int posX;
	int posY;
	bool ocupado = false;

public:

	int Height();
	int Width();

	Floor(Sprite* spt, int posX, int posY, bool toPut = false);
	~Floor();

	void Update();
	void Draw();
	void OnCollision(Object* obj);
};

inline int Floor::Height() {
	return sprite->Height();
}

inline int Floor::Width() {
	return sprite->Width();
}
