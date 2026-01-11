#pragma once
#include "FIR.hpp"
#include "Window.hpp"
#include <vector>

namespace ko {
	/**
	 * @brief Low-pass FIR filter.
	 * Class implementing a low-pass FIR filter designed using a selected window function. The
	 * filter exhibits linear-phase characteristics.
	 */
	class LowPassFIR : public FIR {
		public:	
			/**
			 * @brief Parametrized constructor.
			 * Initializes and configures the filter parameters.
			 *
			 * @param order Filter order.
			 * @param fc    Cut-off frequency.
			 * @param fc    Sampling frequency.
			 */
			LowPassFIR(const int order, const double fc, const double fs, ko::Window &window);

			/**
			 * @brief Calculates the FIR filter coefficients for a high-pass response.
			 * Uses the specified parameters to design the filter impulse response.
			 *
			 * @param window
			 */
			void designFilter(ko::Window &window);
	};
}
