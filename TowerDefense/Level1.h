#pragma once

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
