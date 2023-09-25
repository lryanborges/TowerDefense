#include "Hub.h"
#include "Object.h"


Hub::Hub()
{	
	image = new Image("Resources/Hub.png");
	sprite = new Sprite(image);
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
	sprite->Draw(485,640 , Layer::UPPER);

}

void Hub::OnCollision(Object* obj)
{
}

