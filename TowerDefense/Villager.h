#pragma once

#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

enum VillagerState {
	WALKFRONT,
	WALKRIGHT,
	WALKBACK,
	WALKLEFT,
	RESTO
};

class Villager : public Object {

private:

	TileSet* tileset;
	Animation* animation;
	uint state = WALKFRONT;

public:

	Villager();
	~Villager();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void Villager::Draw() {
	animation->Draw(x, y, z);
}
