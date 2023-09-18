#include "Floor.h"

Floor::Floor(int posX, int posY) {
	sprite = new Sprite("Resources/floor.png");
}

Floor::~Floor() {
	delete sprite;
}

void Floor::Update() {

}

void Floor::OnCollision(Object * obj) {

}