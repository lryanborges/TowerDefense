#pragma once

#include "Game.h"
#include "Scene.h"
#include "Resources.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"

enum ObjectType {
	ENEMY,
	TOWER,
	DIRECTIONPOINT,
	POWER
};

class TowerDefense : public Game {
private:
	Sprite* ground;
	Sprite* floor;
	TileSet* rain;
	Animation* rainAnimation;

public:
	static Scene* scene;

	void Init();
	void Update();
	void Draw();
	void Finalize();

};
