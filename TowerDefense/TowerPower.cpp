#include "TowerPower.h"
#include "TowerDefense.h"
#include <math.h>
#include "Enemy.h"
#include "Tower.h"

int TowerPower::cdr;
TowerPower::TowerPower(int posX, int posY, int toX, int toY, uint twrType) {

	uint towerType = twrType;
	vel = 300;

	if (towerType == GREEN) {
		tileset = new TileSet("Resources/powerGreen.png", 36, 12, 3, 3);
		animation = new Animation(tileset, 0.5f, true);

		vel = 300;

		type = POWERGREEN;
		BBox(new Rect(-18, -6, 17, 5));
	}

	if (towerType == YELLOW) {
		tileset = new TileSet("Resources/powerYellow.png", 101, 60, 7, 21);
		animation = new Animation(tileset, 0.1f, false);

		uint yellownormal[7] = { 0, 1, 2, 3, 4, 5, 6 };
		uint yellowexplosion[14] = { 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

		animation->Add(YELLOWNORMAL, yellownormal, 7);
		animation->Add(YELLOWEXPLOSION, yellowexplosion, 14);

		vel = 150;
		type = POWERYELLOW;
		BBox(new Rect(-14, -20, 13, 5));
	}

	if (towerType == BLUE) {
		tileset = new TileSet("Resources/powerBlue.png", 100, 100, 12, 12);
		animation = new Animation(tileset, 0.05f, false);

		vel = 0;
		type = POWERBLUE;
		auxHit = true;
		BBox(new Circle(40));
	}


	cdr = 50;

	imX = posX;
	imY = posY;
	dstX = toX;
	dstY = toY;

	if (type != POWERBLUE) {
		MoveTo(imX, imY);
		hitedTimer.Start();
		auxHit = true;
	}

	contEnemy = 0;

	// new Rect(- 18, -6, 17, 5)

}

TowerPower::~TowerPower() {
	delete tileset;
	delete animation;
}

void TowerPower::Update() {
	
	animation->NextFrame();

	if (Type() == POWERGREEN) {

		float deltaX = dstX - imX;
		float deltaY = dstY - imY;

		float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

		if (distance > 0) {
			float directionX = deltaX / distance;
			float directionY = deltaY / distance;

			RotateTo(180);

			Translate(directionX * vel * gameTime, directionY * vel * gameTime);
		}

		// pra deletar os poderes caso saiam da tela
		if (x + tileset->TileWidth() / 2.0f > window->Width())
			TowerDefense::scene->Delete();

		if (x - tileset->TileWidth() / 2.0f < 0)
			TowerDefense::scene->Delete();

		if (y + tileset->TileHeight() / 2.0f > window->Height())
			TowerDefense::scene->Delete();

		if (y - tileset->TileHeight() / 2.0f < 0)
			TowerDefense::scene->Delete();

		cdr--;
	}

	if (Type() == POWERYELLOW) {
		animation->Select(powerState);

		float deltaX = dstX - imX;
		float deltaY = dstY - imY;

		float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

		if (distance > 0) {

			float directionX = deltaX / distance;
			float directionY = deltaY / distance;

			float distanceToTravel = vel * gameTime, distance;

			Translate(directionX * distanceToTravel, directionY * distanceToTravel);
		}
		else {
			vel = 0;
		}

		cdr--;

		if (animation->Frame() == 20) {
			TowerDefense::scene->Delete();
		}

	}

	if (Type() == POWERBLUE) {
		if (animation->Frame() == 11) {
			TowerDefense::scene->Delete();
		}

		if (contEnemy == 0) {
			MoveTo(dstX, dstY);
		}

		cdr--;
	}
	
}

void TowerPower::OnCollision(Object* obj) {

	if (obj->Type() == ENEMY) {

		Enemy* enemy = dynamic_cast<Enemy*>(obj);

		if (Type() == POWERYELLOW) {
			powerState = YELLOWEXPLOSION;
			vel = 0;

			if (animation->Frame() < 20) {
				enemy->hited = true;
			}
		}

		if (Type() == POWERBLUE) {

			// fazer sentido de bomba que gruda no mob
			if (contEnemy == 0) {
				firstEnemy = enemy;
				contEnemy++;
			}
			else {
				contEnemy++;
			}
		
			if (firstEnemy != nullptr) {
				MoveTo(firstEnemy->X(), firstEnemy->Y());
			}

			enemies.insert(enemy);

			if (animation->Frame() == 10) {
				if (canHit) {
					for (const auto& en : enemies) {
						en->life--;
					}
					canHit = false;
				}
			}
			
		}

	}

}