#include "Mouse.h"
#include "TowerDefense.h"
#include "Tower.h"

Mouse::Mouse() {
	MoveTo(window->MouseX(), window->MouseY());

	BBox(new Rect(-20, -20, 19, 19));
	type = MOUSE;
}

Mouse::~Mouse() {

}

void Mouse::Update() {
	MoveTo(window->MouseX(), window->MouseY());
	state = PLENO;
}

void Mouse::OnCollision(Object * obj) {
	if (obj->Type() == FLOOR) {
		if (x > obj->X() - 34 && x < obj->X() + 33 && y > obj->Y() - 34 && y < obj->Y() + 33) {
			state = COLISAO;
		}
		state = COLISAO;
	}

	if (obj->Type() == TOWER) {
		Tower* tower = dynamic_cast<Tower*>(obj);

		// inicialmente, -24, +23, -2, +43 -> left, right, top, bottom
		if ((x > tower->X() - 50) && (x < tower->X() + 49) && (y > tower->Y() - 20) && (y < tower->Y() + 59)) {
			state = COLISAO;
		}
	}
}