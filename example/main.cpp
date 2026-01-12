#include <iostream>
#include <vector>
#include <string>

#include "FileHandler.hpp"
#include "HammingWindow.hpp"
#include "FIR.hpp"
#include "HighPassFIR.hpp"
#include "LowPassFIR.hpp"

int main() {
	// Define input and output file paths
	std::string read = "../example/noisy_signal.txt";
	std::string write = "../example/filtered_signal.txt";
	
	// Initialize file handler
	ko::FileHandler file(read, write);

	// Read signal data from the input file
	file.readData();
	std::vector<double> noisy_signal = file.getReadData();

	// Filter parameters
	int order {250};
	double fs {1000.0};
	double f1 {75.0};
	double f2 {125.0};
	int window_size = order + 1;

	// Create window function for FIR filter design
	ko::HammingWindow hamm(window_size);

	// Create a high-pass and low-pass FIR filters
	ko::HighPassFIR	hp(order, f1, fs, hamm);
	ko::LowPassFIR lp(order, f2, fs, hamm);

	// Create a band-pass FIR filter
	ko::FIR bp = hp * lp;
	
	// Apply a band-pass filter to the input signal
	std::vector<double> filtered_signal = bp.processSamples(noisy_signal);
	
	// Write filtered signal samples to the output file
	file.writeData(filtered_signal);

	return 0;
}
