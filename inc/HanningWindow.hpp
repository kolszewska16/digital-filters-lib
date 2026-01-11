#pragma once
#include "Window.hpp"

namespace ko {
	/**
	 * @brief Class implementing the Hanning window.
	 */
	class HanningWindow : public Window {
		public:
			/**
			 * @brief Parametrized constructor of HanningWindow class.
			 * Initializes HanningWindow object based on the input parameter.
			 *
			 * @param size	Length of the window.
			 */
			HanningWindow(int size);
			
			/**
			 * @brief Generates Hanning window coefficients.
			 * The function calculates coefficients based on the length of the window.
			 * Computed coefficients are stored in the base Window class member vector `m_coeffs`.
			 */
			void generateCoeffs() override;
	};
}
