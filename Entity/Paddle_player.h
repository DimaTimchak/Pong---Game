#pragma once
#include "Entity.h"

#define PADDLE_SPEED 7
class Paddle_player : public Entity
{
private:
    int playerNumber;
    
  public:
      Paddle_player() = default;
        Paddle_player(int playerNumber);
        void Update() override;
};

