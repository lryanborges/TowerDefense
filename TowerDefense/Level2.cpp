#include "Level2.h"
#include "Enemy.h"
#include "Tower.h"
#include "TowerDefense.h"


Scene* Level2::scene = nullptr;
void Level2::Init() {

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

	scene = new Scene();
	TowerDefense::scene = scene;
	scene->Add(TowerDefense::mouse, MOUSE);

	Enemy* brocolis = new Enemy(tilesetBrocolis, BROCOLIS);
	scene->Add(brocolis, MOVING);

	Tower* tower = new Tower(GREEN);
	scene->Add(tower, MOVING);
}

void Level2::Finalize() {
	delete tilesetCenoura;
	delete tilesetBatata;
	delete tilesetCebola;
	delete tilesetNabo;
	delete tilesetBrocolis;
	delete tilesetCheiroVerde;
	delete tilesetMilho;
	delete tilesetAlface;
	delete tilesetCouveFlor;
	scene->Remove(TowerDefense::mouse, MOUSE);
	delete scene;
	delete ground;
}

void Level2::Update() {
	scene->Update();
	scene->DrawBBox();
	scene->CollisionDetection();
}

void Level2::Draw() {
	ground->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
	scene->Draw();
}