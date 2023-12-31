#include "TelaInicio.h"
#include "TowerDefense.h"
#include "Level1.h"

Scene* TelaInicio::scene = nullptr;
void TelaInicio::Init()
{
	TowerDefense::audios->Play(INTRO, true);
	
	scene = new Scene();

	background = new Sprite("Resources/bg.png");
	text = new Font("Resources/text.png");
	text->Spacing(65);

	TowerDefense::pontos = 0;
}

void TelaInicio::Update(){
	if (!dw) {
		fm++;
		if (fm >= mfm) {
			dw = true;
			fm = 0;
		}
	}

	if (window->KeyPress(VK_SPACE)) {
		TowerDefense::audios->Stop(INTRO);
		TowerDefense::NextLevel<Level1>();
	}
}

void TelaInicio::Draw(){
	background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
	Color Black(0.0f, 0.0f, 0.0f, 1.0f);
	Color White(1.0f, 1.0f, 1.0f, 1.0f);
	text->Draw(150, 230, "Village of Lost Souls", White, Layer::UPPER, 0.51f);
	text->Draw(151, 230,"Village of Lost Souls", Black, Layer::UPPER, 0.51f);
	text->Draw(90, 300, "Cleric Elara VS The Vegetable Menace", White, Layer::UPPER, 0.35f);
	text->Draw(91, 300, "Cleric Elara VS The Vegetable Menace", Black, Layer::UPPER, 0.35f);
	if (dw) {
		text->Draw(200, 475, "PRESS SPACE TO START THE GAME", White, Layer::UPPER, 0.3f);
		text->Draw(202, 475, "PRESS SPACE TO START THE GAME", Black, Layer::FRONT, 0.3f);
		fm++;
		if (fm >= mfm) {
			dw = false;
			fm = 0;
		}

	}
}

void TelaInicio::Finalize()
{
	delete background;
	delete text;
	scene->Remove(TowerDefense::mouse, MOVING);
	delete scene;
}
