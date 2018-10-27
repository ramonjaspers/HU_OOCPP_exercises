// example:
// definition of the functions of a line class
// you are not expected to understand how line::print works

#include "rectangle.hpp"

// avoid these because <algorithm> imports iostream stuff
template <class T> void swap(T& a, T& b) {
	T c(a);
	a=b;
	b=c;
}

void rectangle::print() {
	for(int i = start_x; i < end_x + 1; i++) {
		for(int j = start_y; j < end_y + 1; j++) {
			w.write(hwlib::location(i, j));
		}
	}
}
