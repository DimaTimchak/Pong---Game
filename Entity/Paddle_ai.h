#pragma once
#include "Paddle_player.h"
#include "Ball.h"
#define AI_BALL_BOUNDS 10.0f
class Paddle_ai : public Paddle_player
{
private:
    bool ballAway();
    sf::Vector2f target;
    Ball* ballObject;
    int playerNumber;
    float speed;
    void SelectTarget();
public:
    Paddle_ai(int playerNumber, int difficulty);
    void setBall(Ball* ballObject);
    void Update() override;
};

