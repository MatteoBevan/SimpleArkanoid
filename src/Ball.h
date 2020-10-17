#pragma once

#include "GameObject.h"

class Ball : public GameObject
{
public:
	Ball(const sf::Vector2<float>& initialPosition);
	~Ball();

protected:

	sf::Vector2<float> Velocity;

};

