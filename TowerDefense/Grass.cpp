#include "Grass.h"

Grass::Grass(int posX, int posY, uint grassTp) {
	if (grassTp == 1) {
		sprite = new Sprite("Resources/grass1.png");
	}
	MoveTo(posX, posY);
}

Grass::~Grass() {
	delete sprite;
}

void Grass::Update() {

}

void Grass::OnCollision(Object* obj) {

}