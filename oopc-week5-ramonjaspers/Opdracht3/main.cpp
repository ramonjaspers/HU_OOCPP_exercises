#include "hwlib.hpp"
#include "deco.hpp"

void kitt(hwlib::port_out & leds, int ms = 500) {
	uint16_t mask = 65280;
	auto button1 = hwlib::target::pin_in(hwlib::target::pins::d6);
	auto button2 = hwlib::target::pin_in(hwlib::target::pins::d7);

	and_pin_in button(button1, button2);
	int counter =0;
	for(;;) {
		if(button.get()== 1) {
			hwlib::cout << "true"<< hwlib::flush;
			leds.set((mask>>=1)&255);
			hwlib::wait_ms(ms);
			counter++;
		}
		
	}
}

int main(void) {
	WDT->WDT_MR = WDT_MR_WDDIS;
	namespace target = hwlib::target;
	auto ds   = target::pin_out(target::pins::d8);
	auto shcp = target::pin_out(target::pins::d9);
	auto stcp = target::pin_out(target::pins::d10);
	auto spi  = hwlib::spi_bus_bit_banged_sclk_mosi_miso(
	                stcp, ds, hwlib::pin_in_dummy
	            );

	auto hc595 = hwlib::hc595(spi, shcp);

	auto led0 = target::pin_out(target::pins::d5);
	auto led1 = target::pin_out(target::pins::d2);
	auto led2 = target::pin_out(target::pins::d3);
	auto led3 = target::pin_out(target::pins::d4);


	auto leds = hwlib::port_out_from_pins(
	                led0,
	                led1,
	                led2,
	                led3,
	                hc595.p0,
	                hc595.p1,
	                hc595.p2,
	                hc595.p3
	            );
	::kitt(leds);
}
