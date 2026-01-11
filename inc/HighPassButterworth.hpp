#pragma once
#include "IIR.hpp"

namespace ko {
	/**
	 * @brief High-pass Butterworth IIR filter.
	 * Class implementing a high-pass Butterworth filter with an infinite impulse response. The
	 * filter provides a maximally flat frequency response in the passband.
	 */
	class HighPassButterworth : public IIR {
		public:
			/**
			 * @brief Parametrized constructor of HighPassButterworth derived class.
			 * Initializes and configures the filter parameters.
			 *
			 * @param order	Filter order.
			 * @param fc	Cut-off frequency in Hz.
			 * @param fs	Sampling frequency in Hz. 
			 */
			HighPassButterworth(const int order, const double fc, const double fs);
			
			/**
			 * @brief Calculates the Butterworth IIR filter coefficients for a high-pass
			 * response. Uses the specified parameters to design the filter impulse response.
			 */
			void designFilter();
	};
}
