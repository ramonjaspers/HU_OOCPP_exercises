#ifndef FURNITURE_HPP
#define FURNITURE_HPP

#include <ostream>
#include "table.hpp"
#include "stool.hpp"

class furniture {
private:
	stool stool1;
	stool stool2;
	stool stool3;
	stool stool4;

	table mahogonyTable;
public:
	furniture();
	void makeMoreHipster();
	void print();
};

#endif //FURNITURE_HPP