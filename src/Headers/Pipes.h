#pragma once

class Pipes
{
private:

	short x_pos;

	unsigned short y_pos;

public:
	Pipes(short i_x, unsigned short i_y);

	void draw(sf::RenderWindow& i_window);
	void update();
	bool is_out_of_frame();
	short get_x_pos();
	unsigned short get_y_pos();
};