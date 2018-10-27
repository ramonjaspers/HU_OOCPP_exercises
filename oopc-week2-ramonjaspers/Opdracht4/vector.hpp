#include <iostream>
#include "ostream"

class vector {
private:
	int x;
	int y;

public:
	vector(int x, int y):
		x(x), y(y)
	{}
	bool operator==(const vector & rhs) const;
	vector operator+(const vector & rhs);
	vector operator+(const int rhs);
	vector operator+=(const vector & rhs);
	vector operator*(const vector & rhs);
	vector operator*(const int rhs);
	vector operator*=(const vector & rhs);
	vector operator*=(const int rhs);
	friend std::ostream & operator<<(std::ostream & lhs, const vector & rhs);

	int x_get() { return x; }
	int y_get() { return y; }
	void x_set(int new_x) { x = new_x; }
	void y_set(int new_y) { y = new_y; }
};
