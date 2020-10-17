#include "Ball.h"



Ball::Ball(const sf::Vector2<float>& initialPosition)
	: GameObject(initialPosition)
{
	TexturePath = "sprites/ballGrey.png";
}


Ball::~Ball()
{
}
