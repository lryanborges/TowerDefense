#pragma once

#include "Game.h"
#include "Scene.h"
#include "Resources.h"

class TowerDefense : public Game {
private:

public:
	static Scene* scene;

	void Init();
	void Update();
	void Draw();
	void Finalize();

};
