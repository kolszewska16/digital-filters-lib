#include <iostream>
#include <vector>
#include <math.h>
#include "RectangularWindow.hpp"
#include "HammingWindow.hpp"
#include "HanningWindow.hpp"
#include "BlackmanWindow.hpp"

std::vector<double> generateSin(int freq, int fs, int N) {
	std::vector<double> signal(N);
	for(int i = 0; i < N; i++) {
		double t = (double)i / fs;
		signal[i] = sin(2 * M_PI * freq * t);
	}
	return signal;
}

int main() {
	int freq = 10;
	int fs = 50;
	int N = 16;

	std::vector<double> signal = generateSin(freq, fs, N);
	std::cout << "sine: ";
	for(int i = 0; i < N; i++) {
		std::cout << signal[i] << " ";
	}
	std::cout << std::endl;

	ko::RectangularWindow rectangular(N);
	int rectangular_size = rectangular.getSize();
	std::cout << "rectangular_size: " << rectangular_size << std::endl;
	
	std::vector<double> rectangular_coeff = rectangular.getCoeffs();
	std::cout << "rectangular_coeff: ";
	for(int i = 0; i < rectangular_size; i++) {
		std::cout << rectangular_coeff[i] << " ";
	}
	std::cout << std::endl;
	
	std::vector<double> rectangular_signal = rectangular * signal;
	std::cout << "rectangular_window * signal: ";
	for(int i = 0; i < N; i++) {
		std::cout << rectangular_signal[i] << " ";
	}
	std::cout << std::endl;

	ko::HammingWindow hamming(N);
	int hamming_size = hamming.getSize();
	std::cout << "hamming_size: " << hamming_size << std::endl;
	
	std::vector<double> hamming_coeff = hamming.getCoeffs();
	std::cout << "hamming_coeff: ";
	for(int i = 0; i < hamming_size; i++) {
		std::cout << hamming_coeff[i] << " ";
	}
	std::cout << std::endl;

	std::vector<double> hamming_signal = signal * hamming;
	std::cout << "signal * hamming_window: ";
	for(int i = 0; i < N; i++) {
		std::cout << hamming_signal[i] << " ";
	}
	std::cout << std::endl;

	ko::HanningWindow hanning(N);
	int hanning_size = hanning.getSize();
	std::cout << "hanning_size: " << hanning_size << std::endl;
	
	std::vector<double> hanning_coeff = hanning.getCoeffs();
	std::cout << "hanning_coeff: ";
	for(int i = 0; i < hanning_size; i++) {
		std::cout << hanning_coeff[i] << " ";
	}
	std::cout << std::endl;

	std::vector<double> hanning_signal = hanning * signal;
	std::cout << "hanning_window * signal: ";
	for(int i = 0; i < N; i++) {
		std::cout << hanning_signal[i] << " ";
	}
	std::cout << std::endl;

	ko::BlackmanWindow blackman(N);
	int blackman_size = blackman.getSize();
	std::cout << "blackman_size: " << blackman_size << std::endl;
	
	std::vector<double> blackman_coeff = blackman.getCoeffs();
	std::cout << "blackman_coeff: ";
	for(int i = 0; i < blackman_size; i++) {
		std::cout << blackman_coeff[i] << " ";
	}
	std::cout << std::endl;

	std::vector<double> blackman_signal = signal * blackman;
	std::cout << "signal * blackman_window: ";
	for(int i = 0; i < N; i++) {
		std::cout << blackman_signal[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
