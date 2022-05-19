#include"Ulti.h"

vector<tuple<string, string, int*>> getDataFromFile(string fileName) {
	ifstream fin;
	fin.open(fileName);
	string data;
	vector<tuple<string, string, int*>> result;

	if (!fin.is_open()) {
		cout << "Cann't open file " << fileName << endl;
		return result;
	}

	bool successful = true;
	int errorCode = 0;
	string message = "";
	tuple<string, string, int*> info;

	while (getline(fin, data, '\n')) {
		tie(successful, errorCode, message, info) = Information::parse(data);
		if (successful) {
			result.push_back(info);
		}
		else {
			cout << message << " : " << data << endl;
		}
	}

	fin.close();
	return result;
}