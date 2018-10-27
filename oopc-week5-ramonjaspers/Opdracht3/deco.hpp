#ifndef DECO_HPP
#define DECO_HPP

class and_pin_in: public hwlib::pin_in {
private:
	hwlib::pin_in & pin;
	hwlib::pin_in & second_pin;
public:
	and_pin_in(hwlib::pin_in & pin, hwlib::pin_in & second_pin): pin(pin), second_pin(second_pin) {}

	virtual bool get(hwlib::buffering buf = hwlib::buffering::unbuffered) override {
		return(pin.get() ==0 && second_pin.get() ==0);
	}

	virtual void refresh() {
		pin.refresh();
		second_pin.refresh();
	}
};

#endif //DECO_HPP
