#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "FileHandler.hpp"

int main() {
	const std::string filename = "../example/noisy_signal.txt";
	ko::FileHandler file;
	file.setFilenameToWrite(filename);

	srand(static_cast<unsigned int>(time(0)));

	double f1 {50.0};
	double f2 {100.0};
	double f3 {150.0};
	double fs {1000.0};
	double duration {2.0};
	int num_samples = static_cast<int>(fs * duration);
	
	double t {0.0};
	double signal {0.0};
	double noise {0.0};
	std::vector<double> noise_signal(num_samples);

	for(int i = 0; i < num_samples; i++) {
		t = i / fs;
		signal = std::sin(2 * M_PI * f1 * t) + std::sin(2 * M_PI * f2 * t) + std::sin(2 * M_PI * f3 * t);
		noise = static_cast<double>(rand() / RAND_MAX) - 0.5;
		noise_signal[i] = signal + noise;	
	}

	file.writeData(noise_signal);
	return 0;
}
