#include "Tower.h"
#include "TowerDefense.h"
#include "TowerPower.h"
#include "Enemy.h"
#include "Floor.h"

Tower::Tower(uint twrType) {

	towerType = twrType;

	if (towerType == GREEN) {
		sprite = new Sprite("Resources/statueGreen.png");
		BBox(new Circle(180));
	}

	if (towerType == YELLOW) {
		sprite = new Sprite("Resources/statueYellow.png");
		BBox(new Circle(180));
	}

	if (towerType == BLUE) {
		sprite = new Sprite("Resources/statueBlue.png");
		BBox(new Circle(180));
	}

	if (towerType == RED) {
		sprite = new Sprite("Resources/statueRed.png");
		BBox(new Circle(180));
	}

	if (towerType == PURPLE) {
		sprite = new Sprite("Resources/statuePurple.png");
		BBox(new Circle(180));
	}

	// new Rect(-24, -2, 23, 43)

	MoveTo(window->CenterX(), window->CenterY());

	life = 5;
	startAtack = true;
	hitEnemy = false;
	firstHit = true;

	type = TOWER;
}

Tower::~Tower() {

	if (Mouse::carrying) {
		TowerDefense::scene->Delete(Mouse::towerCarry, TOWER);
		Mouse::carrying = false;
	}

	delete sprite;
}

void Tower::Update() {
	if (life <= 0) {
		TowerDefense::scene->Delete();
	}

	if (towerType == GREEN || towerType == YELLOW || towerType == BLUE) {
		// só pra começar a contar o tempo
		if (startAtack) {
			greenAtackTimer.Start();
			yellowAtackTimer.Start();
			blueAtackTimer.Start();
		}
	}

}

void Tower::Draw() {
	
	if (Mouse::state == COLISAO && Mouse::towerCarry == this) {
		sprite->Draw(x, y, Layer::UPPER, 1.0f, 0.0f, {1.5, 1, 1, 1});
	}
	else {
		sprite->Draw(x, y, Layer::UPPER);
	}


	// , 1.0f, 0.0f, {1.3, 1, 1, 1} -> vermelho soft
	// {2, 35, 212, 1} -> cristal
}

void Tower::OnCollision(Object* obj) {

	if (obj->Type() == ENEMY) {
		Enemy* enemy = dynamic_cast<Enemy*>(obj);
		startAtack = false;

		if (Mouse::towerCarry != this) {
			if ((enemy->State() < DEATH || enemy->State() > DEAD)) {
				if (towerType == GREEN) {
					if (firstHit || greenAtackTimer.Elapsed(1.0f)) {
						TowerPower* power = new TowerPower(x, y, enemy->X(), enemy->Y(), GREEN);
						TowerDefense::scene->Add(power, MOVING);
						greenAtackTimer.Reset();
						firstHit = false;
					}
				}

				if (towerType == YELLOW) {
					if ((firstHit || yellowAtackTimer.Elapsed(5.0f)) && (enemy->State() < DEATH || enemy->State() > DEAD)) {
						TowerPower* power = new TowerPower(x, y, enemy->X(), enemy->Y(), YELLOW);
						TowerDefense::scene->Add(power, MOVING);
						yellowAtackTimer.Reset();
						firstHit = false;
					}
				}

				if (towerType == BLUE) {
					if ((firstHit || blueAtackTimer.Elapsed(2.0f)) && (enemy->State() < DEATH || enemy->State() > DEAD)) {
						TowerPower* power = new TowerPower(x, y, enemy->X(), enemy->Y(), BLUE);
						TowerDefense::scene->Add(power, MOVING);
						blueAtackTimer.Reset();
						firstHit = false;
						power->canHit = true;
					}
				}

				if (towerType == RED) {
					if ((firstHit || greenAtackTimer.Elapsed(2.0f)) && (enemy->State() < DEATH || enemy->State() > DEAD)) {
						TowerPower* power = new TowerPower(x, y, enemy->X(), enemy->Y(), RED);
						TowerDefense::scene->Add(power, MOVING);
						greenAtackTimer.Reset();
						firstHit = false;
						power->canHit = true;
					}
				}

				if (towerType == PURPLE) {
					if ((firstHit || greenAtackTimer.Elapsed(2.0f)) && (enemy->State() < DEATH || enemy->State() > DEAD)) {
						TowerPower* power = new TowerPower(x, y, enemy->X(), enemy->Y(), PURPLE);
						TowerDefense::scene->Add(power, MOVING);
						greenAtackTimer.Reset();
						firstHit = false;
						power->canHit = true;
					}
				}
			}

		}


	}

	if (obj->Type() == FLOOR) {
		Floor* floor = dynamic_cast<Floor*>(obj);

		text.str("");

		text << floor->X() << ".\n";;
		OutputDebugString(text.str().c_str());
	}

}