// example:
// definition of the functions of a line class 
// you are not expected to understand how line::print works

#include "filled_rectangle.hpp"

// avoid these because <algorithm> imports iostream stuff
template <class T> void swap( T& a, T& b ){
  T c(a); a=b; b=c;
}

void filled_rectangle::print() {
	for(int i = 0; i < end_x + 1; i++) {
		if(i >= start_x) {
			for(int j = 0; j < end_y + 1; j++) {
				if(j >= start_y) {
					w.draw(vector(i, j));
				}
			}
		}
	}
}