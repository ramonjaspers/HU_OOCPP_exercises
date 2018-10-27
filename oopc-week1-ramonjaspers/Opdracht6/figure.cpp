#include "figure.hpp"
#include <iostream>

void figure::print() {
	for(int i = 0; i < amount; i++) {
		if(i > 0) {
			mid_x += 50;
		}


		line diagonal_line(w, mid_x+20, mid_y +3,mid_x +20, mid_y + 6);
		diagonal_line.print();
		rectangle box(w, mid_x+15, mid_y+8 , mid_x+26, mid_y +33);
		box.print();
		circle ball(w, mid_x+14, mid_y +40, 7);
		ball.print();
		circle ball2(w, mid_x+ 27, mid_y +40, 7);
		ball2.print();
		circle tip(w,  mid_x+20, mid_y +8, 5);
		tip.print();
//
//
//		filled_rectangle boxCar(w, position_x, mid_y, position_x + 40, mid_y + 20);
//		box.print();
//		circle wheel1(w, position_x + 5, start_y + 23, 2);
//		wheel1.print();
//		circle wheel2(w, position_x + 35, start_y + 23, 2);
//		wheel2.print();
//		line connector(w, position_x + 40, start_y + 18, position_x + 50, start_y + 18);
//		connector.print();
	}
}
