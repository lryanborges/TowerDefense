#include "Priest.h"
#include "TowerDefense.h"

Priest::Priest() {

	tileSet = new TileSet("Resources/priest.png", 80, 80, 4, 16);
	animation = new Animation(tileSet, 0.5f, true);
	uint priest[16] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	uint stay[6] = { 2,3,4,4,3,2 };
	animation->Add(STAY, stay, 6);
	animation->Add(MAGIC, priest, 16);

	MoveTo(20, 645);
	type = PRIEST;
}

Priest::~Priest() {
	delete tileSet;
	delete animation;
}



void Priest::Update()
{
	if (controler && state) {
		stt = MAGIC;
		state = false;
	}
	animation->Select(stt);
	animation->NextFrame();

	if (animation->Frame() == 15 && !state) {
		state = true;
		stt = STAY;
	}
}

bool Priest::operator==(const Priest& other) const
{
	return false;
}
