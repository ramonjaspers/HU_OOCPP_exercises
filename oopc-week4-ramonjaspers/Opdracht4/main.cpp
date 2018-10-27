
#include "hwlib.hpp"

void kitt(hwlib::port_out & leds, int ms = 500) {
	uint8_t mask = 240;
	for(;;) {
		if((PIOC->PIO_PDSR & (0x01 << 23)) == 0) {
			leds.set((mask>>=1)&15);
			hwlib::wait_ms(ms);
		} else {
			PIOB->PIO_CODR = 0x01 << 22;
		}
	}
}

int main(void) {
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	//enable due clock to listen
	PMC->PMC_PCER0 = (0x3F << 11);
	// make the GPIO pin an output
	PIOB->PIO_OER = 0x01 << 27;

	auto led0 = hwlib::target::pin_out(hwlib::target::pins::d8);
	auto led1 = hwlib::target::pin_out(hwlib::target::pins::d9);
	auto led2 = hwlib::target::pin_out(hwlib::target::pins::d10);
	auto led3 = hwlib::target::pin_out(hwlib::target::pins::d11);
	auto leds = hwlib::port_out_from_pins(led0, led1, led2, led3);
	::kitt(leds);
}
