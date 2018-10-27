// example:
// definition of the functions of a rectangle object

#include "rectangle.hpp"

rectangle::rectangle( window & w, const vector & start, const vector & end, const vector & bounceIndex):
   drawable( w, start, end - start, bounceIndex),
   end( end ),
   left(   w, vector( start.x, start.y ), vector( start.x, end.y   ), bounceIndex),
   right(  w, vector( end.x,   start.y ), vector( end.x,   end.y   ), bounceIndex ),
   top(    w, vector( start.x, start.y ), vector( end.x,   start.y ), bounceIndex),
   bottom( w, vector( start.x, end.y   ), vector( end.x,   end.y   ), bounceIndex)
{}

void rectangle::draw(){
   left.draw();
   right.draw();
   top.draw();
   bottom.draw();
}

