#include "TowerDefense.h"
#include "Engine.h"
#include "Enemy.h"
#include "Tower.h"
#include "Rain.h"
#include "DirectionPoint.h"
#include "Ghost.h"
#include "Grass.h"
#include "Floor.h"
#include "Mouse.h"
#include "Level1.h"

Game* TowerDefense::level = nullptr;
Scene* TowerDefense::scene = nullptr;
Mouse* TowerDefense::mouse = nullptr;
void TowerDefense::Init() {

    level = new Level1();

    level->Init();

    scene = Level1::scene;

    mouse = new Mouse();
    scene->Add(mouse, MOVING);

}

void TowerDefense::Finalize() {
    level->Finalize();
    delete mouse;
    delete level;
}

void TowerDefense::Update() {
    if (window->KeyPress(VK_LBUTTON) && TowerDefense::mouse->State() != COLISAO) {
        Tower* tw = new Tower(YELLOW);
        tw->MoveTo(window->MouseX(), window->MouseY() - (tw->Height()) / 3);
        scene->Add(tw, MOVING);
    }
    level->Update();
}

void TowerDefense::Draw() {
    level->Draw();
}

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine* engine = new Engine();

    // configura motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(968, 680);
    engine->window->Color(200, 24, 240);
    engine->window->Title("Tower Defense");
    //engine->window->Icon(IDI_ICON);
    //engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new TowerDefense());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

