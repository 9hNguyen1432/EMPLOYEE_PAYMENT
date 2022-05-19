#pragma once
#include<tuple>
#include<string>
#include<fstream>
#include<vector>
#include"Information.h"

vector<tuple<string, string, int*>> getDataFromFile(string fileName);