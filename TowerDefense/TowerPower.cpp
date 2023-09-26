#include "TowerPower.h"
#include "TowerDefense.h"
#include <math.h>
#include "Enemy.h"
#include "Tower.h"
#include <cmath>

int TowerPower::cdr;
TowerPower::TowerPower(int posX, int posY, int toX, int toY, uint twrType) {

	uint towerType = twrType;
	vel = 300;

	if (towerType == GREEN) {
		TowerDefense::audios->Play(WINDSPELL, false);
		tileset = new TileSet("Resources/powerGreen.png", 36, 12, 3, 3);
		animation = new Animation(tileset, 0.5f, true);

		vel = 300;

		type = POWERGREEN;
		BBox(new Rect(-18, -6, 17, 5));
	}

	if (towerType == YELLOW) {
		TowerDefense::audios->Play(DIVINESPELL, false);
		tileset = new TileSet("Resources/powerYellow.png", 101, 60, 7, 21);
		animation = new Animation(tileset, 0.1f, false);

		uint yellownormal[7] = { 0, 1, 2, 3, 4, 5, 6 };
		uint yellowexplosion[14] = { 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

		animation->Add(YELLOWNORMAL, yellownormal, 7);
		animation->Add(YELLOWEXPLOSION, yellowexplosion, 14);

		canHit = true;
		powerState = YELLOWNORMAL;
		vel = 80;
		type = POWERYELLOW;
		BBox(new Rect(-14, -20, 13, 5));
	}

	if (towerType == BLUE) {
		TowerDefense::audios->Play(FREEZESPELL, false);
		tileset = new TileSet("Resources/powerBlue.png", 100, 100, 12, 12);
		animation = new Animation(tileset, 0.05f, false);

		vel = 0;
		type = POWERBLUE;
		auxHit = true;
		BBox(new Circle(40));
	}

	if (towerType == RED) {
		TowerDefense::audios->Play(FIRESPELL, false);
		tileset = new TileSet("Resources/powerRed.png", 40, 35, 5, 5);
		animation = new Animation(tileset, 0.1f, true);

		uint redstart[2] = { 0, 1 };
		uint rednormal[1] = { 1 };
		uint redexplosion[3] = { 2, 3, 4 };

		animation->Add(REDSTART, redstart, 2);
		animation->Add(REDNORMAL, rednormal, 1);
		animation->Add(REDEXPLOSION, redexplosion, 3);

		powerState = REDSTART;
		vel = 250;
		type = POWERRED;
		BBox(new Rect(-20, -17, 19, 17));
	}

	if (towerType == PURPLE) {
		TowerDefense::audios->Play(MAGICSPELL, false);
		tileset = new TileSet("Resources/powerPurple.png", 95, 70, 5, 5);
		animation = new Animation(tileset, 0.3f, true);

		uint purplenormal[2] = { 0, 1 };
		uint purplefinished[3] = { 2, 3, 4 };

		animation->Add(PURPLENORMAL, purplenormal, 2);
		animation->Add(PURPLEFINISHED, purplefinished, 3);

		powerState = PURPLENORMAL;
		vel = 0;
		type = POWERPURPLE;
		BBox(new Circle(50));
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

		// calcular as diferenças em X e Y
		float deltaX = dstX - imX;
		float deltaY = dstY - imY;

		// calcular o ângulo em graus
		float angle = atan2(deltaY, deltaX) * (180.0f / 3.1415926535);

		// garantir que o ângulo está no intervalo [0, 360)
		if (angle < 0) {
			angle += 360.0f;
		}

		// calcular a distância entre os pontos
		float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

		// se houver uma distância, mova o objeto
		if (distance > 0) {
			// normalizar a direção
			float directionX = deltaX / distance;
			float directionY = deltaY / distance;

			RotateTo(angle);
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

		if (!canHit) {
			firstEnemy = nullptr;
		}

		if (firstEnemy != nullptr) {
			if (canHit) {
				if (firstEnemy != nullptr) {
					//MoveTo(firstEnemy->X(), firstEnemy->Y());
				}
			}
		}

		cdr--;
	}

	if (Type() == POWERRED) {
		animation->Select(powerState);

		if (animation->Frame() == 1) {
			powerState = REDNORMAL;
		}

		float deltaX = dstX - imX;
		float deltaY = dstY - imY;

		float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);
		
		// calcular o ângulo em graus
		float angle = atan2(deltaY, deltaX) * (180.0f / 3.1415926535);

		// garantir que o ângulo está no intervalo [0, 360)
		if (angle < 0) {
			angle += 360.0f;
		}


		if (distance > 0) {

			float directionX = deltaX / distance;
			float directionY = deltaY / distance;

			float distanceToTravel = vel * gameTime, distance;

			RotateTo(angle);
			Translate(directionX * distanceToTravel, directionY * distanceToTravel);
		}

		if (animation->Frame() == 4) {
			TowerDefense::scene->Delete();
		}
	}

	if (Type() == POWERPURPLE) {
		animation->Select(powerState);


		if (contEnemy == 0) {
			MoveTo(dstX, dstY);
		}

		if (hitedTimer.Elapsed(3.0)) {
			powerState = PURPLEFINISHED;
		}

		if (Frame() == 4) {
			TowerDefense::scene->Delete();
		}

	}
	
}

void TowerPower::Draw() {
	if (Type() == POWERPURPLE) {
		animation->Draw(x, y, Layer::UPPER + 0.01, 1.1, rotation);
	}
	else {
		animation->Draw(x, y, Layer::FRONT, 1.1, rotation);
	}

}

void TowerPower::OnCollision(Object* obj) {

	if (obj->Type() == ENEMY) {

		Enemy* enemy = dynamic_cast<Enemy*>(obj);

		if (Type() == POWERYELLOW) {
			powerState = YELLOWEXPLOSION;
			vel = 0;

			enemies.insert(enemy);

			if (animation->Frame() >= 6) {
					for (const auto& en : enemies) {
						en->life--;
					}
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

		if (Type() == POWERRED) {

			powerState = REDEXPLOSION;

			enemies.insert(enemy);

				if (canHit) {
					for (const auto& en : enemies) {
						en->life--;	
					}
					canHit = false;
				}
			
		}

		if (Type() == POWERPURPLE) {

			if (contEnemy == 0) {
				hitedTimer.Start();
				firstEnemy = enemy;
				contEnemy++;
			}
			else {
				contEnemy++;
			}

			enemies.insert(enemy);

			if (hitedTimer.Elapsed(2.0)) {
				canHit = true;
			}
			if (animation->Frame() == 1) {
				if (canHit) {
					enemy->life--;
					enemies.clear();
					canHit = false;
				}
			}
		}

	}

}