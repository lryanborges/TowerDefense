#include "Level1.h"
#include "Grass.h"
#include "Ghost.h"
#include "Floor.h"
#include "DirectionPoint.h"
#include "Enemy.h"
#include "Tower.h"
#include "TowerDefense.h"
#include "Level2.h"

Scene* Level1::scene = nullptr;
void Level1::Init() {
	tilesetCenoura = new TileSet("Resources/cenoura.png", 40, 50, 8, 30);
    tilesetBatata = new TileSet("Resources/batata.png", 40, 50, 8, 30);
    tilesetCebola = new TileSet("Resources/cebola.png", 40, 50, 8, 30);
    tilesetNabo = new TileSet("Resources/nabo.png", 40, 50, 8, 30);
    tilesetBrocolis = new TileSet("Resources/brocolis.png", 40, 50, 8, 30);
    tilesetCheiroVerde = new TileSet("Resources/cheiroverde.png", 40, 50, 8, 30);
    tilesetMilho = new TileSet("Resources/milho.png", 40, 50, 8, 30);
    tilesetAlface = new TileSet("Resources/alface.png", 40, 50, 8, 30);
    tilesetCouveFlor = new TileSet("Resources/couveflor.png", 40, 50, 8, 30);

    ground = new Sprite("Resources/ground.png");
    floor = new Sprite("Resources/floor.png");
    priest = new Priest();
    scene = new Scene();

    // ----------------------------------
    //          Ambientação
    // ----------------------------------
    Grass* ambientation = new Grass(143, 393, 8); scene->Add(ambientation, STATIC);

    // ----------------------------------
    //        Definição de rota
    // ----------------------------------
    int posicaoX = -48;
    int posicaoY = 360;
    Floor* chao = new Floor(floor, posicaoX, posicaoY);
    scene->Add(chao, STATIC);
    for (int i = 0; i < 2; i++) {
        posicaoX = posicaoX + 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }
    scene->Add(priest, STATIC);
    for (int i = 0; i < 2; i++) {
        posicaoY = posicaoY - 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 2; i++) {
        posicaoX = posicaoX + 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 5; i++) {
        posicaoY = posicaoY + 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 2; i++) {
        posicaoX = posicaoX + 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 4; i++) {
        posicaoY = posicaoY - 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 3; i++) {
        posicaoX = posicaoX + 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 3; i++) {
        posicaoY = posicaoY - 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 3; i++) {
        posicaoX = posicaoX + 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 5; i++) {
        posicaoY = posicaoY + 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 3; i++) {
        posicaoX = posicaoX - 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 2; i++) {
        posicaoY = posicaoY + 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    for (int i = 0; i < 6; i++) {
        posicaoX = posicaoX + 68;
        chao = new Floor(floor, posicaoX, posicaoY);
        scene->Add(chao, STATIC);
    }

    // ----------------------------------
    //        Resto dos pisos
    // ----------------------------------
    Sprite* flowerFloor = new Sprite("Resources/flowerGround.png");
    Sprite* basicFloor = new Sprite("Resources/basicGround.png");

    int n68 = -68;
    posicaoX = posicaoX + 68;
    for (int i = 1; i <= 144; i++) {
        if (i == 3 || i == 22 || i == 36 || i == 51 || i == 55 || i == 58 || i == 66 || i == 78 || i == 86 || i == 91 || i == 101 || i == 121 || i == 131 || i == 132 || i == 140 || i == 143) {
            chao = new Floor(flowerFloor, posicaoX, posicaoY, true);
        }
        else {
            chao = new Floor(basicFloor, posicaoX, posicaoY, true);
        }
        scene->Add(chao, STATIC);
        posicaoX = posicaoX + n68;
        if (i % 16 == 0) {
            posicaoY = posicaoY - 68;
            n68 = -n68;
        }
    }

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

    /*Enemy* enemy = new Enemy(tilesetBatata, BATATA);
    scene->Add(enemy, MOVING);*/

    Enemy* couveflor = new Enemy(tilesetCouveFlor, COUVEFLOR);
    scene->Add(couveflor, MOVING);

    Enemy* batata = new Enemy(tilesetBatata, BATATA);
    batata->MoveTo(-50, window->CenterY() + 20);
    scene->Add(batata, MOVING);

    Enemy* cenoura  = new Enemy(tilesetCenoura, CENOURA);
    cenoura->MoveTo(-100, window->CenterY() + 20);
    scene->Add(cenoura, MOVING);

    Enemy* cenoura2 = new Enemy(tilesetCenoura, CENOURA);
    cenoura2->MoveTo(-150, window->CenterY() + 20);
    scene->Add(cenoura2, MOVING);

    Tower* tower = new Tower(GREEN);
    scene->Add(tower, STATIC);

    /*Enemy* brocolis = new Enemy(tilesetBrocolis, BROCOLIS);
    scene->Add(brocolis, MOVING);
    brocolis->MoveTo(window->CenterX(), window->CenterY());*/
}

void Level1::Finalize() {
    delete tilesetCenoura;
    delete tilesetBatata;
    delete tilesetCebola;
    delete tilesetNabo;
    delete tilesetBrocolis;
    delete tilesetCheiroVerde;
    delete tilesetMilho;
    delete tilesetAlface;
    delete tilesetCouveFlor;
    delete floor;
    delete flowerFloor;
    delete basicFloor;
    delete ground;
    scene->Remove(TowerDefense::mouse, MOUSE);
    scene->Remove(TowerDefense::hub, HUB);
    delete scene;
}

void Level1::Update() {


    if (window->KeyPress('2')) {
        TowerDefense::NextLevel<Level2>();
    }
    else {
        scene->Update();
        scene->CollisionDetection();
        scene->DrawBBox();
    }
}

void Level1::Draw() {
    ground->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scene->Draw();
}