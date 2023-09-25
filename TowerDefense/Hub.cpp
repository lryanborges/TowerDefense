#include "Hub.h"
#include "Object.h"
#include "TowerDefense.h"


Hub::Hub()
{	
	image = new Image("Resources/Hub.png");
	sprite = new Sprite(image);

	MoveTo(window->CenterX(), 640);

	BBox(new Rect(-window->CenterX(), -40, window->CenterX() - 1, 39));

	type = HUB;

}

Hub::~Hub()
{
	delete image;
	delete sprite;

}

void Hub::Update()
{
}

void Hub::Draw()
{
	sprite->Draw(x ,y , Layer::UPPER);

}

void Hub::OnCollision(Object* obj)
{
}

