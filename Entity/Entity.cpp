#include "Entity.h"


Entity::Entity() {
    this->texture = new sf::Texture();
}

void Entity::Load(std::string filename) {
    this->texture->loadFromFile(filename);
    this->setTexture(*this->texture);
}

 void Entity::Update() {
    this->move(this->velocity);
}

bool Entity::CheckCollision(Entity* entity) {
    if (this->getGlobalBounds().intersects(entity->getGlobalBounds()))
    {
        return true;
    }
}

Entity::~Entity() {
    delete this->texture;
}
