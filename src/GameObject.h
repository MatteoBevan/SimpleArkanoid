#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(const sf::Vector2<float>& initialPosition);
	~GameObject();

	void Init();
	void Update();
	void Draw(sf::RenderWindow& window);

protected:

	sf::Vector2<float> Position;

	sf::Sprite Sprite;
	sf::Texture Texture;
	std::string TexturePath;
};

