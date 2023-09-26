#include "Pontuation.h"
#include "Level2.h"
#include "Font.h"
#include "TowerDefense.h"


Scene* Pontuation::scene = nullptr;
void Pontuation::Init() {

    ground = new Sprite("Resources/ground.png");
    pointsBar = new Sprite("Resources/pointsBar.png");
    soul = new Sprite("Resources/soul.png");
}
void Pontuation::Update() {
  
    if (window->KeyPress(VK_SPACE)) {
        TowerDefense::audios->Stop(LEVEL2);
        TowerDefense::NextLevel<Level2>();
    }
}

void Pontuation::Draw() {
    ground->Draw(window->CenterX(), window->CenterY(), Layer::BACK, 1.0f, 0.0f, {0.8, 0.8, 0.8, 1.0});
    pointsBar->Draw(window->CenterX(), window->CenterY() - 30, Layer::LOWER);
    Color white(1.0f, 1.0f, 1.0f, 1.0f);
    string souls = std::to_string(TowerDefense::souls);
    TowerDefense::placar->Spacing(72);
    TowerDefense::placar->Draw(window->CenterX() - 150, window->CenterY() - 120, "Almas libertas: " + souls, white, Layer::FRONT - 0.002f, 0.25f);
    soul->Draw(window->CenterX() - 180, window->CenterY() - 118), Layer::FRONT;
}

void Pontuation::Finalize() {
    delete soul;
    delete ground;
    delete pointsBar;
}

