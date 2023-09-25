#include"Object.h"
#include "Animation.h"
#include "TileSet.h"

enum priestState {
	STAY,
	MAGIC
};
class Priest : public Object {
private:
	TileSet* tileSet;
	Animation* animation;
	int fm = 0;
	bool controler = false;
	bool state = true;
	uint stt = STAY;
public:


	Priest();
	~Priest();
	void Update();
	void Draw();
	void OnCollision(Object* obj);

};


inline void Priest::Draw() {
	animation->Draw(x, y, Layer::FRONT);
}

inline void Priest::OnCollision(Object* obj)
{
}
