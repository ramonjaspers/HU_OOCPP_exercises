#include <iostream>
#include "furniture.hpp"


furniture::furniture() :
	stool1(1,4),
	stool2(1,4),
	stool3(1,4),
	stool4(1,4),
	mahogonyTable(6, 6000,8000)
{}


void furniture::print() {
	std::cout << "Stoel 1:"<< std::endl;
	stool1.print();
	std::cout << std::endl;

	std::cout << "Stoel 2:"<< std::endl;
	stool2.print();
	std::cout << std::endl;

	std::cout << "Stoel 3:"<< std::endl;
	stool3.print();
	std::cout << std::endl;

	std::cout << "legs";
	stool3.print();
	std::cout << std::endl;

	std::cout << "Stoel 4:"<< std::endl;
	stool4.print();
	std::cout << std::endl;

	std::cout << "Tafel 1:"<< std::endl;
	mahogonyTable.print();
	std::cout << std::endl;

}


void furniture::makeMoreHipster() {
	stool1.removeLegs(1);
	stool2.removeLegs(1);
	stool3.removeLegs(1);
	stool4.removeLegs(1);
	mahogonyTable.addLegs(4);
}
