#include <iostream>
#include "stool.hpp"

stool::stool(){}

void stool::print() {
	 print_legs();
	 print_seats();
}

void stool::print_legs() {
	std::cout << n_legs << std::endl;
}

void stool::print_seats() {
	std::cout << n_seats << std::endl;
}


void stool::removeLegs(int legs) {
	n_legs -= legs;
}


