// template

#include <iostream>

#include "window.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "figure.hpp"

int main(int argc, char **argv) {
	std::cout << "dit werkt uiteindelijk toch wel";
	window w(516, 258, 2);
	figure dick(w, 5, 5, 6);
	dick.print();

	return 0;
}
