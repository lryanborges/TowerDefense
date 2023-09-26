#include "Pontuation.h"
#include "Level2.h"
#include "Font.h"
#include "TowerDefense.h"


Scene* Pontuation::scene = nullptr;
void Pontuation::Init() {
    TowerDefense::audios->Play(TYPINGMACHINE,false);
    ground = new Sprite("Resources/ground.png");
    pointsBar = new Sprite("Resources/pointsBar.png");
    soul = new Sprite("Resources/soul.png");
}
void Pontuation::Update() {
  

    if (!dw) {
        fm++;
        if (fm >= mfm) {
            dw = true;
            fm = 0;
        }
    }

    if (window->KeyPress(VK_SPACE)) {
        TowerDefense::audios->Stop(TYPINGMACHINE);
        TowerDefense::NextLevel<Level2>();
    }
}

void Pontuation::Draw() {
    ground->Draw(window->CenterX(), window->CenterY(), Layer::BACK, 1.0f, 0.0f, {0.8, 0.8, 0.8, 1.0});
    pointsBar->Draw(window->CenterX(), window->CenterY() - 30, Layer::LOWER);
    Color white(1.0f, 1.0f, 1.0f, 1.0f);
    Color black(0.0f, 0.0f, 0.0f, 1.0f);
    string pontos = std::to_string(TowerDefense::pontos);
    TowerDefense::placar->Spacing(72);
    TowerDefense::placar->Draw(window->CenterX() - 152, window->CenterY() - 120, "Almas libertas: " + pontos, white, Layer::FRONT - 0.002f, 0.25f);
    TowerDefense::placar->Draw(window->CenterX() - 150, window->CenterY() - 120, "Almas libertas: " + pontos, black, Layer::UPPER - 0.002f, 0.25f);
    soul->Draw(window->CenterX() - 180, window->CenterY() - 118), Layer::FRONT;

    TowerDefense::placar->Draw(window->CenterX() - 142, window->CenterY() - 60, "Began to rain...", white, Layer::FRONT - 0.002f, 0.25f);
    TowerDefense::placar->Draw(window->CenterX() - 140, window->CenterY() - 60, "Began to rain...", black, Layer::UPPER - 0.002f, 0.25f);
    TowerDefense::placar->Draw(window->CenterX() - 232, window->CenterY() - 30, "The vegetables are stronger", white, Layer::FRONT - 0.002f, 0.25f);
    TowerDefense::placar->Draw(window->CenterX() - 230, window->CenterY() - 30, "The vegetables are stronger", black, Layer::UPPER - 0.002f, 0.25f);

    if (dw) {
        TowerDefense::placar->Draw(282, 400, "PRESS SPACE TO CONTINUE", white, Layer::FRONT, 0.25f);
        TowerDefense::placar->Draw(280, 400, "PRESS SPACE TO CONTINUE", black, Layer::UPPER, 0.25f);
        fm++;
        if (fm >= mfm) {
            dw = false;
            fm = 0;
        }

    }
}

void Pontuation::Finalize() {
    delete soul;
    delete ground;
    delete pointsBar;
}

