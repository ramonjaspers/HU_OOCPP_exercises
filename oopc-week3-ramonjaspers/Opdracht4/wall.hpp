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
	vector bounceIndex;

	int update_count;
public:
	wall(window & w, const vector & location, const vector & end, const vector & bounceIndex):
		drawable(w, location, end - location, bounceIndex),
		end(end),
		filled(false),
		bounceIndex(bounceIndex),
		update_count(0)
	{}
	void draw() override;
	void update() override;
};

#endif // WALL_HPP
