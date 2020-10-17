#include "Block.h"



Block::Block(const sf::Vector2<float>& initialPosition, BlockType type)
	: GameObject(initialPosition)
{
	Type = type;
	switch (Type)
	{
	case BlockType::BLUE:
		TexturePath = "sprites/element_blue_rectangle.png";
		break;
	case BlockType::GREEN:
		TexturePath = "sprites/element_green_rectangle.png";
		break;
	case BlockType::GREY:
		TexturePath = "sprites/element_grey_rectangle.png";
		break;
	case BlockType::PURPLE:
		TexturePath = "sprites/element_purple_rectangle.png";
		break;
	case BlockType::RED:
		TexturePath = "sprites/element_red_rectangle.png";
		break;
	case BlockType::YELLOW:
		TexturePath = "sprites/element_yellow_rectangle.png";
		break;
	}
}


Block::~Block()
{
}
