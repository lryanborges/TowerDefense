#pragma once

#include "Game.h"
#include "Scene.h"
#include "Resources.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "Mouse.h"
#include "Hub.h"
#include "Audio.h"
#include "Priest.h"
#include "Font.h"
enum SoundsIntro {
	INTRO,
	MAIN,
	LEVEL2,
	TOWERSET,
	GAMEOVER,
	ZOMBIE1, 
	ZOMBIE2,
	BONES,
	LAUGH,
	TYPINGMACHINE,
	FIRESPELL,
	FREEZESPELL,
	MAGICSPELL,
	WINDSPELL,
	DIVINESPELL,
	MORENO
};

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
	HUB,
	GRASS
};

class TowerDefense : public Game {
private:
	static Game* level;

public:
	static Audio * audios;
	static Scene* scene;
	static Mouse* mouse;
	static Hub* hub;
	static Priest* priest;
	static int souls;
	static Font* placar;

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
