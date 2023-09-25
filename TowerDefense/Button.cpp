#include "Button.h"
#include "TowerDefense.h"
#include "Tower.h"
#include "Priest.h"

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
	
	switch (t) {
	case REDB:
		MoveTo(610, 645);
		break;
	case PURPLEB:
		MoveTo(680, 645);
		break;
	case BLUEB:
		MoveTo(750, 645);
		break;
	case YELLOWB:
		MoveTo(820, 645);
		break;
	case GREENB:
		MoveTo(890, 645);
		break;
	}

	BBox(new Rect(-28, -28, 27, 27));

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

	button->Draw(x, y, Layer::FRONT);
	
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
			if (window->KeyPress(VK_LBUTTON) && TowerDefense::mouse->State() != COLISAO) {
				if (!TowerDefense::mouse->carrying) {
					Tower* tw = new Tower(BLUE);
					TowerDefense::scene->Add(tw, STATIC);
					Mouse::towerCarry = tw;
					TowerDefense::mouse->carrying = true;
				}
			}
			break;
		case YELLOWB:
			// Gerar torre amarela
			if (window->KeyPress(VK_LBUTTON) && TowerDefense::mouse->State() != COLISAO) {
				if (!TowerDefense::mouse->carrying) {
					Tower* tw = new Tower(YELLOW);
					TowerDefense::scene->Add(tw, STATIC);
					Mouse::towerCarry = tw;
					TowerDefense::mouse->carrying = true;
				}
			}
			break;
		case GREENB:
			// Gerar torre verde
			if (window->KeyPress(VK_LBUTTON) && TowerDefense::mouse->State() != COLISAO) {
				if (!TowerDefense::mouse->carrying) {
					Tower* tw = new Tower(GREEN);
					TowerDefense::scene->Add(tw, STATIC);
					Mouse::towerCarry = tw;
					TowerDefense::mouse->carrying = true;
				}
			}
			break;
		}
	}

}
