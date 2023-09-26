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
    audios->Add(MAIN, "Resources/main.wav");
    audios->Add(LEVEL2, "Resources/level2.wav");
    audios->Add(TOWERSET, "Resources/tower.wav", 2);
    audios->Add(GAMEOVER, "Resources/Game_Lose.wav");
    audios->Add(ZOMBIE1, "Resources/zombie1.wav", 2);
    audios->Add(ZOMBIE2, "Resources/zombie2.wav", 2);
    audios->Add(BONES, "Resources/bones.wav", 2);
    audios->Add(LAUGH, "Resources/laugh.wav", 2);
    audios->Add(TYPINGMACHINE, "Resources/typing.wav", 2);
    audios->Add(FIRESPELL, "Resources/fire.wav", 5);
    audios->Add(FREEZESPELL, "Resources/freeze.wav", 5);
    audios->Add(MAGICSPELL, "Resources/Spell.wav", 5);
    audios->Add(DIVINESPELL, "Resources/divine.wav", 5);
    audios->Add(WINDSPELL, "Resources/wind.wav", 5);
    audios->Volume(FIRESPELL, 0.08f);
    audios->Volume(FREEZESPELL, 0.08f);
    audios->Volume(MAGICSPELL, 0.08f);
    audios->Volume(DIVINESPELL, 0.08f);
    audios->Volume(WINDSPELL, 0.08f);

    audios->Volume(INTRO, 0.08f);
    audios->Volume(LEVEL2, 0.08f);
    audios->Volume(TOWERSET, 3.0f);
    audios->Volume(MAIN, 0.08f);
    audios->Volume(GAMEOVER, 0.08f);

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

