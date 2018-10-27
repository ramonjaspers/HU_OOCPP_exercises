#ifndef VICTIM_HPP
#define VICTIM_HPP

#include "window.hpp"
#include "vector.hpp"
#include "drawable.hpp"
#include "rectangle.hpp"

class victim : public drawable {
private:
   vector location;
   int size;
public:
   victim( window & w, const vector & location, int size):
      drawable( w, location, vector(location.x + size, location.y + size), vector(1, 1)),
	  location (location),
	  size( size )
   {}
   void draw() override;
   void interact(drawable & other) override;
};

#endif // VICTIM_HPP
