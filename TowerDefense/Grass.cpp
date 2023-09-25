#include "Grass.h"

Grass::Grass(int posX, int posY, uint grassTp) {
	if (grassTp == 1) {
		sprite = new Sprite("Resources/grass1.png");
	}
	if (grassTp == 2) {
		sprite = new Sprite("Resources/grass2.png");
	}
	if (grassTp == 3) {
		sprite = new Sprite("Resources/grass3.png");
	}
	if (grassTp == 4) {
		sprite = new Sprite("Resources/grass4.png");
	}
	if (grassTp == 5) {
		sprite = new Sprite("Resources/grass5.png");
	}
	if (grassTp == 6) {
		sprite = new Sprite("Resources/grass6.png");
	}
	if (grassTp == 7) {
		sprite = new Sprite("Resources/grass7.png");
	}
	if (grassTp == 8) {
		sprite = new Sprite("Resources/grass8.png");
	}
	if (grassTp == 9) {
		sprite = new Sprite("Resources/tree1.png");
	}
	if (grassTp == 10) {
		sprite = new Sprite("Resources/tree2.png");
	}
	if (grassTp == 11) {
		sprite = new Sprite("Resources/tree3.png");
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