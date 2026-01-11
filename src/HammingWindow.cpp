#include "HammingWindow.hpp"
#include <stdexcept>
#include <cmath>

namespace ko {
	HammingWindow::HammingWindow(int size) : Window(size) {
		if(size < 2) {
			throw std::invalid_argument("Window size must be greater or equal 2");
		}
		generateCoeffs();
	}

	void HammingWindow::generateCoeffs() {
		for(int i = 0; i < m_size; i++) {
			m_coeffs[i] = 0.54 - 0.46 * std::cos((2 * M_PI * i) / (m_size - 1));
		}
	}
}
