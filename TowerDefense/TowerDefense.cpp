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
#include "Level1.h"
#include "TelaFinal.h"
#include "TelaInicio.h"

Audio * TowerDefense::audios = nullptr;
Game* TowerDefense::level = nullptr;
Scene* TowerDefense::scene = nullptr;
Mouse* TowerDefense::mouse = nullptr;
Hub* TowerDefense::hub = nullptr;
Priest* TowerDefense::priest = nullptr;
int TowerDefense::souls = 3;
Font* TowerDefense::placar = nullptr;

void TowerDefense::Init() {

    audios = new Audio();
    audios->Add(INTRO, "Resources/intro.wav");
    audios->Add(TOWERSET, "Resources/tower.wav");


    level = new TelaInicio();

    level->Init();

    scene = TelaInicio::scene;

    mouse = new Mouse();
    scene->Add(mouse, MOVING);

    hub = new Hub();
    scene->Add(hub, STATIC);
    scene->Remove(hub, STATIC);

    priest = new Priest();
    scene->Add(priest, STATIC);
    scene->Remove(priest, STATIC);

    placar = new Font("Resources/FixedSys30.png");
    placar->Spacing(72);

}

void TowerDefense::Finalize() {
    level->Finalize();
    delete priest;
    delete hub;
    delete mouse;
    delete placar;
    delete level;
    delete audios;
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

