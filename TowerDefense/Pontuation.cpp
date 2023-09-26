#include "Pontuation.h"
#include "Level2.h"
#include "Font.h"
#include "TowerDefense.h"


Scene* Pontuation::scene = nullptr;
void Pontuation::Init() {

    ground = new Sprite("Resources/ground.png");
}
void Pontuation::Update() {
  
    if (window->KeyPress(VK_SPACE)) {
        TowerDefense::audios->Stop(LEVEL2);
        TowerDefense::NextLevel<Level2>();
    }
}

void Pontuation::Draw() {
    ground->Draw(window->CenterX(), window->CenterY(), Layer::BACK);

}

void Pontuation::Finalize() {
    delete ground;
}

