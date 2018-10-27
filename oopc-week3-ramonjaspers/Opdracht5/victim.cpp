#include "victim.hpp"


void victim::draw() {
	rectangle square(w, location, vector(location.x + size, location.y + size), vector(1, 1));
	square.draw();
}

void victim::interact(drawable & other) {
if( this != & other){
      if( overlaps( other )){
			if(size != 0) {
				size--;
			}
		}
	}
}
