# include "TemperatureDatabase.h"
# include <fstream>

using std::cout, std::endl, std::string, std::ofstream, std::ifstream;

TemperatureDatabase::TemperatureDatabase() : records() {}
TemperatureDatabase::~TemperatureDatabase() {
	records.clear();
}

void TemperatureDatabase::loadData(const string& filename) {
	// TODO: implement this function
	ifstream dataFS;
	string id, ending, tempStr;
	int year;
	double temperature, month;
	TemperatureData newData;
	Node newNode;
	bool emptyTemp, error = false;

	dataFS.open(filename);
  	if (!dataFS.is_open()) {
    	throw std::runtime_error("Failed to open " + filename);
  	}

	while (!dataFS.eof()) {
		if (emptyTemp) {
			id = tempStr;
			emptyTemp = false;
		}
		else {
			dataFS >> id;
			if (dataFS.eof()) {
				break;
			}
		}

		dataFS >> year;
		if (year < 1800 || year > 2023) {
			std::cout << "Error: Invalid year " << year << std::endl;
			error = true;
		}

		dataFS >> month;
		if (month != int(month)) {
			std::cout << "Error: Other invalid input" << std::endl;
			error = true;
		}		
		else if (month > 12 || month < 1) {
			month = int(month);
			std::cout << "Error: Invalid month " << month << std::endl;
			error = true;
		}
		month = int(month);

		dataFS >> temperature;
		
		if (temperature != -99.99 && (temperature < -50.0 || temperature > 50.0)) {
			if (temperature >= 10000 && temperature <= 99999) {
				emptyTemp = true;
				tempStr = std::to_string(int(temperature));
				std::cout << "Error: Other invalid input " << std::endl;
				error = true;
			}
			else {
				std::cout << "Error: Invalid temperature " << std::to_string(temperature) << std::endl;
				error = true;
			}
		}

		if (!error) {
			newData.id = id;
			newData.month = month;
			newData.year = year;
			newData.temperature = temperature;
			
			newNode.data = newData;

			records.insert(newNode.data.id, newNode.data.year, newNode.data.month, newNode.data.temperature);
			
		}
	}

	if (!dataFS.eof()) {            
    	dataFS >> ending; 
    	if (!dataFS.eof()) {throw std::runtime_error("Too many values");}
    	else if (ending != " " && ending != "") {throw std::runtime_error("Too many values");}
  	}

	cout << records.print();
}

void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}

	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// TODO: implement this function
}
