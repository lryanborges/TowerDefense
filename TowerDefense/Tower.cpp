#include "Tower.h"

Tower::Tower() {
	sprite = new Sprite("Resources/statue.png");

	MoveTo(window->CenterX(), window->CenterY());
}

Tower::~Tower() {
	delete sprite;
}

void Tower::Update() {

}

void Tower::OnCollision() {

}