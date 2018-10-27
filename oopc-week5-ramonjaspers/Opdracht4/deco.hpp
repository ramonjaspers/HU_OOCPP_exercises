
/*
#ifndef DECO_HPP
#define DECO_HPP

class pin_out_invert : public hwlib::pin_out {
private:
   hwlib::pin_out & slave;
   
public:
   pin_out_invert( hwlib::pin_out & slave ): 
      slave( slave ){}
   
   bool get() {
       return ! slave.get();
   }       
   
   void set( bool x ) {
      slave.set( ! x );
   }  
};



#endif //OOPC_18_DOUBLE_PORT_IN_DECORATOR_HPP

*/

#ifndef DECO_HPP
#define DECO_HPP

#include <array>
#include "hwlib.hpp"

class pin_out_all : public hwlib::pin_out {
private:
   std::array< hwlib::pin_out *, 4 > list;     
   
public:

   pin_out_all( 
      hwlib::pin_out & p0, 
      hwlib::pin_out & p1 = hwlib::pin_out_dummy,  
      hwlib::pin_out & p2 = hwlib::pin_out_dummy, 
      hwlib::pin_out & p3 = hwlib::pin_out_dummy 
   ):
      list{ &p0, &p1, &p2, &p3 }
   {}
   
   void set( 
      bool v, 
      hwlib::buffering buf = hwlib::buffering::unbuffered  
   ){
      for( auto p  : list ){
          p->set( v );
      }
   }
};

class pin_out_invert: public hwlib::pin_out {
private:
	hwlib::pin_out & pin;
public:
	pin_out_invert(hwlib::pin_out & pin): pin(pin) {}

	void set(bool x, hwlib::buffering buf = hwlib::buffering::unbuffered) override {
		pin.set(!x);
	}

	virtual void flush() {
		pin.flush();
	}
};

#endif //DECO_HPP
