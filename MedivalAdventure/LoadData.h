#pragma once
#include <fstream>
#include <iostream>
#include <string>

#include <vector>
using namespace std;

class LoadData
{
public:
	void InitFiles() {

		fstream file;
		if (!is_file_exist("assets/data.txt"))
		{
			ofstream ofile("assets/data.txt", 'r' | 'w');
			ofile.close();
			file.open("assets/data.txt", 'r' | 'w');
			file << 100 << " " << 4 << " " << 1 << " " << 2 << " " << 0 << " " << 0 << " " << 0;
			file.close();
		}
	}

	vector<double> readNumbersFromFile(const string& filename) {
		vector<double> numbers;
		double num;

		ifstream infile(filename);
		if (!infile.is_open()) {
			cerr << "Error opening file: " << filename << endl;
			return numbers; // Return an empty vector if file cannot be opened
		}

		while (infile >> num) {
			numbers.push_back(num);
		}

		infile.close();
		return numbers;
	}


	void write_vector_to_file(const std::vector<double>& vec, const std::string& filename) {
		std::ofstream file(filename);
		for (const auto& num : vec) {
			file << num << " ";
		}

		file.close();
	}

private:

	bool is_file_exist(const char* fileName)
	{
		std::ifstream infile(fileName);
		return infile.good();
	}
};

