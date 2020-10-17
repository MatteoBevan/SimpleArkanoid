#include "GameObject.h"
#include <SFML/Graphics.hpp>

static std::map<std::string, sf::Texture> s_TextureCache;

GameObject::GameObject(const sf::Vector2<float>& initialPosition)
{
	Position = initialPosition;
}

GameObject::~GameObject()
{
}

void GameObject::Init()
{
	std::map<std::string, sf::Texture>::iterator it = s_TextureCache.find(TexturePath);

	if(it == s_TextureCache.end())
	{
		if (!Texture.loadFromFile(TexturePath))
		{
			// error...
		}

		s_TextureCache.insert(std::pair<std::string, sf::Texture>(TexturePath, Texture));
	}
	else
	{
		Texture = it->second;
	}

	Sprite.setTexture(Texture);
	Sprite.setPosition(Position);
}

void GameObject::Update()
{
	
}

void GameObject::Draw(sf::RenderWindow& window)
{
	window.draw(Sprite);
}