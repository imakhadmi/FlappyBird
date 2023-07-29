#include <SFML/Graphics.hpp>

#include "Headers/Pipes.h"
#include "Headers/Bird.h"
#include "Headers/GLOBAL.h"

Bird::Bird() : 
	y_pos(0.5f * (SCREEN_HEIGHT - BIRD_SIZE)), collision(0), score(0), vertical_speed(0)
{

}
	
void Bird::draw(sf::RenderWindow& i_window)
{
	sf::Texture texture;
	texture.loadFromFile("Images/Bird16.png"); 

	sf::Sprite sprite;
	sprite.setPosition(BIRD_START_X, round(y_pos));
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(BIRD_SIZE * (vertical_speed <= 0), BIRD_SIZE * collision, BIRD_SIZE, BIRD_SIZE));

	i_window.draw(sprite);
}

void Bird::update(std::vector<Pipes> i_pipes)
{
	vertical_speed += GRAVITY;
	y_pos += vertical_speed;

	// Collision Detection
	if (y_pos >= GROUND_OFFSET - BIRD_SIZE)		// With ground
	{
		collision = 1;

		y_pos = GROUND_OFFSET - BIRD_SIZE;
	}
	else										// With Pipes
	{
		for (Pipes& p : i_pipes)
		{
			if (((BIRD_START_X < p.get_x_pos() + 2 * BIRD_SIZE && BIRD_START_X > p.get_x_pos() - BIRD_SIZE)) &&
				(y_pos < p.get_y_pos() || y_pos > p.get_y_pos() + GAP_SIZE - BIRD_SIZE))
			{
				collision = 1;
			}
			else if (p.get_x_pos() + 2 * BIRD_SIZE == BIRD_START_X) // Pipe passed bird
			{
				score++;
			}
		}
	}
	
	// Flap Detection
	if (!collision && vertical_speed >= 0 && y_pos >= 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		vertical_speed = FLAP_SPEED;
	}
}

bool Bird::get_collision()
{
	return collision;
}

void Bird::reset()
{
	collision = 0;
	vertical_speed = 0;
	y_pos = 0.5f * (SCREEN_HEIGHT - BIRD_SIZE);
	score = 0;
}

unsigned short Bird::get_score()
{
	return score;
}