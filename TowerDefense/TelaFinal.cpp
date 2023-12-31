#include "TelaFinal.h"
#include "TowerDefense.h"
#include "TelaInicio.h"

void TelaFinal::Init(){
	TowerDefense::audios->Play(GAMEOVER, false);
	background = new Sprite("Resources/end.png");
	text = new Font("Resources/text.png");
	text->Spacing(65);

	Priest::life = 10;
}

void TelaFinal::Update(){
	if (window->KeyPress(VK_SPACE)) {
		TowerDefense::audios->Stop(GAMEOVER);
		TowerDefense::NextLevel<TelaInicio>();
	}
		

	if (!dw) {
		fm++;
		if (fm >= mfm) {
			dw = true;
			fm = 0;
		}
	}
	}

void TelaFinal::Draw(){
	background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
	Color Black(0.0f, 0.0f, 0.0f, 1.0f);
	Color White(1.0f, 1.0f, 1.0f, 1.0f);
	Color Red(0.7f, 0.1f , 0.1f, 1);
	text->Draw(180, 130, "You died!!", White, Layer::UPPER, 1.0f);
	text->Draw(182, 130, "You died!!", Black, Layer::UPPER, 1.0f);
	if (dw) {
		text->Draw(200, 540, "PRESS SPACE TO RESTART THE GAME", White, Layer::UPPER, 0.3f);
		text->Draw(202, 540, "PRESS SPACE TO RESTART THE GAME", Black, Layer::FRONT, 0.3f);
		fm++;
		if (fm >= mfm) {
			dw = false;
			fm = 0;
		}

	}
}

void TelaFinal::Finalize(){

	delete background;
		delete text;
}
