// example:
// definition of the functions of a line class
// you are not expected to understand how line::print works

#include "filledSquare.hpp"

// avoid these because <algorithm> imports iostream stuff
template <class T> void swap(T& a, T& b) {
	T c(a);
	a=b;
	b=c;
}

void filledSquare::print() {
	for(int i = start_x; i <= end_x; i++) {
		for(int j = start_y; j <= end_y ; j++) {
			w.draw(i, j);
		}
	}
}
