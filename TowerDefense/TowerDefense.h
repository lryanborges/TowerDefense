#pragma once

#include "Game.h"
#include "Scene.h"
#include "Resources.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "Mouse.h"

enum ObjectType {
	ENEMY,
	TOWER,
	DIRECTIONPOINT,
	POWERGREEN,
	POWERYELLOW,
	POWERRED,
	POWERBLUE,
	POWERPURPLE, 
	FLOOR,
	MOUSE
};

class TowerDefense : public Game {
private:
	Sprite* ground;
	Sprite* floor;
	TileSet* rain;
	Animation* rainAnimation;

public:
	static Scene* scene;
	static Mouse* mouse;

	void Init();
	void Update();
	void Draw();
	void Finalize();

};
