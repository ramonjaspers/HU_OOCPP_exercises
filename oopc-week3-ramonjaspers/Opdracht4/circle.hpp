#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "window.hpp"
#include "vector.hpp"
#include "drawable.hpp"

class circle : public drawable {
protected:
   int radius;
public:
   circle( window & w, const vector & midpoint, int radius, const vector & bounceIndex):
      drawable( w, midpoint - vector( radius, radius ), vector( radius, radius ) * 2, bounceIndex),
      radius( radius )
   {}
   void draw() override;
};

#endif // CIRCLE_HPP
