#pragma once
#include "Window.hpp"

namespace ko {
	/**
	 * @brief Class implementing Rectangular window.
	 */
	class RectangularWindow : public Window {
		public:
			/**
			 * @brief Parametrized consturctor of RectangularWindow class.
			 * Initializes RectangularWindow object based on the input parameter.
			 *
			 * @param size	Length of the window.
			 */
			RectangularWindow(int size);
			
			/**
			 * @brief Generates Rectangular window coefficients.
			 * The function calculates the coefficients based on the length of the window.
			 * Computed coefficients are stored in the base Window class member vector `m_coeffs`.
			 */
			void generateCoeffs() override;
	};
}
