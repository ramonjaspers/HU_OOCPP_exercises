// example:
// definition of the functions of a line class 
// you are not expected to understand how line::print works

#include "wall.hpp"


void wall::draw() {
	if(filled == false) {
		int x0 = location.x;
		int x1 = end.x;
		int y0 = location.y;
		int y1 = end.y;
		for( int i = 0; i < x1 + 1; i++) {
			if(i >= x0) {
				for(int j = 0; j < y1 + 1; j++) {
					if(j >= y0) {
						w.draw(vector(i, j));
					}
				}
			}
		}
		filled = true;
	} else {
		drawWall.draw();
		filled = false;
	}
}

void wall::update() {
	if(update_count == 0) {
		filled = false;
		update_count++;
	} else {
		filled = true;
		update_count--;
	}
}
