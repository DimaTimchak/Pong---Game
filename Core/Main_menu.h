#pragma once

#include "Main_game.h"
#include "Game_State.h"
#include "../Entity/Background.h"

class Main_menu : public Tiny_state {
private:
    sf::Font* font;
    sf::Text* title;
    sf::Text* play_solo;
    sf::Text* quit;
    Background* back;
    int selected;
    float scale;
    float scaleInc;
    int mode;
    bool upKey, downKey, leftKey, rightKey;
    void UpdateMode(sf::RenderWindow* window);
public:
    void Initialize(sf::RenderWindow* window);
    void Update(sf::RenderWindow* window);
    void Render(sf::RenderWindow* window);
    void Destroy(sf::RenderWindow* window);

};

