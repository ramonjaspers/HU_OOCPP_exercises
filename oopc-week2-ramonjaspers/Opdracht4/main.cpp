#include <iostream>
#include "ostream"
#include "vector.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("equality, equal") {
	vector v(1, 2);
	REQUIRE(v == vector(1, 2));
}

TEST_CASE("equality, unequal") {
	vector v(1, 2);
	REQUIRE(!(v == vector(1, 3)));
}


TEST_CASE("multiply by vector") {
	vector v(3, 4);
	vector x = v * vector(9, 7);
	REQUIRE(v == vector(3, 4));
	REQUIRE(x == vector(27, 28));
}


TEST_CASE("multiply by int") {
	vector v(3, 4);
	vector x = v * 7;
	REQUIRE(v == vector(3, 4));
	REQUIRE(x == vector(21, 28));
}

TEST_CASE("multiply vector into vector; return value") {
	vector v(3, 10);
	vector x = (v *= vector(1, 2));
	REQUIRE(v == vector(3, 20));
	REQUIRE(x == vector(3, 20));
}

TEST_CASE("multiply vector with int; return value") {
	vector v(3, 10);
	vector x = (v *= 6);
	REQUIRE(v == vector(18, 60));
	REQUIRE(x == vector(18, 60));
}

TEST_CASE("add rational; return value") {
	vector v(1, 2);
	vector x = (v + vector(4, 4));
	REQUIRE(v == vector(1, 2));
	REQUIRE(x == vector(5, 6));
}

TEST_CASE("add int; return value") {
	vector v(1, 2);
	vector x = (v + 5);
	REQUIRE(v == vector(1, 2));
	REQUIRE(x == vector(6, 7));
}

TEST_CASE("add rational into rational; return value") {
	vector v(1, 2);
	vector x = (v += vector(1, 4));
	REQUIRE(v == vector(2, 6));
	REQUIRE(x == vector(2, 6));
}

TEST_CASE("Ostream overload; string stream ostream") {
	vector v(50, 200);
	std::stringstream s;
	s << v;
	REQUIRE(s.str() =="(50,200)");

}
