#include "hwlib.hpp"
#include "circle.hpp"
#include "line.hpp"
#include "rectangle.hpp"

int main(void) {
	WDT->WDT_MR = WDT_MR_WDDIS;

	namespace target = hwlib::target;

	auto scl = target::pin_oc(target::pins::scl);
	auto sda = target::pin_oc(target::pins::sda);

	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl,sda);

	auto display = hwlib::glcd_oled(i2c_bus, 0x3c);
	display.clear();

	int objectAmount = 3;
	for(unsigned int i = 0; i <= objectAmount ; i++) {
//start x-y , end x-y
		line diagonal_line(display, (i*30)+20, 10+3, (i*30) +20, 10 + 6);
		rectangle box(display, (i*30)+15, 10+8, (i*30)+26, 10 +33);
		circle ball(display, (i*30)+14, 10 +40, 7);
		circle ball2(display, (i*30)+ 27, 10 +40, 7);
		circle tip(display, (i*30)+20, 10 +8, 5);
		diagonal_line.print();
		box.print();
		ball.print();
		ball2.print();
		tip.print();
	}
}
