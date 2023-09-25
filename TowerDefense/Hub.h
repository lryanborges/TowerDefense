#pragma once
#include "Object.h"
#include "Sprite.h"
#include <sstream>
using std::stringstream;


class Hub : public Object {
private:
	Image* image;
	Sprite* sprite;
	stringstream text;

public:
	Hub();
	~Hub();
	void Update();
	void Draw();

	void OnCollision(Object* obj);
};
