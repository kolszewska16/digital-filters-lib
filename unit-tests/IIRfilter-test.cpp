#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "LowPassButterworth.hpp"
#include "HighPassButterworth.hpp"
#include "FileHandler.hpp"

std::vector<double> generateSignal(const double fs, const double duration, const double f1, const double f2) {
	int num_samples = static_cast<int>(fs * duration);
	std::vector<double> signal(num_samples);
	
	for(int i = 0; i < num_samples; i++) {
		double t = i / fs;
		signal[i] = std::sin(2 * M_PI * f1 * t) + std::sin(2 * M_PI * f2 * t);
	}

	return signal;
}

int main() {
	int order {4};
	double fs = {1000};
	
	double duration {1.0};
	double f1 {50.0};
	double f2 {150.0};

	ko::LowPassButterworth lp1IIR(order, 60, fs);
	ko::HighPassButterworth hp1IIR(order, 40, fs);
	ko::LowPassButterworth lp2IIR(order, 200, fs);
	ko::HighPassButterworth hp2IIR(order, 100, fs);

	std::vector<double> signal = generateSignal(fs, duration, f1, f2);

	std::vector<double> lp1_a_coeffs = lp1IIR.getFeedBackCoeffs();
	std::vector<double> lp1_b_coeffs = lp1IIR.getFeedForwardCoeffs();

	std::vector<double> hp1_a_coeffs = hp1IIR.getFeedBackCoeffs();
	std::vector<double> hp1_b_coeffs = hp1IIR.getFeedForwardCoeffs();

	std::cout << "----- LOW PASS BUTTERWORTH FILTER (60Hz) -----" << std::endl;
	std::cout << "low pass feed-back coeffs: ";
	for(int i = 0; i < lp1_a_coeffs.size(); i++) {
		std::cout << lp1_a_coeffs[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "low pass feed-forward coeffs: ";
	for(int i = 0; i < lp1_b_coeffs.size(); i++) {
		std::cout << lp1_b_coeffs[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "----- HIGH PASS BUTTERWORTH FILTER (40Hz) -----" << std::endl;
	std::cout << "high pass feed-back coeffs: ";
	for(int i = 0; i < hp1_a_coeffs.size(); i++) {
		std::cout << hp1_a_coeffs[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "high pass feed-forward coeffs: ";
	for(int i = 0; i < hp1_b_coeffs.size(); i++) {
		std::cout << hp1_b_coeffs[i] << " ";
	}
	std::cout << std::endl;

	ko::IIR bandstopIIR = lp1IIR + hp1IIR;
	std::vector<double> bs_a_coeffs = bandstopIIR.getFeedBackCoeffs();
	std::vector<double> bs_b_coeffs = bandstopIIR.getFeedForwardCoeffs();
	std::cout << "----- BAND STOP BUTTERWORTH FILTER -----" << std::endl;
	std::cout << "band stop feed-back coeffs: ";
	for(int i = 0; i < bs_a_coeffs.size(); i++) {
		std::cout << bs_a_coeffs[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "band stop feed-forward coeffs: ";
	for(int i = 0; i < bs_b_coeffs.size(); i++) {
		std::cout << bs_b_coeffs[i] << " ";
	}
	std::cout << std::endl;


	ko::IIR bandpassIIR = lp2IIR * hp2IIR;
	std::vector<double> bp_a_coeffs = bandpassIIR.getFeedBackCoeffs();
	std::vector<double> bp_b_coeffs = bandpassIIR.getFeedForwardCoeffs();
	std::cout << "----- BAND PASS BUTTERWORTH FILTER -----" << std::endl;
	std::cout << "band pass feed-back coeffs: ";
	for(int i = 0; i < bp_a_coeffs.size(); i++) {
		std::cout << bp_a_coeffs[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "band pass feed-forward coeffs: ";
	for(int i = 0; i < bp_b_coeffs.size(); i++) {
		std::cout << bp_b_coeffs[i] << " ";
	}
	std::cout << std::endl;

	std::vector<double> filtered_signal = bandpassIIR.processSamples(signal);
	ko::FileHandler file;
	std::string filename = "../unit-tests/IIR-filtered-signal.txt";
	file.setFilenameToWrite(filename);
	file.writeData(filtered_signal);

	return 0;
}
