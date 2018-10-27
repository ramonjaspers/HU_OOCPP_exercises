#include "hwlib.hpp"

void kitt(hwlib::port_out & leds, int ms = 500) {
	uint16_t mask = 65280;
	for(;;) {
		if((PIOC->PIO_PDSR & (0x01 << 24)) == 0) {
			leds.set((mask<<=1)&255);
			hwlib::wait_ms(ms);
		} else {
			PIOB->PIO_CODR = 0x01 << 22;
		}
		if((PIOC->PIO_PDSR & (0x01 << 23)) == 0) {
			leds.set((mask>>=1)&255);
			hwlib::wait_ms(ms);
		} else {
			PIOB->PIO_CODR = 0x01 << 22;
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

	auto led0 = target::pin_out(target::pins::d1);
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
