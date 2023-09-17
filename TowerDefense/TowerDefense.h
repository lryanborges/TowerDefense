#pragma once

#include "Game.h"
#include "Scene.h"
#include "Resources.h"
#include "Sprite.h"
#include "TileSet.h"

class TowerDefense : public Game {
private:
	Sprite* ground;
	TileSet* rain;

public:
	static Scene* scene;

	void Init();
	void Update();
	void Draw();
	void Finalize();

};
