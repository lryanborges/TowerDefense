#pragma once

#include "Object.h"
#include "Animation.h"
#include "TileSet.h"

class Ghost : public Object {
private:
	Animation* animation;

public:
	Ghost(TileSet* tset);
	~Ghost();

	void Update();
	void Draw();

};

inline void Ghost::Draw() {
	animation->Draw(x, y, Layer::FRONT);
}
