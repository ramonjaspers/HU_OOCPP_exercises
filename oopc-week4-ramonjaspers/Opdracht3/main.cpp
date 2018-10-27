#include "hwlib.hpp"

void kitt(hwlib::port_out & leds, int ms = 500) {
	for(;;) {
		for(unsigned int i = 0; i < leds.number_of_pins() -1; ++i) {
			leds.set(0x03 << i);
			hwlib::wait_ms(ms);
		}
		for(unsigned int i = leds.number_of_pins() - 3; i > 0; --i) {
			leds.set(0x03 << i);
			hwlib::wait_ms(ms);
		}
	}
}

int main(void) {
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;

	auto led0 = hwlib::target::pin_out(hwlib::target::pins::d8);
	auto led1 = hwlib::target::pin_out(hwlib::target::pins::d9);
	auto led2 = hwlib::target::pin_out(hwlib::target::pins::d10);
	auto led3 = hwlib::target::pin_out(hwlib::target::pins::d11);

	auto leds = hwlib::port_out_from_pins(led0, led1, led2, led3);
	::kitt(leds);
}
