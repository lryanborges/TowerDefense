#include "Floor.h"
#include "TowerDefense.h"

Floor::Floor(Sprite* spt, int posX, int posY) {

	sprite = spt;

	MoveTo(posX, posY);
	BBox(new Rect(-34, -34, 33, 33));

	type = FLOOR;
}

Floor::~Floor() {
	// nao deleta o floor
}

void Floor::Update() {

}

void Floor::OnCollision(Object * obj) {

}