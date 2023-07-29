#include <SFML/Graphics.hpp>

#include "Headers/GLOBAL.h"
#include "Headers/Pipes.h"

Pipes::Pipes(short i_x, unsigned short i_y) :
	x_pos(i_x), y_pos(i_y)
{

}

void Pipes::update()
{
	x_pos -= PIPE_SPEED;
}

void Pipes::draw(sf::RenderWindow& i_window)
{
	sf::Sprite sprite;

	sf::Texture texture;

	texture.loadFromFile("Images/Pipes16.png");

	sprite.setPosition(x_pos, static_cast<float>(y_pos - SCREEN_HEIGHT));
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(2 * BIRD_SIZE, 0, 2 * BIRD_SIZE, SCREEN_HEIGHT));

	i_window.draw(sprite);

	sprite.setPosition(x_pos, static_cast<float>(y_pos + GAP_SIZE));
	sprite.setTextureRect(sf::IntRect(0, 0, 2 * BIRD_SIZE, SCREEN_HEIGHT));

	i_window.draw(sprite);
}

bool Pipes::is_out_of_frame()
{
	return x_pos <= -2 * BIRD_SIZE;
}

short Pipes::get_x_pos()
{
	return x_pos;
}

unsigned short Pipes::get_y_pos()
{
	return y_pos;
}