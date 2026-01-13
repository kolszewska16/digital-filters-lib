#include <iostream>
#include <vector>
#include <string>

#include "FileHandler.hpp"
#include "HammingWindow.hpp"
#include "FIR.hpp"
#include "HighPassFIR.hpp"
#include "LowPassFIR.hpp"
#include "IIR.hpp"
#include "HighPassButterworth.hpp"
#include "LowPassButterworth.hpp"

int main() {
	// Define input and output file paths
	std::string read = "../example/noisy_signal.txt";
	std::string write = "../example/FIR_filtered_signal.txt";
	
	// Initialize file handler
	ko::FileHandler file(read, write);

	// Read signal data from the input file
	file.readData();
	std::vector<double> noisy_signal = file.getReadData();

	// Filter parameters
	int FIRorder {250};
	int IIRorder {4};
	double fs {1000.0};
	double f1 {75.0};
	double f2 {125.0};
	int window_size = FIRorder + 1;

	// Create window function for FIR filter design
	ko::HammingWindow hamm(window_size);

	// Create a high-pass and low-pass FIR filters
	ko::HighPassFIR	FIRhp(FIRorder, f1, fs, hamm);
	ko::LowPassFIR FIRlp(FIRorder, f2, fs, hamm);

	// Create a band-pass FIR filter
	ko::FIR FIRbp = FIRhp * FIRlp;
	
	// Apply a band-pass filter to the input signal
	std::vector<double> FIR_filtered_signal = FIRbp.processSamples(noisy_signal);
	
	// Write filtered signal samples to the output file
	file.writeData(FIR_filtered_signal);

	// Create a high-pass and low-pass IIR filters
	ko::HighPassButterworth IIRhp(IIRorder, f1, fs);
	ko::LowPassButterworth IIRlp(IIRorder, f2, fs);

	// Create a band-pass IIR filter
	ko::IIR IIRbp = IIRhp * IIRlp;

	// Apply a band-pass filter to the input signal
	std::vector<double> IIR_filtered_signal = IIRbp.processSamples(noisy_signal);

	// Define new output file and write filtered signal samples to the file
	std::string write_filename = "../example/IIR_filtered_signal.txt";
	file.setFilenameToWrite(write_filename);
	file.writeData(IIR_filtered_signal);
	
	return 0;
}
