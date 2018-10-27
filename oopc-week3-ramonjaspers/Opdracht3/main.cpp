#include <array>
#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "wall.hpp"

int main(){
   window w( vector( 128, 64 ), 2 );
   wall right( w, vector(124, 5), vector(128, 59));
   wall left( w, vector(0,  5), vector(4, 59 ));
   wall bottom(w, vector(0, 60), vector(128, 64));
   wall top( w, vector(0, 0), vector( 128, 4 ));
   ball b( w, vector( 50, 20 ), 9, vector( 5, 2 ) );
   
   std::array< drawable *, 5 > objects = { &b, &left, &top, &right, &bottom };

   for(;;){
      w.clear();
      for( auto & p : objects ){
         p->draw();
      }
	  wait_ms(200);
      for( auto & p : objects ){
		  //wait_ms(p->update_interval);
          p->update();
      }
      for( auto & p : objects ){
         for( auto & other : objects ){
            p->interact( *other );
         } 
      }
   }
}

