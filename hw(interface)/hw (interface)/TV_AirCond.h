#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::string;

__interface IDevice
{
public:
	virtual void power() = 0;
	virtual void plus() = 0;
	virtual void minus() = 0;
	virtual void next() = 0;
	virtual void prev() = 0;
	virtual void showInfo() = 0;
	virtual void setName(const string& name) = 0;
	virtual string getName() = 0;
};

class TV : public IDevice
{
	static const int MAX_VOLUME = 100;
	int max_channels;
	bool start = false;
	int volume = 0;
	int channel = 1;
	string name;
public:
	TV(const int& max_channel = 10)
		:max_channels(max_channel) {}
	void power();
	void plus();
	void minus();
	void next();
	void prev();
	void showInfo();

	void setName(const string& name) override {
		this->name = name;
	}
	string getName() override {
		return name;
	}
};


enum AirConditionerMode {
	HEAT,
	COOL,
	TURBO,
	SLEEP
};
class AirConditioner : public IDevice
{
	static const int MAX_TEMPERATURE = 40;
	int max_modes;
	bool powerOn = false;
	int temperature = 0;
	int mode = 1;
	string name;

public:
	AirConditioner(const int& max_mode = 10)
		: max_modes(max_mode) {}
	void power();
	void plus();
	void minus();
	void next();
	void prev();
	void showInfo();

	void setName(const string& name) override {
		this->name = name;
	}
	string getName() override {
		return name;
	}
};

