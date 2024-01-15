# include "TemperatureData.h"
# include <iostream>
using std::string;

TemperatureData::TemperatureData() : id(""), year(0), month(0), temperature(0) {
	// TODO: implement this function
}

TemperatureData::TemperatureData(string id, int year, int month, double temperature) : id(id), year(year), month(month), temperature(temperature) {
	// TODO: implement this function

}

TemperatureData::~TemperatureData() {
	id = "";
	year = 0;
	month = 0;
	temperature = 0.0;
}

TemperatureData& TemperatureData::operator=(const TemperatureData& other) {
    // Assignment operator
    this->id = other.id;
    this->year = other.year;
    this->month = other.month;
    this->temperature = other.temperature;
    return *this;
}

bool TemperatureData::operator<(const TemperatureData& b) {
	// TODO: implement this function
	std::cout << this->id << " " << this->year << " " << this->month << " " << std::endl;
	std::cout << b.id << " " << b.year << " " << b.month << " " << std::endl;
	if (this->id < b.id) {return true;}
	else if (!(this->id == b.id)) {return false;}
	if (this->year < b.year) {return true;}
	else if (!(this->year == b.year)) {return false;}
	if (this->month < b.month) {return true;}
	else {return false;}
}

