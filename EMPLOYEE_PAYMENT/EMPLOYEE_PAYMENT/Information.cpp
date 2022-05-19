#include "Information.h"
#include<sstream>
#include<regex>
#include<string>
#include"EmployeeFactory.h"

tuple<bool, int, string, tuple<string,string,int*>> Information::parse(string data) {
	bool successful = true;
	int errorCode = 0;
	string message = "";
	string category = "";
	string name = "";
	int* number= new int[3];

	if (data == "") {
		successful = false;
		errorCode = 1;
		message = "Empty data";
	}
	else {
		stringstream ss;
		ss << data;
		string temp;
		
		//category
		if (getline(ss, temp,':')) {
			if (EmployeeFactory::instance()->getPrototype(temp) != NULL) {
				category = temp;
			}
			else {
				errorCode = 2;
				message = "Invalid employee's type";
				goto End;
			}
		}
		else {
			errorCode = 3;
			message = "Invalid information format";
			goto End;
		}

		//name
		if (getline(ss, temp, ';')) {
			name = temp;
		}
		else {
			errorCode = 3;
			message = "Invalid format information";
			goto End;
		}

		//number
		string pattern;
		for (int i = 0; ss.eof()==false ; i++) {
			pattern = "\\d+";

			if (getline(ss, temp, ';')) {
				int pos = temp.find('=');

				if (pos != string::npos) {
					temp = temp.substr(pos+1, temp.length());

					if (i % 2 == 0)
						pattern = "\\d+\\$";
					bool isMatched = regex_match(temp, regex(pattern));

					if (isMatched) {
						if (i % 2 == 0)
							temp = temp.substr(0, temp.length() - 1);
						number[i] = stoi(temp);
						continue;
					}
					errorCode = 3;
					message = "Invalid information format";
					goto End;
				}
			}
		}
	}

	End:
	if (errorCode != 0)
		successful = false;

	tuple<string, string, int*> info = tie(category, name, number);
	tuple<bool, int, string, tuple<string, string, int*>> result = tie(successful, errorCode, message, info);

	return result;
}
