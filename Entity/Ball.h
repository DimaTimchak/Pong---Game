#pragma once
#include "Entity.h"
#include "Paddle_player.h"
#include "Score.h"
class Ball : public Entity
{
private:
    Score* score1;
    Score* score2;
    Paddle_player* player1;
    Paddle_player* player2;
    

public:
    Ball(Score* score1, Score* score2, Paddle_player* player1, Paddle_player* player2);
    void Update(sf::RenderWindow* window);

    bool GoingToCeil();
    bool GoingToFloar();

    void AddVelocity(Paddle_player* paddle);
    void Reset(sf::RenderWindow* window);
};

