#pragma once

#include "Object.h"

enum SideType {
	UP,
	DOWN,
	RIGHT,
	LEFT
};

class DirectionPoint : public Object {

private:

public:
	uint direction;
	
	DirectionPoint(uint dir = RIGHT);
	~DirectionPoint();

	void Update();
	void Draw();
	void OnCollision(Object * obj);

};

inline void DirectionPoint::Draw() {

}
