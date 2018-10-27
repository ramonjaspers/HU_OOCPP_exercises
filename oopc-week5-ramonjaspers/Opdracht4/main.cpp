#include "hwlib.hpp"
#include "deco.hpp"

/*void kitt(hwlib::port_out & leds, int ms = 500) {
	uint32_t mask = 65280;
	for(;;) {
		leds.set((mask<<=254));
		hwlib::wait_ms(ms);
		leds.set((mask>>=254));
		hwlib::wait_ms(ms);
		hwlib::cout << "hoihoi";
	}
}*/

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



	pin_out_all leds1(led0, led1, led2, led3);
	pin_out_all leds2(hc595.p0, hc595.p1, hc595.p2, hc595.p3);

	pin_out_invert led1_inverted(leds1);

	hwlib::port_out_from_pins kutt_port(
	    leds1, leds2
	);
	hwlib::kitt(kutt_port);
	pin_out_all kutt_blink(led1_inverted, leds2);

	//kitt
	//hwlib::kitt(kutt_port);
	//blink
	hwlib::blink(kutt_blink);
}
