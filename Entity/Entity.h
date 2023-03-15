#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Entity : public sf::Sprite 
{
private:
	sf::Texture* texture;
public:
	sf::Vector2f velocity;
	Entity();
	void Load(std::string filename);
	virtual void Update();
	bool CheckCollision(Entity* entity);
	~Entity();
};

