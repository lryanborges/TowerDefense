#include "Game.h"
#include "Font.h"
#include "Timer.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Scene.h"

class Pontuation :public Game {
private:
	Font* text;
	Sprite* bg;
	Sprite* ground;
	Sprite* floor;
	Sprite* pointsBar;
	Sprite* soul;
	TileSet* tilesetRain;
	Timer rainTimer;
	bool rainTimerStarter;
public:
	static Scene* scene;

	void Init();
	void Update();
	void Draw();
	void Finalize();
	int random(int low, int high);
};