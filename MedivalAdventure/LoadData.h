#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class LoadData
{
public:
	void InitFiles() {
		fstream file;
		file.open("assets/money.txt");
		file << "100";
		file.close();


	}

	int LoadFromFile(string path) {
		fstream file;
		
		file.open(path);
		file.read(result, 100);
		
		//remove spaces
		*std::remove(result, result + strlen(result), ' ') = 0;
		
		if ((result != NULL) && (result[0] == '\0')) {
			file.close();
			return -1;
		}

		file.close();

		return strtol(result, NULL, 0);
	}

private:
	int money = 100;
	char* result;
};

