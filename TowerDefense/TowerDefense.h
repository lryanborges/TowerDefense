#pragma once

#include "Game.h"
#include "Scene.h"
#include "Resources.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "Mouse.h"
#include "Hub.h"

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
	MOUSE,
	FLOORSPACE,
	TOWERGREEN,
	TOWERBLUE,
	BUTTON, 
	PRIEST,
	HUB
};

class TowerDefense : public Game {
private:
	static Game* level;

public:
	static Scene* scene;
	static Mouse* mouse;
	static Hub* hub;

	void Init();
	void Update();
	void Draw();
	void Finalize();

	template<class T>
	static void NextLevel()         // muda para próximo nível do jogo
	{
		if (level)
		{
			level->Finalize();
			delete level;
			level = new T();
			level->Init();
		}
	}

};
