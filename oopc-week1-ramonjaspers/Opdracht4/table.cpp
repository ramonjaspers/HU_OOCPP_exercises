#include <iostream>
#include "table.hpp"

table::table(){}

void table::print() {
	print_legs();
	print_width();
	print_length();
}
void table::print_legs() {
	std::cout << n_legs << std::endl;
}


void table::print_width() {
	std::cout << width << std::endl;
}

void table::print_length() {
	std::cout << length << std::endl;
}


void table::addLegs(int legs) {
	n_legs += legs;
}
