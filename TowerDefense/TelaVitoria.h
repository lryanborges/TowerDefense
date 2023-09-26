#pragma once
#include "Game.h"
#include "Font.h"
#include "Sprite.h"

class TelaVitoria : public Game {
private:
	Sprite* bg;
	Font* text;
	bool dw = false;
	int fm = 0;
	int mfm = 30;
public:
	void Init() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;
};