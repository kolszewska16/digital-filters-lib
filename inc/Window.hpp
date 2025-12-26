#pragma once
#include <vector>

namespace ko {
	class Window {
		protected:
			int m_size;
			std::vector<double> m_coeffs;

		public:
			Window(int size) : m_size(size), m_coeffs(size) {}
			virtual ~Window() {}
			int getSize();
			std::vector<double> getCoeffs();
			virtual void generateCoeffs() = 0;
			friend std::vector<double> operator* (const Window &w, const std::vector<double> &signal);
			friend std::vector<double> operator* (const std::vector<double> &signal, const Window &w);
	};
}
