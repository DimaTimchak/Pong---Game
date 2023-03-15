#include "Paddle_player.h"

Paddle_player::Paddle_player(int playerNumber){ 
    this->playerNumber = playerNumber;
        this->Load("../Pong - Game/Graphics/Sprites/paddle51.png");
}

void Paddle_player::Update() {
    if (this->playerNumber==0) {
        this->velocity.y = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) -
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) * PADDLE_SPEED;
    }
    Entity::Update();

    if (this->getPosition().y < 0) {
        this->move(0, PADDLE_SPEED);
    }
    if (this->getPosition().y + this->getGlobalBounds().height > 800) {
        this->move(0, -PADDLE_SPEED);
    }
}