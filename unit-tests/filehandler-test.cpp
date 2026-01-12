#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "FileHandler.hpp"
#include "HammingWindow.hpp"

void generateSine(const int freq, const int fs, const int N) {
	std::vector<double> signal(N);
	
	for(int i = 0; i < N; i++) {
		double t = (double)i / fs;
		signal[i] = std::sin(2 * M_PI * freq * t);
	}

	std::string write_file = "../unit-tests/signal_data.txt";
	ko::FileHandler file;
	file.setFilenameToWrite(write_file);
	file.writeData(signal);
}

int main() {
	std::string read_file = "../unit-tests/signal_data.txt";
	std::string write_file = "../unit-tests/output_data.txt";
	int freq = 10;
	int fs = 1000;
	int N = 1024;

	generateSine(freq, fs, N);
	ko::FileHandler file(read_file, write_file);
	std::string get_filename = file.getFilenameToRead();
	std::cout << "filename getter test: " << get_filename << std::endl;
	
	file.readData();
	std::vector<double> data = file.getReadData();

	ko::HammingWindow hamming(data.size());
	std::vector<double> output = hamming * data;
	file.writeData(output);
	
	return 0;
}
