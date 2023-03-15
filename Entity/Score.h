#pragma once
#include <SFML/Graphics.hpp>
class Score : public sf::Text
{
private:
	int value;
public:
	Score(sf::Font & font, unsigned int size);
	void IncrementScore();
	void Update();
};

