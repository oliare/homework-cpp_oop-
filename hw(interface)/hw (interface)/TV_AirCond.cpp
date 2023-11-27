#include "TV_AirCond.h"

void TV::power()
{
	start = !start;
	start ? "TV is ON" : "TV is OFF";
}

void TV::plus()
{
	if (volume < MAX_VOLUME) {
		volume++;
	}
	showInfo();
}

void TV::minus()
{
	if (volume > 0) {
		volume--;
	}
	showInfo();
}

void TV::next()
{
	channel++;
	if (channel > max_channels) {
		channel = 1;
	}
	showInfo();
}

void TV::prev()
{
	channel--;
	if (channel < 1) {
		channel = max_channels;
	}
	showInfo();

}

void TV::showInfo()
{
	cout << "\n\n\t*  TV  *  \n";
	if (!start) {
		cout << "TV is OFF" << endl;
		return;
	}
	cout << "TV is ON" << endl;
	cout << "Volume  :: " << volume << endl;
	cout << "Channel :: " << channel << endl;

}

///////// AIR CONDITIONER /////////


void AirConditioner::power() {
	powerOn = !powerOn;
	powerOn ? "Air Conditioner is ON" : "Air Conditioner is OFF" ;
}

void AirConditioner::plus() {
	if (temperature < MAX_TEMPERATURE) {
		temperature++;
		showInfo();
	}
}

void AirConditioner::minus() {
	if (temperature > 0) {
		temperature--;
		showInfo();
	}
}

void AirConditioner::next() {
	if (powerOn) {
		mode = static_cast<AirConditionerMode>((mode + 1) % 4);
		showInfo();
	}
}

void AirConditioner::prev() {
	if (powerOn) {
		mode = static_cast<AirConditionerMode>((mode + 3) % 4);
		showInfo();
	}
}

void AirConditioner::showInfo() {
	cout << "\n\n\t*  Air Conditioner  *  \n"<<endl;
	if (!powerOn) {
		cout << "Air Conditioner is OFF" << endl;
		return;
	}
	cout << "Air Conditioner is ON" << endl;
	cout << "Temperature :: " << temperature << endl;
	cout << "Mode        :: ";
	switch (mode) {
	case HEAT:
		cout << "Heating";
		break;
	case COOL:
		cout << "Cooling";
		break;
	case TURBO:
		cout << "Turbo";
		break;
	case SLEEP:
		cout << "Sleep";
		break;
	}
	cout << endl;
}
