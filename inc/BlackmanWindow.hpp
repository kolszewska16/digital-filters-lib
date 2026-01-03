#pragma once
#include "Window.hpp"

namespace ko {
	class BlackmanWindow : public Window {
		public:
			/**
			 * @brief Parametrized constructor of BlackmanWindow class.
			 * 
			 * Initializes BlackmanWindow object based on the input parameter.
			 *
			 * @param size	Length of the window.
			 */
			BlackmanWindow(int size);
			
			/**
			 * @brief Generats Blackman window coefficients.
			 * 
			 * The function calculates coefficients based on the length of the window.
			 * Computed coefficients are stored in the base Window class member vector `m_coeffs`.
			 */
			void generateCoeffs() override;
	};
}
