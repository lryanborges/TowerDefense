#include "TowerPower.h"
#include "TowerDefense.h"
#include <math.h>

int TowerPower::cdr;
TowerPower::TowerPower(int posX, int posY, int toX, int toY) {
	tileset = new TileSet("Resources/powerGreen.png", 36, 12, 3, 3);
	animation = new Animation(tileset, 0.5f, true);
	cdr = 50;

	vel = 300;

	imX = posX;
	imY = posY;
	dstX = toX;
	dstY = toY;

	MoveTo(imX, imY);

	// new Rect(- 18, -6, 17, 5)
	BBox(new Rect(-18, -6, 17, 5));

	type = POWER;
}

TowerPower::~TowerPower() {
	delete tileset;
	delete animation;
}

void TowerPower::Update() {
	animation->NextFrame();
	
	float deltaX = dstX - imX;
	float deltaY = dstY - imY;

	// Calcular a magnitude do vetor de direção
	float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

	// Certificar-se de que não estamos dividindo por zero (verifique se a distância é maior que zero)
	if (distance > 0) {
		// Normalizar o vetor de direção
		float directionX = deltaX / distance;
		float directionY = deltaY / distance;

		// Calcular o ângulo de rotação em radianos
		//float angle = std::atan2(directionY, directionX);

		// Mover o disparo na direção correta
		//RotateTo(angle * 250 * gameTime); // Rotacionar o objeto na direção correta

		// Mover o disparo na direção correta
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

void TowerPower::OnCollision(Object* obj) {
	if (obj->Type() == ENEMY) {
		//TowerDefense::scene->Delete();
	}
}