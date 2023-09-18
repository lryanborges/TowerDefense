#pragma once

#include "Object.h"
#include "Animation.h"
#include "TileSet.h"

enum PowerState {
	YELLOWNORMAL,
	YELLOWEXPLOSION
};

class TowerPower : public Object {

private:

	TileSet* tileset;
	Animation* animation;
	uint powerState = YELLOWNORMAL;
	int vel;
	int dstX;
	int dstY;
	int imX;
	int imY;

public:
	static int cdr;

	TowerPower(int posX, int posY, int toX, int toY, uint twrType);
	~TowerPower();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void TowerPower::Draw() {
	animation->Draw(x, y, z, scale, rotation);
}
