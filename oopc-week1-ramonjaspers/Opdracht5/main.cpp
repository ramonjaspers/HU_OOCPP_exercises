// example: 
// using a line that requires its window

#include <iostream>

#include "window.hpp"
#include "line.hpp"
#include "filledSquare.hpp"

int main(int argc, char **argv){
   window w( 128, 64, 2 );
   filledSquare box1( w, 5, 5, 30, 40 );
   box1.print();
   filledSquare box2( w, 35, 5, 70, 70 );
   box2.print();
   filledSquare box3( w, 80, 5, 120, 30 );
   box3.print();
   return 0;
}


