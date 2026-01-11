#pragma once
#include "FIR.hpp"
#include "Window.hpp"
#include <vector>

namespace ko {
	/**
	 * @brief High-pass FIR filter.
	 * Class implementing a high-pass FIR filter designed using a selected window function. The
	 * filter exhibits linear-phase characteristics.
	 */
	class HighPassFIR : public FIR {
		public:
			/**
			 * @brief Parametrized constructor.
			 * Initializes and configures the filter parameters.
			 *
			 * @param order	Filter order.
			 * @param fc	Cut-off frequency.
			 * @param fc	Sampling frequency.
			 */
			HighPassFIR(const int order, const double fc, const double fs, ko::Window &window);

			/**
			 * @brief Calculates the FIR filter coefficients for a high-pass response.
			 * Uses the specified parameters to design the filter impulse response.
			 *
			 * @param window
			 */
			void designFilter(ko::Window &window);
	};
}
