#include "TowerDefense.h"

bool Priest::controler = false;
int Priest::life = 10;
bool Priest::lostLife = false;
Priest::Priest() {

	tileSet = new TileSet("Resources/priest.png", 219, 207, 16, 16);
	animation = new Animation(tileSet, 0.15f, true);
	uint priest[16] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	uint stay[5] = { 2,3,4,3,2 };
	animation->Add(STAY, stay, 5);
	animation->Add(MAGIC, priest, 16);

	purpleBar = new Sprite("Resources/purpleBar.png");
	pinkBar = new Sprite("Resources/pinkBar.png");
	
	pinkX = x + 260;
	lostLife = false;
	MoveTo(100, 560);
	type = PRIEST;
}

Priest::~Priest() {
	delete purpleBar;
	delete pinkBar;
	delete tileSet;
	delete animation;
}

void Priest::Update()
{
	animation->Select(stt);
	animation->NextFrame();

	if (controler && state) {
		stt = MAGIC;
		state = false;
	}

	if (animation->Frame() == 15 && !state) {
		state = true;
		stt = STAY;
		controler = false;
	}

	if (lostLife) {
		pinkX = pinkX - 13.4;
		lostLife = false;
	}

	switch (life) {
	case 10:
		break;
	case 9: 
		pinkBar = new Sprite("Resources/pinkBar90.png");
		break;
	case 8:
		pinkBar = new Sprite("Resources/pinkBar80.png");
		break;
	case 7:
		pinkBar = new Sprite("Resources/pinkBar70.png");
		break;
	case 6:
		pinkBar = new Sprite("Resources/pinkBar60.png");
		break;
	case 5:
		pinkBar = new Sprite("Resources/pinkBar50.png");
		break;
	case 4:
		pinkBar = new Sprite("Resources/pinkBar40.png");
		break;
	case 3:
		pinkBar = new Sprite("Resources/pinkBar30.png");
		break;
	case 2:
		pinkBar = new Sprite("Resources/pinkBar20.png");
		break;
	case 1:
		pinkBar = new Sprite("Resources/pinkBar10.png");
		break;
	default:
		pinkBar = new Sprite("");
	}

}

void Priest::Draw() {
	animation->Draw(x, y, Layer::FRONT);
	purpleBar->Draw(x + 160, y + 83, Layer::FRONT - 0.001f);
	pinkBar->Draw(pinkX, y + 83, Layer::FRONT - 0.002f);
}

