#include "MainMenu.h"
#include "TowerDefense.h"
#include "Level1.h"
#include "Floor.h"

// -----------------------------------------------------------------------------
Game* MainMenu::level = nullptr;
Scene* MainMenu::scene = nullptr;

void MainMenu::Init() {



    //level = new Level1();
    background = new Sprite("Resources/mainmenu.png");
    Floor* bg = new Floor(background, window->CenterX(), window->CenterY()); // Shh
    scene = new Scene();
    scene->Add(bg, STATIC);
}

void MainMenu::Update()
{
    if (window->KeyPress(VK_SPACE)) {
        OutputDebugString("Apertou espaço");
        TowerDefense::NextLevel<TowerDefense>();
    }
    else {
        scene->Update();
        scene->CollisionDetection();
    }

    // sai com pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

}

void MainMenu::Draw()
{
    scene->Draw();
}

void MainMenu::Finalize()
{
    delete scene;
    delete background;
}
