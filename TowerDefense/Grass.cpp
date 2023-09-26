#include "Grass.h"
#include "TowerDefense.h"

Grass::Grass(int posX, int posY, uint grassTp) {

	grassType = grassTp;

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
	if (grassTp == 12) {
		sprite = new Sprite("Resources/bush1.png");
	}
	if (grassTp == 13) {
		sprite = new Sprite("Resources/bush2.png");
	}
	if (grassTp == 14) {
		sprite = new Sprite("Resources/bush3.png");
	}
	if (grassTp == 20) {
		sprite = new Sprite("Resources/plate1.png");
	}
	if (grassTp == 40) {
		sprite = new Sprite("Resources/tomb1.png");
	}
	if (grassTp == 41) {
		sprite = new Sprite("Resources/tomb2.png");
	}
	if (grassTp == 42) {
		sprite = new Sprite("Resources/tomb3.png");
	}
	MoveTo(posX, posY);

	if (grassTp >= 20) {
		BBox(new Rect(-16, -16, 15, 15));
	}

	type = GRASS;
}

Grass::~Grass() {
	delete sprite;
}

void Grass::Update() {

}

void Grass::Draw() {
	if (grassType == 12 || grassType == 13 || grassType == 14) {
		sprite->Draw(x, y, Layer::UPPER - 0.01f);
	}
	else {
		sprite->Draw(x, y, Layer::UPPER + 0.01f, 1.0f, 0.0f, { 0.8, 0.8, 0.6, 1 });
	}
}

void Grass::OnCollision(Object* obj) {

}