#include "Engine.h"
#include "Game.h"
#include "Sprite.h"
#include "Resources.h"
#include "Scene.h"
#include "Audio.h"

class MainMenu : public Game
{
private:
    static Game* level;
    Audio* audio = nullptr;
    Sprite* background;
public:
    static Scene* scene;

    void Init();
    void Update();
    void Draw();
    void Finalize();
};
