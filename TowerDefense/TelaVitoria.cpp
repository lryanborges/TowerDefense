#include "TelaVitoria.h"
#include "TowerDefense.h"
#include "TelaInicio.h"

void TelaVitoria::Init()
{
	TowerDefense::audios->Play(GAMEWIN, true);
	bg = new Sprite("Resources/win.png");
	text = new Font("Resources/text.png");
	text->Spacing(65);

	Priest::life = 10;
}

void TelaVitoria::Update()
{

	if (window->KeyPress(VK_SPACE)) {
		TowerDefense::audios->Stop(GAMEWIN);
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

void TelaVitoria::Draw()
{
	bg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
	Color Black(0.0f, 0.0f, 0.0f, 1.0f);
	Color White(1.0f, 1.0f, 1.0f, 1.0f);
	Color Red(0.7f, 0.1f, 0.1f, 1);
	text->Draw(170, 160, "You protected the village!!", Black, Layer::UPPER, 0.3f);
	text->Draw(172, 160, "You protected the village!!", White, Layer::UPPER, 0.3f);
	text->Draw(260, 200, "Freed souls: 100", Black, Layer::UPPER, 0.3f);
	text->Draw(262, 200, "Freed souls: 100", White, Layer::UPPER, 0.3f);
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

void TelaVitoria::Finalize()
{
}
