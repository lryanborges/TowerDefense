#include "TowerDefense.h"
#include "Engine.h"
#include "Enemy.h"

Scene* TowerDefense::scene = nullptr;

void TowerDefense::Init() {
    scene = new Scene();

    TileSet* tilesetCenoura = new TileSet("Resources/cenoura.png", 112, 112, 8, 24);
    TileSet* tilesetBatata = new TileSet("Resources/batata.png", 112, 112, 8, 24);
    TileSet* tilesetCebola = new TileSet("Resources/cebola.png", 112, 112, 8, 24);
    TileSet* tilesetTomate = new TileSet("Resources/tomate.png", 112, 112, 8, 24);
    TileSet* tilesetBrocolis = new TileSet("Resources/brocolis.png", 112, 112, 8, 24);
    TileSet* tilesetCheiroVerde = new TileSet("Resources/cheiroverde.png", 112, 112, 8, 24);
    TileSet* tilesetMilho = new TileSet("Resources/milho.png", 112, 112, 8, 24);
    TileSet* tilesetAlface = new TileSet("Resources/alface.png", 112, 112, 8, 24);
    TileSet* tilesetCouveFlor = new TileSet("Resources/couveflor.png", 112, 112, 8, 24);

    Enemy* enemy = new Enemy(tilesetCouveFlor, COUVEFLOR);
    scene->Add(enemy, MOVING);

    /*Enemy* brocolis = new Enemy(tilesetBrocolis, BROCOLIS);
    scene->Add(brocolis, MOVING);
    brocolis->MoveTo(window->CenterX(), window->CenterY());*/

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

