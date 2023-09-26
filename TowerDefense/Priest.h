#include"Object.h"
#include "Animation.h"
#include "TileSet.h"
#include "Sprite.h"

enum priestState {
	STAY,
	MAGIC
};
class Priest : public Object {
private:
	TileSet* tileSet;
	Animation* animation;
	int fm = 0;
	bool state = true;
	uint stt = STAY;
	Sprite* purpleBar;
	Sprite* pinkBar;
	int pinkX;
public:
	static bool lostLife;
	static bool controler;
	static int life;

	Priest();
	~Priest();
	void Update();
	void Draw();
	void OnCollision(Object* obj);

};


inline void Priest::OnCollision(Object* obj)
{
}
