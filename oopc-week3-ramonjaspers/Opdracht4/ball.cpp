#include "ball.hpp"
#include <iostream>

void ball::update(){
   location += speed;
}

ball::ball( window & w, const vector & midpoint, int radius, const vector & speed, const vector & bounceIndex):
   circle( w, midpoint, radius, bounceIndex),
   speed( speed )
{}

void ball::interact( drawable & other ){
   if( this != & other){
      if( overlaps( other )){
         speed.x *= other.bounceIndex.x;//other.wall.bounceIndex.x;
         speed.y *= other.bounceIndex.y;//other->;
      }
   }
}