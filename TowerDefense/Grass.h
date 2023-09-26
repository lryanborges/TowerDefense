#pragma once

#include "Object.h"
#include "Sprite.h"

class Grass : public Object {
private:

	Sprite* sprite;
	uint grassType = 0;

public:

	Grass(int posX, int posY, uint grassTp = 0);
	~Grass();

	void Update();
	void Draw();
	void OnCollision(Object* obj);
};

inline void Grass::Draw() {
	sprite->Draw(x, y, Layer::UPPER + 0.01f);
}
