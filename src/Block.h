#pragma once

#include "GameObject.h"

enum BlockType
{
	BLUE,
	GREEN,
	GREY,
	PURPLE,
	RED,
	YELLOW
};

class Block : public GameObject
{
public:
	Block(const sf::Vector2<float>& initialPosition, BlockType type);
	~Block();

protected:

	BlockType Type;
};

