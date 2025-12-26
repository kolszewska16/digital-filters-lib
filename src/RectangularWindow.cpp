#include "RectangularWindow.hpp"
#include <stdexcept>

namespace ko {
	RectangularWindow::RectangularWindow(int size) : Window(size) {
		if(size < 1) {
			throw std::invalid_argument("Window size must be greater or equal 1");
		}
		generateCoeffs();
	}

	void RectangularWindow::generateCoeffs() {
		for(int i = 0; i < m_size; i++) {
			m_coeffs[i] = 1.0;
		}
	}
}
