#include "Button.h"
#include "TowerDefense.h"

Button::Button(int b){
	t = b;

	switch (t){

	case REDB:
		iconB = new Image("Resources/button/icon1B.png");
		iconD = new Image("Resources/button/icon1D.png");
		iconA = new Image("Resources/button/icon1A.png");
		button = new Sprite(iconD);
		break;
	case PURPLEB:
		iconA = new Image("Resources/button/icon2A.png");
		iconD = new Image("Resources/button/icon2D.png");
		iconB = new Image("Resources/button/icon2B.png");
		button = new Sprite(iconD);
		break;
	case BLUEB:
		iconA = new Image("Resources/button/icon3A.png");
		iconD = new Image("Resources/button/icon3D.png");
		iconB = new Image("Resources/button/icon3B.png");
		button = new Sprite(iconD);
		break;
	case YELLOWB:
		iconB = new Image("Resources/button/icon4B.png");
		iconA = new Image("Resources/button/icon4A.png");
		iconD = new Image("Resources/button/icon4D.png");
		button = new Sprite(iconD);
		break;
	case GREENB:
		iconA = new Image("Resources/button/icon5A.png");
		iconD = new Image("Resources/button/icon5D.png");
		iconB = new Image("Resources/button/icon5B.png");
		button = new Sprite(iconD);
		break;
	default:
		iconB = new Image("Resources/button/icon1B.png");
		iconD = new Image("Resources/button/icon1D.png");
		iconA = new Image("Resources/button/icon1A.png");
		button = new Sprite(iconD);
		t = REDB;
		break;
	}
	
	BBox(new Rect(-64, -64, 63, 63));

type = BUTTON;
}

Button::~Button()
{
	delete iconA;

	delete iconD;

	delete iconB;

	delete button;
}

void Button::Update(){
	
}

void Button::Draw(){
	
	switch (t) {
	case REDB:
		button->Draw(610, 645, Layer::FRONT);
		break;
	case PURPLEB:
		button->Draw(680, 645, Layer::FRONT);
		break;
	case BLUEB:
		button->Draw(750, 645, Layer::FRONT);
		break;
	case YELLOWB:
		button->Draw(820, 645, Layer::FRONT);
		break;
	case GREENB:
		button->Draw(890, 645, Layer::FRONT);
		break;
	}


}

void Button::OnCollision(Object* obj){
	if (obj->Type() == MOUSE) {
		switch (t) {
		case REDB:
			// Gerar torre vermelha
			
			break;
		case PURPLEB:
			// Gerar torre roxa
			break;
		case BLUEB:
			// Gerar torre azul 
			break;
		case YELLOWB:
			// Gerar torre amarela
			break;
		case GREENB:
			// Gerar torre verde
			break;
		}
	}

}
