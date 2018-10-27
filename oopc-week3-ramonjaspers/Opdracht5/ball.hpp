#ifndef BALL_HPP
#define BALL_HPP

#include <iostream>
#include "window.hpp"
#include "vector.hpp"
#include "circle.hpp"

class ball : public circle {
private:
   vector speed;
public:
   ball( window & w, const vector & midpoint, int radius, const vector & speed, const vector & bounceIndex);
   void update() override;
   void interact( drawable & other ) override;
};

#endif // BALL_HPP
