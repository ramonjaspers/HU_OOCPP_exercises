#ifndef WALL_HPP
#define WALL_HPP

#include "window.hpp"
#include "vector.hpp"
#include "drawable.hpp"
#include "rectangle.hpp"

class wall : public drawable {
private:
	vector end;
	bool filled;
	int update_interval;
	int update_count;
public:
	wall(window & w, const vector & location, const vector & end):
		drawable(w, location, end - location),
		end(end),
		filled(false),
		update_interval(400),
		update_count(0)
	{}
	void draw() override;
	void update() override;
};

#endif // WALL_HPP
