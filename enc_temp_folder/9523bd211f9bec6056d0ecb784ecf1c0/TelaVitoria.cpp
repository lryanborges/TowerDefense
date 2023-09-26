#include "TelaVitoria.h"
#include "TowerDefense.h"
#include "TelaInicio.h"

void TelaVitoria::Init()
{
	TowerDefense::audios->Play(GAMEWIN, true);
	bg = new Sprite("Resources/win.png");
	text = new Font("Resources/text.png");
	text->Spacing(65);
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
	text->Draw(90, 130, "Você Protegeu a Vila!!", Black, Layer::UPPER, 0.4f);
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
