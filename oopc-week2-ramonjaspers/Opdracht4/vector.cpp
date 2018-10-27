#include <iostream>
#include "vector.hpp"

/// \brief
/// checks if given values are equal
/// \details
/// This operator== checks if the given vectors are equal.
bool vector::operator==(const vector & rhs) const {
	return (x == rhs.x) && (y == rhs.y);
}

/// \brief
/// multiply a vector by an vector
/// \details
/// This operator* multiplies a vector value with an integer value.
vector vector::operator*(const vector & rhs) {
	return vector(x * rhs.x, y * rhs.y);
}

/// \brief
/// multiply a vector by an integer
/// \details
/// This operator* multiplies an vector with an integer value
vector vector::operator*(const int rhs) {
	return vector(x * rhs, y * rhs);
}

/// \brief
/// multiplies an vector with another vector with an reference to vector y
/// \details
/// This operator*= multiplies an vector with anpother vector value
vector vector::operator*=(const vector & rhs) {
	x = (x * rhs.x), (rhs.y * y);
	y *= rhs.y;
	return vector(x,y);
}

/// \brief
/// multiplies an vector with another vector with an reference to vector y
/// \details
/// This operator*= multiplies an vector with an integer value
vector vector::operator*=(const int rhs) {
	x = (x * rhs), (rhs * y);
	y *= rhs;
	return vector(x,y);
}

/// \brief
/// add a vector to another vector
/// \details
/// This operator+ adds a vector value with an vector variable.
vector vector::operator+(const vector & rhs) {
	return vector(x + rhs.x, rhs.y + y);
}
/// \brief
/// Adds a int to another vector
/// \details
/// this operator+ adds an integer value to a vector value
vector vector::operator+(const int rhs) {
	return vector(x + rhs, rhs + y);
}

/// \brief
/// add a vector to another vector
/// \details
/// This operator+= adds vector values with another one which inherits the value.
vector vector::operator+=(const vector & rhs) {
	x = (x + rhs.x), (rhs.y + y);
	y += rhs.y;
	return vector(x,y);
}

.
/// \brief
/// output operator for a vector value
/// \details
/// This operator<< prints a constructor in the format
/// (x int/y int) where both values are printed as
///  integer values.
std::ostream & operator<<(std::ostream & lhs, const vector & rhs) {
	return lhs
	       << "("
	       << rhs.x
	       << ","
	       << rhs.y
	       << ")";
}
