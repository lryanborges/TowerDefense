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
#include "Hub.h"

Game* TowerDefense::level = nullptr;
Scene* TowerDefense::scene = nullptr;
Mouse* TowerDefense::mouse = nullptr;
Hub* TowerDefense::hub = nullptr;

void TowerDefense::Init() {

    level = new Level1();

    level->Init();

    scene = Level1::scene;

    mouse = new Mouse();
    scene->Add(mouse, MOVING);

    hub = new Hub();
    scene->Add(hub, STATIC);

    Button* button1 = new Button(REDB);
    Button* button2 = new Button(PURPLEB);
    Button* button3 = new Button(BLUEB);
    Button* button4 = new Button(YELLOWB);
    Button* button5 = new Button(GREENB);

    scene->Add(button1, STATIC);
    scene->Add(button2, STATIC);
    scene->Add(button3, STATIC);
    scene->Add(button4, STATIC);
    scene->Add(button5, STATIC);

}

void TowerDefense::Finalize() {
    level->Finalize();
    delete mouse;
    delete level;
}

void TowerDefense::Update() {
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
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new TowerDefense());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

