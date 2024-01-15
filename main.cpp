# include "TemperatureDatabase.h"
# include <iostream>

using std::cout, std::endl;

int main(int argc, char** argv) {

	// TemperatureData z;
	// z.id = "1222";
	// z.year = 2076;
	// z.month = 11;
	// z.temperature = 14.82;

	// TemperatureData y;
	// y.id = "1222";
	// y.year = 2017;
	// y.month = 10;
	// y.temperature = 14.82;

	// std::cout << stoi(z.id) << " " << stoi(y.id) << std::endl;
	// bool b = z < y;
	// cout << b;

	TemperatureDatabase x;
	x.loadData("temps-3lines.dat");



	if (argc < 3) {
		cout << "Usage: " << argv[0] << " data_file query_file" << endl;
		return 1;
	} else {
		TemperatureDatabase database;
		database.loadData(argv[1]);
		database.outputData(argv[1]); // comment out before submitting Part 2
		database.performQuery(argv[2]); // will be done in Part 2
	}
}
