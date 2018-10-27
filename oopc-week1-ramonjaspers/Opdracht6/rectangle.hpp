// example:
// declaration of a line class that stores its window
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "window.hpp"

class rectangle {
private:
   int start_x;
   int start_y; 
   int end_x;
   int end_y;
   window & w;
public:
   rectangle( window & w, int start_x, int start_y, int end_x, int end_y ):
      start_x( start_x ),
      start_y( start_y ),
      end_x( end_x ),
      end_y( end_y ),
      w( w )
   {}
   void print();
};

#endif // RECTANGLE_HPP
