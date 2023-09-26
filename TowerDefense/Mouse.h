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

public:
	static uint state;
	static bool carrying;
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