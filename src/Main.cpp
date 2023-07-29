#include <array>
#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>

#include "Headers/Pipes.h"
#include "Headers/Bird.h"
#include "Headers/GLOBAL.h"
#include "Headers/PipesManager.h"
#include "Headers/DrawText.h"

int main() 
{

	std::mt19937_64 random_engine(std::chrono::system_clock::now().time_since_epoch().count());

	sf::Event event;

	sf::RenderWindow window(sf::VideoMode(SCREEN_RESIZE * SCREEN_WIDTH, SCREEN_RESIZE * SCREEN_HEIGHT), "Flappy Bird", sf::Style::Close);
	window.setView(sf::View(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));

	sf::Sprite background_sprite;
	sf::Sprite ground_sprite;

	sf::Texture background_texture;
	sf::Texture ground_texture;

	background_texture.loadFromFile("Images/Background.png");
	ground_texture.loadFromFile("Images/Ground.png");

	background_sprite.setTexture(background_texture);
	ground_sprite.setTexture(ground_texture);

	ground_sprite.setPosition(0, GROUND_OFFSET);

	PipesManager pipesmanager;
	Bird bird;

	window.draw(background_sprite);
	pipesmanager.draw(window);
	bird.draw(window);
	window.draw(ground_sprite);

	window.display();

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			window.close();
		}

		if (!bird.get_collision())									// Updates pipes movement until a collision occurs
		{
			pipesmanager.update(random_engine);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))	// Reset after collision by pressing Enter
		{
			bird.reset();
			pipesmanager.reset();
		}

		bird.update(pipesmanager.get_pipes());

		window.clear();
		
		window.draw(background_sprite);
		pipesmanager.draw(window);
		bird.draw(window);
		window.draw(ground_sprite);

		draw_text(1, 1, 0, 0, BIRD_SIZE, std::to_string(bird.get_score()), window);
		
		window.display();
	}
}