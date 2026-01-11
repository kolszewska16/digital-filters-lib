#pragma once
#include "IIR.hpp"

namespace ko {
	/**
	 * @brief Low-pass Butterworth IIR filter.
	 * Class implementing a low-pass Butterworth filter with an infinite impulse response. The
	 * filter provides a maximally flat frequency response in the passband.
	 */
	class LowPassButterworth : public IIR {
		public:
			/**
			 * @brief Parametrized constructor of LowPassButterworth derived class.
			 * Initializes and configures the filter parameters.
			 *
			 * @param order	Filter order.
			 * @param fc	Cut-off frequency in Hz.
			 * @param fs	Sampling frequency in Hz.
			 */
			LowPassButterworth(const int order, const double fc, const double fs);
			
			/**
			 * @brief Calculates the Butterworth IIR filter coefficients for a low-pass
			 * response. Uses the specified parameters to design the filter impulse response.
			 */			
			void designFilter();
	};
}
