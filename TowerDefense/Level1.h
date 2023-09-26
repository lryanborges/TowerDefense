#pragma once
#include "Button.h"
#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "Scene.h"

class Level1 : public Game {
private:
	Sprite* floor;
	Sprite* flowerFloor;
	Sprite* basicFloor;
	Sprite* ground;
	TileSet* rain;
	Animation* rainAnimation;
	int frames = 0;
	int ctFrames1 = 1600;
	int ctFrames2 = 3000;
	bool controlador1 = false;
	bool controlador2 = false;
	// TileSets mobs
	TileSet* tilesetCenoura;
	TileSet* tilesetBatata;
	TileSet* tilesetCebola;
	TileSet* tilesetNabo;
	TileSet* tilesetBrocolis;
	TileSet* tilesetCheiroVerde;
	TileSet* tilesetMilho;
	TileSet* tilesetAlface;
	TileSet* tilesetCouveFlor;
public:
	static Scene* scene;

	int random(int low, int high);

	void Init();
	void Update();
	void Draw();
	void Finalize();

};
