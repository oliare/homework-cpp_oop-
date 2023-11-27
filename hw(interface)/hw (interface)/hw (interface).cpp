#include <iostream>
#include "SmartRemote.h"

int main()
{
	TV lg, samsung;
	AirConditioner ac;

	SmartRemote remote(&lg);

	lg.setName("LG");
	remote.addDevice(&lg);

	samsung.setName("Samsung");
	remote.addDevice(&samsung);

	ac.setName("Hunter");
	remote.addDevice(&ac);

	remote.setCurrentDevice(&lg);
	remote.testDevice();


}