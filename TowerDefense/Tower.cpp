#include "Tower.h"
#include "TowerDefense.h"
#include "TowerPower.h"
#include "Enemy.h"

Tower::Tower() {
	sprite = new Sprite("Resources/statueGreen.png");

	BBox(new Circle(180));
	// new Rect(-24, -2, 23, 43)

	MoveTo(window->CenterX(), window->CenterY());

	life = 5;

	type = TOWER;
}

Tower::~Tower() {
	delete sprite;
}

void Tower::Update() {
	text.str("");

	text << life << ".\n";;
	OutputDebugString(text.str().c_str());
	if (life <= 0) {
		TowerDefense::scene->Delete();
	}

	// só pra começar a contar o tempo
	if (TowerPower::cdr == 50) {
		atackTime.Start();
	}

}

void Tower::Draw() {
	sprite->Draw(x, y, z);

	// , 1.0f, 0.0f, {1.3, 1, 1, 1} -> vermelho soft
	// {2, 35, 212, 1} -> cristal
}

void Tower::OnCollision(Object* obj) {
	
	if (obj->Type() == ENEMY) {
		Enemy* enemy = dynamic_cast<Enemy*>(obj);

		if (atackTime.Elapsed(1.0f)) {
			TowerPower* power = new TowerPower(x, y, enemy->X(), enemy->Y());
			TowerDefense::scene->Add(power, MOVING);
			atackTime.Start();
		}
	}
}