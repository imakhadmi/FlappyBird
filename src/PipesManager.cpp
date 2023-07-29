#include <random>
#include <SFML/Graphics.hpp>

#include "Headers/GLOBAL.h"
#include "Headers/Pipes.h"
#include "Headers/PipesManager.h"

PipesManager::PipesManager() :
	y_distribution(PIPE_OFFSET, GROUND_OFFSET - PIPE_OFFSET - GAP_SIZE),
	new_pipe_timer(NEW_PIPE_PERIOD)
{	
	
}

void PipesManager::update(std::mt19937_64& i_random_engine)
{
	if (!new_pipe_timer)
	{
		new_pipe_timer = NEW_PIPE_PERIOD;

		pipes.emplace_back(Pipes(SCREEN_WIDTH, y_distribution(i_random_engine)));
	}

	new_pipe_timer--;

	for (Pipes& a : pipes)
	{
		a.update();
	}

	for (std::vector<Pipes>::iterator a = pipes.begin(); a != pipes.end(); a++)
	{
		if (a->is_out_of_frame())
		{
			pipes.erase(a);
		}
	}
}

void PipesManager::draw(sf::RenderWindow& i_window)
{
	for (Pipes p : pipes)
	{
		p.draw(i_window);
	}
}

void PipesManager::reset()
{
	pipes.clear();
	
	new_pipe_timer = NEW_PIPE_PERIOD;
}

std::vector<Pipes> PipesManager::get_pipes()
{
	return pipes;
}