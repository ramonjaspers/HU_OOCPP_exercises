#ifndef STOOL_HPP
#define STOOL_HPP

#include <ostream>

class stool {
private:
	int n_legs;
	int n_seats;

	void print_legs();
	void print_seats();
public:
	stool();
	stool(
	    const int & n_legs,
	    const int & n_seats
	):
		n_legs(n_legs),
		n_seats(n_seats) {}
	
	void removeLegs(int legs);
	void print();
};

#endif // FURNITURE_HPP