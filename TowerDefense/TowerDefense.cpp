#include "TowerDefense.h"
#include "Engine.h"
#include "Enemy.h"
#include "Tower.h"
#include "Rain.h"
#include "DirectionPoint.h"
#include "Ghost.h"
#include "Grass.h"

Scene* TowerDefense::scene = nullptr;

void TowerDefense::Init() {

    TileSet* tilesetCenoura = new TileSet("Resources/cenoura.png", 40, 50, 8, 30);
    TileSet* tilesetBatata = new TileSet("Resources/batata.png", 40, 50, 8, 30);
    TileSet* tilesetCebola = new TileSet("Resources/cebola.png", 40, 50, 8, 30);
    TileSet* tilesetNabo = new TileSet("Resources/nabo.png", 40, 50, 8, 30);
    TileSet* tilesetBrocolis = new TileSet("Resources/brocolis.png", 40, 50, 8, 30);
    TileSet* tilesetCheiroVerde = new TileSet("Resources/cheiroverde.png", 40, 50, 8, 30);
    TileSet* tilesetMilho = new TileSet("Resources/milho.png", 40, 50, 8, 30);
    TileSet* tilesetAlface = new TileSet("Resources/alface.png", 40, 50, 8, 30);
    TileSet* tilesetCouveFlor = new TileSet("Resources/couveflor.png", 40, 50, 8, 30);

    TileSet* ghost = new TileSet("Resources/ghost.png", 32, 32, 10, 10);

    rain = new TileSet("Resources/rain.png", 12, 12, 3, 3);
    ground = new Sprite("Resources/ground.png");
    floor = new Sprite("Resources/floor.png");

    scene = new Scene();

    Grass* grass = new Grass(300, 300, 1);
    scene->Add(grass, STATIC);

    Ghost* fant = new Ghost(ghost);
    scene->Add(fant, STATIC);
    fant->MoveTo(200, 200);

    // ------------------------------------------------------------------------------------
    //                DEFINIÇÃO DOS DIRECTIONS POINTS PRA ESSA FASE
    // ------------------------------------------------------------------------------------

    DirectionPoint* point1 = new DirectionPoint(UP);
    point1->MoveTo(window->CenterX() - 360, window->CenterY() + 20);    // -395 é bem no meio (do primeiro)
    scene->Add(point1, STATIC);

    DirectionPoint* point2 = new DirectionPoint(RIGHT);
    point2->MoveTo(window->CenterX() - 393, window->CenterY() - 150);
    scene->Add(point2, STATIC);

    DirectionPoint* point3 = new DirectionPoint(DOWN);
    point3->MoveTo(window->CenterX() - 220, window->CenterY() - 115);
    scene->Add(point3, STATIC);

    DirectionPoint* point4 = new DirectionPoint(RIGHT);
    point4->MoveTo(window->CenterX() - 258, window->CenterY() + 260);
    scene->Add(point4, STATIC);

    DirectionPoint* point5 = new DirectionPoint(UP);
    point5->MoveTo(window->CenterX() - 88, window->CenterY() + 227);
    scene->Add(point5, STATIC);

    DirectionPoint* point6 = new DirectionPoint(RIGHT);
    point6->MoveTo(window->CenterX() - 120, window->CenterY() - 80);
    scene->Add(point6, STATIC);

    DirectionPoint* point7 = new DirectionPoint(UP);
    point7->MoveTo(window->CenterX() + 115, window->CenterY() - 47);
    scene->Add(point7, STATIC);
    
    DirectionPoint* point8 = new DirectionPoint(RIGHT);
    point8->MoveTo(window->CenterX() + 83, window->CenterY() - 285);
    scene->Add(point8, STATIC);

    DirectionPoint* point9 = new DirectionPoint(DOWN);
    point9->MoveTo(window->CenterX() + 320, window->CenterY() - 252);
    scene->Add(point9, STATIC);

    DirectionPoint* point10 = new DirectionPoint(LEFT);
    point10->MoveTo(window->CenterX() + 287, window->CenterY() + 123);
    scene->Add(point10, STATIC);

    DirectionPoint* point11 = new DirectionPoint(DOWN);
    point11->MoveTo(window->CenterX() + 50, window->CenterY() + 88);
    scene->Add(point11, STATIC);

    DirectionPoint* point12 = new DirectionPoint(RIGHT);
    point12->MoveTo(window->CenterX() + 85, window->CenterY() + 260);
    scene->Add(point12, STATIC);

    // ------------------------------------------------------------------------------------

    Rain* chuva = new Rain(rain);
    scene->Add(chuva, STATIC);

    /*Enemy* enemy = new Enemy(tilesetBatata, BATATA);
    scene->Add(enemy, MOVING);*/

    Enemy* cenoura = new Enemy(tilesetCouveFlor, COUVEFLOR);
    scene->Add(cenoura, MOVING);

    Tower* tower = new Tower();
    scene->Add(tower, MOVING);

    /*Enemy* brocolis = new Enemy(tilesetBrocolis, BROCOLIS);
    scene->Add(brocolis, MOVING);
    brocolis->MoveTo(window->CenterX(), window->CenterY());*/

}

void TowerDefense::Finalize() {
    delete rain;
    delete ground;
    delete floor;
    delete scene;
}

void TowerDefense::Update() {

    if (window->KeyPress(VK_LBUTTON)) {
        Tower* tw = new Tower();
        tw->MoveTo(window->MouseX(), window->MouseY() - (tw->Height()) / 3);
        scene->Add(tw, MOVING);
    }

    scene->Update();
    scene->CollisionDetection();
    scene->DrawBBox();
}

void TowerDefense::Draw() {
    ground->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    floor->Draw(window->CenterX(), window->CenterY(), Layer::LOWER);
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

