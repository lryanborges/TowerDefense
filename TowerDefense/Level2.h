#pragma once

#include "Game.h"
#include "Scene.h"
#include "Sprite.h"
#include "TileSet.h"

class Level2 : public Game {
private:
	Sprite* ground;

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

	void Init();
	void Update();
	void Draw();
	void Finalize();

};