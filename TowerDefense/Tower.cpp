#include "Tower.h"
#include "TowerDefense.h"

Tower::Tower() {
	sprite = new Sprite("Resources/statueGreen.png");

	BBox(new Rect(-24, -2, 23, 43));

	MoveTo(window->CenterX(), window->CenterY());

	type = TOWER;
}

Tower::~Tower() {
	delete sprite;
}

void Tower::Update() {

}

void Tower::Draw() {
	sprite->Draw(x, y, z);

	// , 1.0f, 0.0f, {1.3, 1, 1, 1} -> vermelho soft
	// {2, 35, 212, 1} -> cristal
}

void Tower::OnCollision() {

}