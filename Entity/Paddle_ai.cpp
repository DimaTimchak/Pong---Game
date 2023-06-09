#include "paddle_ai.h"


Paddle_ai::Paddle_ai(int playerNumber, int difficulty) {
    this->playerNumber = playerNumber;
    this->ballObject = ballObject;
    switch (difficulty) {
    case 1:
        this->speed = 1.05f * PADDLE_SPEED;
        break;
    case 2:
        this->speed = 1.20f * PADDLE_SPEED;
        break;
    default:
        this->speed = 1.43f * PADDLE_SPEED;
        break;
    }
    this->Load("Graphics/Sprites/paddle52.png");
}

void Paddle_ai::setBall(Ball* ballObject) {
    this->ballObject = ballObject;
}

bool Paddle_ai::ballAway() {
    if (this->playerNumber == 0) {
        return this->ballObject->velocity.x > 0;
    }
    return this->ballObject->velocity.x < 0;
}

void Paddle_ai::SelectTarget() {
    if (this->ballObject->GoingToCeil() || this->ballObject->GoingToFloar()) {
        this->target.y = rand() % 800;
    }
}


void Paddle_ai::Update() {
    if (this->ballObject) {
        if (this->ballAway()) {
            if (target.x < 0) {
                target.x = 1;
                this->SelectTarget();
            }
            float temp = ((this->getPosition().y + this->getGlobalBounds().height / 2) - this->target.y);
            if (temp < -AI_BALL_BOUNDS) {
                this->velocity.y = this->speed;
            }
            else if (temp > AI_BALL_BOUNDS) {
                this->velocity.y = -this->speed;
            }
            else {
                this->velocity.y = 0;
            }
        }
        else {
            target = sf::Vector2f(-1, 0);
            float temp = ((this->getPosition().y + this->getGlobalBounds().height / 2) - this->ballObject->getPosition().y);
            if (temp < -AI_BALL_BOUNDS) {
                this->velocity.y = this->speed;
            }
            else if (temp > AI_BALL_BOUNDS) {
                this->velocity.y = -this->speed;
            }
            else {
                this->velocity.y = 0;
            }
        }
    }

    Entity::Update();
    if (this->getPosition().y < 0) {
        this->move(0, this->speed);
    }
    if (this->getPosition().y + this->getGlobalBounds().height > 800) {
        this->move(0, -this->speed);
    }
}