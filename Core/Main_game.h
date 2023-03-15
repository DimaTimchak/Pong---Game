#pragma once

#include "Main_menu.h"
#include "Game_state.h"
#include "../Entity/Entity.h"
#include "../Entity/Score.h"
#include "../Entity/Paddle_player.h"
#include "../Entity/Ball.h"
#include "../Entity/Paddle_ai.h"
#include "../Entity/Background.h"


class Main_game : public Tiny_state {
public:
    Main_game(int mode);
    void Initialize(sf::RenderWindow* window);
    void Update(sf::RenderWindow* window);
    void Render(sf::RenderWindow* window);
    void Destroy(sf::RenderWindow* window);
private:
    int difficulty;
    Background* back;
    Paddle_player* player1;
    Paddle_ai* player2;
    Ball* ballObject;
    Score* score1;
    Score* score2;
    sf::Font* font;
    sf::Font* pausedFont;
    sf::Font* scoreFont;
    sf::Text* pausedText;
    bool paused, enterKey;
    sf::Clock startTimer;
    sf::Time startElapsed;
    sf::Text* startDigits;


};

