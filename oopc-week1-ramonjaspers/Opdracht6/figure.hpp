#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>

#include "window.hpp"
#include "circle.hpp"
#include "line.hpp"
#include "rectangle.hpp"

class figure {
private:
	int mid_x;
	int mid_y;
	int amount;
	window & w;
	line * diagonal_line;
	rectangle * box;
	circle * ball;
	circle * ball2;


public:
	figure(window & w, int mid_x, int mid_y, int amount):
		mid_x(mid_x),
		mid_y(mid_y),
		amount(amount),
		w(w)
	{}
	void print();
};

#endif // LINE_HPP
