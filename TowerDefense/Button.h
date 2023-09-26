#include "Object.h"
#include "Sprite.h"
using std::stringstream;
enum buttonTypes {
	GREENB,
	REDB,
	YELLOWB,
	BLUEB,
	PURPLEB,
};
enum buttonState {
	DESACTIVATE,
	ACTIVATE
};

class Button : public Object {
private:
	Image* iconA;
	uint t;
	Image* iconD;
	Image* iconB;
	Sprite* button;
	int price;
public:
	Button(int b);
	~Button();
	void Update();
	void Draw();

	void OnCollision(Object* obj);

};
