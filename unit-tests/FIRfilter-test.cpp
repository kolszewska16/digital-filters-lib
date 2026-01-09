#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "HighPassFIR.hpp"
#include "LowPassFIR.hpp"
#include "HammingWindow.hpp"
#include "FileHandler.hpp"

std::vector<double> generateSignal(double fs, double duration, double f1, double f2) {
	int num_samples = static_cast<int>(fs * duration);
	std::vector<double> signal(num_samples);

	for(int i = 0; i < num_samples; i++) {
		double t = i / fs;
		signal[i] = std::sin(2 * M_PI * f1 * t) + std::sin(2 * M_PI * f2 * t);
	}

	return signal;
}

int main() {
	int order {10};
	double fs {1000};
	int size = order + 1;

	double duration {1.0};
	double f1 {50.0};
	double f2 {150.0};

	ko::HammingWindow hamm(size);
	ko::HighPassFIR hp1FIR(order, 60, fs, hamm);
	ko::LowPassFIR lp1FIR(order, 40, fs, hamm);

	ko::HighPassFIR hp2FIR(order, 100, fs, hamm);
	ko::LowPassFIR lp2FIR(order, 200, fs, hamm);

	std::vector<double> signal = generateSignal(fs, duration, f1, f2);

	std::vector<double> hp1FIR_b = hp1FIR.getImpulseResponse();
	std::vector<double> lp1FIR_b = lp1FIR.getImpulseResponse();
	std::vector<double> hp2FIR_b = hp2FIR.getImpulseResponse();
	std::vector<double> lp2FIR_b = lp2FIR.getImpulseResponse();

	std::cout << "----- BANDSTOP FILTER -----" << std::endl;
	std::cout << "high pass FIR filter (hamm window, 60Hz): "; 
	for(int i = 0; i < hp1FIR_b.size(); i++) {
		std::cout << hp1FIR_b[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "low pass FIR filter (hamm window, 40Hz): ";
	for(int i = 0; i < lp1FIR_b.size(); i++) {
		std::cout << lp1FIR_b[i] << " ";
	}
	std::cout << std::endl;

	ko::FIR bandstopFIR = hp1FIR + lp1FIR;
	std::vector<double> bandstopFIR_b = bandstopFIR.getImpulseResponse();
	std::cout << "bandstop filter: ";
	double bs_sum {0.0};
	for(int i = 0; i < bandstopFIR_b.size(); i++) {
		std::cout << bandstopFIR_b[i] << " ";
		bs_sum += bandstopFIR_b[i];
	}
	std::cout << std::endl;
	std::cout << "bs sum: " << bs_sum << std::endl;

	std::cout << "----- BANDPASS FILTER -----" << std::endl;
	std::cout << "high pass FIR filter (hamm window, 100Hz): ";
	double hp2_sum {0.0};
	for(int i = 0; i < hp2FIR_b.size(); i++) {
		std::cout << hp2FIR_b[i] << " ";
		hp2_sum += hp2FIR_b[i];
	}
	std::cout << std::endl;
	std::cout << "hp2[5]: " << hp2FIR_b[5] << std::endl;
	std::cout << "hp2 sum: " << hp2_sum << std::endl;

	std::cout << "low pass FIR filter (hamm window, 200Hz): ";
	double lp2_sum {0.0};
	for(int i = 0; i < lp2FIR_b.size(); i++) {
		std::cout << lp2FIR_b[i] << " ";
		lp2_sum += lp2FIR_b[i];
	}
	std::cout << std::endl;
	std::cout << "lp2[5]: " << lp2FIR_b[5] << std::endl;
	std::cout << "lp2 sum: " << lp2_sum << std::endl;

	ko::FIR bandpassFIR = hp2FIR * lp2FIR;
	std::vector<double> bandpassFIR_b = bandpassFIR.getImpulseResponse();
	std::cout << "bandpass filter: ";
	for(int i = 0; i < bandpassFIR_b.size(); i++) {
		std::cout << bandpassFIR_b[i] << " ";
	}
	std::cout << std::endl;

	double bp_sum {0.0};
	for(int i = 0; i < bandpassFIR_b.size(); i++) {
		bp_sum += bandpassFIR_b[i];
	}
	std::cout << "bp sum: " << bp_sum << std::endl;

	std::vector<double> filtered_signal = bandpassFIR.processSamples(signal);
	std::string filename = "../unit-tests/FIR-filtered-signal.txt";
	ko::FileHandler file;
	file.setFilenameToWrite(filename);
	file.writeData(filtered_signal);

	return 0;
}
