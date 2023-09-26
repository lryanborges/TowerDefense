#include "Mouse.h"
#include "TowerDefense.h"
#include "Tower.h"

Tower* Mouse::towerCarry = nullptr;
bool Mouse::carrying;
uint Mouse::state = PLENO;
Mouse::Mouse() {
	MoveTo(window->MouseX(), window->MouseY());

	state = PLENO;
	carrying = false;
	BBox(new Rect(-20, -20, 19, 19));
	type = MOUSE;
}

Mouse::~Mouse() {

}

void Mouse::Update() {

	
	if (carrying) {
		towerCarry->MoveTo(x, y - (towerCarry->Height()) / 4);
		if (window->KeyPress(VK_LBUTTON) && TowerDefense::mouse->State() != COLISAO) {
			if (state != COLISAO) {
				TowerDefense::audios->Play(TOWERSET, false);
				Priest::controler = true;
				carrying = false;
				towerCarry->MoveTo(x, y - (towerCarry->Height()) / 4);
				Mouse::towerCarry = nullptr;
			}
		}
	}

	state = PLENO;
	MoveTo(window->MouseX(), window->MouseY());
	
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
		if ((x > tower->X() - 50) && (x < tower->X() + 49) && (y > tower->Y() - 20) && (y < tower->Y() + 59) && !carrying) {
			state = COLISAO;
		}
	}

	if (obj->Type() == HUB) {
		state = COLISAO;
	}

	if (obj->Type() == BUTTON) {
		state = PLENO;
	}

	if (obj->Type() == GRASS) {
		state = COLISAO;
	}
}