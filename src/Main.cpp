#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
#include "Ball.h"
#include "Vaus.h"
#include "Block.h"

namespace Settings
{
	const int s_width = 13;
	const int s_height = 6;
	const int s_windowWidth = 1200;
	const int s_windowHeight = 800;

	const float s_ballSize = 25.0f;
	const float s_blockWidth = 65.0f;
	const float s_blockHeight = 25.0f;

}

void InitGame(sf::RenderWindow& window, std::vector<GameObject*>& gameObjects)
{
	const sf::Vector2<float> s_initialPosition(
		Settings::s_windowWidth / 2.0f - Settings::s_blockWidth / 2.0f, 
		Settings::s_windowHeight - Settings::s_ballSize * 2.0f);

	const sf::Vector2<float> ballPos = s_initialPosition + sf::Vector2<float>(0.0f, -Settings::s_ballSize);
	gameObjects.push_back(new Ball(ballPos));

	gameObjects.push_back(new Vaus(s_initialPosition));

	const float blockWidth = Settings::s_width * Settings::s_blockWidth;
	const float widthMargin = (Settings::s_windowWidth - blockWidth) / 2.0f;
	const float heightMargin = Settings::s_blockHeight * 2.0f;

	for (int i = 0; i < Settings::s_width; ++i)
	{
		for (int j = 0; j < Settings::s_height; ++j)
		{
			const sf::Vector2<float> pos(widthMargin + i * Settings::s_blockWidth, heightMargin + j * Settings::s_blockHeight);

			gameObjects.push_back(new Block(pos, (BlockType)j));
		}
	}

	for (GameObject* go : gameObjects)
	{
		go->Init();
	}

	window.clear();
	window.display();
}

void UpdateGame(sf::RenderWindow& window, std::vector<GameObject*>& gameObjects)
{
	for (GameObject* go : gameObjects)
	{
		go->Update();
	}

	window.clear();

	for (GameObject* go : gameObjects)
	{
		go->Draw(window);
	}

	window.display();
}

void CloseGame(std::vector<GameObject*>& gameObjects)
{
	for (GameObject* go : gameObjects)
	{
		delete go;
	}

	gameObjects.clear();
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(Settings::s_windowWidth, Settings::s_windowHeight), "My Arkanoid");

	sf::Event event;

	std::vector<GameObject*> gameObjects;

	InitGame(window, gameObjects);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			UpdateGame(window, gameObjects);

			if (event.type == sf::Event::Closed)
			{
				CloseGame(gameObjects);
				window.close();
			}
		}
	}

	return 0;
}