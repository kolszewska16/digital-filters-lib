#include "LowPassFIR.hpp"
#include <stdexcept>
#include <cmath>

namespace ko {
	LowPassFIR::LowPassFIR(int order, double fc, double fs, ko::Window &window) : FIR(order, fc, fs) {
		int size = order + 1;
		window.setSize(size);
		designFilter(window);
	}

	void LowPassFIR::designFilter(ko::Window &window) {
		if(m_fc > m_fs / 2) {
			throw std::invalid_argument("Cut-off frequency can not be greater than 0.5 * fs");
		}

		double fg = m_fc / m_fs;
		double N = m_order / 2.0;
		int size = m_order + 1;

		window.generateCoeffs();
		std::vector<double> w = window.getCoeffs();
		m_b.resize(size);

		for(int i = 0; i < size; i++) {
			double n = i - N;
			double h_ideal {0.0};

			if(n == 0) {
				h_ideal = 2 * fg;
			}
			else {
				h_ideal = 2 * fg * std::sin(2 * M_PI * fg * n) / (2 * M_PI * fg * n);
			}
			
			m_b[i] = h_ideal * w[i];
		}
	}
}
