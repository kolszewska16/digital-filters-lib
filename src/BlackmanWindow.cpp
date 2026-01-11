#include "BlackmanWindow.hpp"
#include <stdexcept>
#include <cmath>

namespace ko {
	BlackmanWindow::BlackmanWindow(int size) : Window(size) {
		if(size < 2) {
			throw std::invalid_argument("Window sie must be greater or equal 2");
		}
		generateCoeffs();
	}

	void BlackmanWindow::generateCoeffs() {
		for(int i = 0; i < m_size; i++) {
			m_coeffs[i] = 0.42 - 0.5 * std::cos((2 * M_PI * i) / (m_size - 1)) + 0.08 * std::cos((4 * M_PI * i) / (m_size - 1));
		}
	}
}
