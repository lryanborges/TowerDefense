#include "TowerDefense.h"
#include "Engine.h"
#include "Enemy.h"

Scene* TowerDefense::scene = nullptr;

void TowerDefense::Init() {
    scene = new Scene();

    Enemy* enemy = new Enemy();
    scene->Add(enemy, MOVING);

}

void TowerDefense::Finalize() {
    delete scene;
}

void TowerDefense::Update() {
    scene->Update();
    scene->CollisionDetection();
}

void TowerDefense::Draw() {
    scene->Draw();
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

