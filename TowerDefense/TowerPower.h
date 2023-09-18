#pragma once

#include "Object.h"
#include "Animation.h"
#include "TileSet.h"

class TowerPower : public Object {

private:

	TileSet* tileset;
	Animation* animation;
	int vel;
	int dstX;
	int dstY;
	int imX;
	int imY;

public:
	static int cdr;

	TowerPower(int posX, int posY, int toX, int toY);
	~TowerPower();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void TowerPower::Draw() {
	animation->Draw(x, y, z, scale, rotation);
}
