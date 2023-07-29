#pragma once

class PipesManager
{
private:

	unsigned short new_pipe_timer;

	std::uniform_int_distribution<unsigned short> y_distribution;

	std::vector<Pipes> pipes;

public:
	PipesManager();

	void draw(sf::RenderWindow& i_window);
	void update(std::mt19937_64& i_random_engine);
	void reset();

	std::vector<Pipes> get_pipes();
};