#include <array>
#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "wall.hpp"
#include "victim.hpp"

int main() {
	window w(vector(128, 64), 2);
	wall right(w, vector(124, 5), vector(128, 59), vector(-1, 1));
	wall left(w, vector(0,  5), vector(4, 59), vector(-1, 1));
	wall bottom(w, vector(0, 60), vector(128, 64), vector(1, -1));
	wall top(w, vector(0, 0), vector(128, 4), vector(1, -1));
	ball b(w, vector(50, 20), 9, vector(5, 2), vector(1, 1));

	victim v(w, vector(50, 30), 12);

	std::array< drawable *, 6 > objects = { &b, &left, &top, &right, &bottom, &v};

	for(;;) {
		w.clear();
		for(auto & p : objects) {
			p->draw();
		}
		wait_ms(200);
		for(auto & p : objects) {
			p->update();
		}
		for(auto & p : objects) {
			for(auto & other : objects) {
				p->interact(*other);
			}
		}
	}
}
