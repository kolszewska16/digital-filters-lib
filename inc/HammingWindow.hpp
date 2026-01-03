#pragma once
#include "Window.hpp"

namespace ko {
	class HammingWindow : public Window {
		public:
			/**
			 * @brief Parametrized constructor of HammingWindow class.
			 * 
			 * Initializes HammingWindow object based on the input parameter.
			 *
			 * @param size	Length of the window.
			 */
			HammingWindow(int size);
			
			/**
			 * @brief Generates Hamming window coefficients.
			 * 
			 * The function calculates coefficients based on the length of the window.
			 * Computed coefficients are stored in the base Window class member vector `m_coeffs`.
			 */
			void generateCoeffs() override;
	};
}
