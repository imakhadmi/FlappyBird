#pragma once

class Bird
{
private:
	float vertical_speed;
	float y_pos;
	bool collision;
	unsigned short score;

public:
	
	Bird();
	bool get_collision();
	void draw(sf::RenderWindow& i_window);
	void update(std::vector<Pipes> i_pipes);
	void reset();
	unsigned short get_score();
};