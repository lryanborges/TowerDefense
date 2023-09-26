#pragma once
#include "Game.h"
#include "Sprite.h"
#include "Audio.h"
#include "Font.h"

class TelaFinal : public Game{
public:

	void Init();
	void Update();
	void Draw();
	void Finalize();

private:
	Sprite * background;
	Audio  * audio;
	Font   * text;
	bool dw = false;
	int fm = 0;
	int mfm = 30;
};
