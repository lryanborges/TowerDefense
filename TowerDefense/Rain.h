#pragma once

#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

enum rainTypes {
	RAIN1,
	RAIN2,
	RAIN3,
};

class Rain : public Object {
private:
	Animation* animation;
	int vel;
	uint state = RAIN1;

public:

	Rain(TileSet* tset, uint rainTp);
	~Rain();

	void Update();
	void Draw();
	void OnCollision();

};

inline void Rain::Draw() {
	animation->Draw(x, y, Layer::MIDDLE);
}