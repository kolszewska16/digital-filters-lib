#include "HanningWindow.hpp"
#include <stdexcept>
#include <cmath>

namespace ko {
	HanningWindow::HanningWindow(int size) : Window(size) {
		if(size < 2) {
			throw std::invalid_argument("Window size must be greater or equal 2");
		}
		generateCoeffs();
	}

	void HanningWindow::generateCoeffs() {
		for(int i = 0; i < m_size; i++) {
			m_coeffs[i] = 0.5 * (1 - std::cos((2 * M_PI * i) / (m_size - 1)));
		}
	}
}
