#include "Hub.h"
#include "Object.h"
#include "TowerDefense.h"


Hub::Hub()
{	
	image = new Image("Resources/Hub.png");
	sprite = new Sprite(image);
	soul = new Sprite("Resources/soul.png");

	MoveTo(window->CenterX(), 640);

	BBox(new Rect(-window->CenterX(), -40, window->CenterX() - 1, 39));

	type = HUB;

}

Hub::~Hub()
{
	delete soul;
	delete image;
	delete sprite;

}

void Hub::Update()
{
}

void Hub::Draw()
{
	sprite->Draw(x, y, Layer::UPPER);
	soul->Draw(x + 32, y + 7, Layer::UPPER - 0.1);
	Color white(1.0f, 1.0f, 1.0f, 1.0f);
	string qtdSouls = std::to_string(TowerDefense::souls);
	TowerDefense::placar->Draw(x + 64, y + 4, qtdSouls, white, Layer::UPPER - 0.1f, 0.2f);
	Color black(0.0f, 0.0f, 0.0f, 1.0f);
	string pontos = std::to_string(TowerDefense::pontos);
	TowerDefense::placar->Spacing(66);
	TowerDefense::placar->Draw(x - 72, y + 2, "Points:" + pontos, black, Layer::UPPER - 0.2f, 0.15f);
	TowerDefense::placar->Draw(x - 72.5, y + 2, "Points:" + pontos, white, Layer::UPPER - 0.1f, 0.15f);
}

void Hub::OnCollision(Object* obj)
{
}

