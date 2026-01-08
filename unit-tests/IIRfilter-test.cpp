#include <iostream>
#include <vector>
#include "LowPassButterworth.hpp"
#include "HighPassButterworth.hpp"

int main() {
	int order = 10;
	double fc = 100;
	double fs = 1000;

	ko::LowPassButterworth lp(order, fc, fs);
	ko::HighPassButterworth hp(order, fc, fs);

	std::vector<double> lp_a_coeffs = lp.getFeedBackCoeffs();
	std::vector<double> lp_b_coeffs = lp.getFeedForwardCoeffs();

	std::vector<double> hp_a_coeffs = hp.getFeedBackCoeffs();
	std::vector<double> hp_b_coeffs = hp.getFeedForwardCoeffs();

	std::cout << "----- LOW PASS BUTTERWORTH FILTER -----" << std::endl;
	std::cout << "low pass feed-back coeffs: ";
	for(int i = 0; i < lp_a_coeffs.size(); i++) {
		std::cout << lp_a_coeffs[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "low pass feed-forward coeffs: ";
	for(int i = 0; i < lp_b_coeffs.size(); i++) {
		std::cout << lp_b_coeffs[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "----- HIGH PASS BUTTERWORTH FILTER -----" << std::endl;
	std::cout << "high pass feed-back coeffs: ";
	for(int i = 0; i < hp_a_coeffs.size(); i++) {
		std::cout << hp_a_coeffs[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "high pass feed-forward coeffs: ";
	for(int i = 0; i < hp_b_coeffs.size(); i++) {
		std::cout << hp_b_coeffs[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
