#pragma once

#include "Object.h"
#include "Enemy.h"
#include "Tower.h"

enum MouseState {
	PLENO,
	COLISAO
};

class Mouse : public Object {
private:

	uint state = PLENO;

public:
	bool carrying;
	static Tower* towerCarry;

	uint State();

	Mouse();
	~Mouse();

	void Update();
	void Draw();
	void OnCollision(Object* obj);

};

inline void Mouse::Draw() {

}

inline uint Mouse::State() {
	return state;
}