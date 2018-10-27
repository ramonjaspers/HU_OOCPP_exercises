#ifndef TABLE_HPP
#define TABLE_HPP

#include <ostream>


class table {
private:
	int n_legs;
	int length;
	int width;

	void print_legs();
	void print_width();
	void print_length();
public:
	table();
	table(
	    const int & n_legs,
	    const int & length,
	    const int & width
	):
		n_legs(n_legs),
		length(length),
		width(width) {}

	void print();

	void addLegs(int legs);

};

#endif // FURNITURE_HPP
