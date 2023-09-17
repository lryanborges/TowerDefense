#pragma once

#include "Object.h"
#include "TileSet.h"
#include "Animation.h"


class Rain : public Object {
private:
	Animation* animation;
	int vel;

public:

	Rain(TileSet* tset);
	~Rain();

	void Update();
	void Draw();
	void OnCollision();

};

inline void Rain::Draw() {
	animation->Draw(x, y, Layer::FRONT);
}