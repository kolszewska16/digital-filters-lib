#include "Window.hpp"
#include <vector>
#include <stdexcept>

namespace ko {
	int Window::getSize() {
		return m_size;
	}

	std::vector<double> Window::getCoeffs() {
		return m_coeffs;
	}

	std::vector<double> operator* (const Window &w, const std::vector<double> &signal) {
		if(signal.size() != w.m_coeffs.size()) {
			throw std::invalid_argument("Signal length must match window size");
		}

		std::vector<double> result(signal.size());
		for(int i = 0; i < signal.size(); i++) {
			result[i] = w.m_coeffs[i] * signal[i];
		}
		return result;
	}

	std::vector<double> operator* (const std::vector<double> &signal, const Window &w) {
        	if(signal.size() != w.m_coeffs.size()) {
                	throw std::invalid_argument("Signal length must match window size");
        	}

        	std::vector<double> result(signal.size());
        	for(int i = 0; i < signal.size(); i++) {
                	result[i] = signal[i] * w.m_coeffs[i];
        	}
        	return result;
	}
}

