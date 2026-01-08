#pragma once
#include "Filter.hpp"
#include <vector>
#include <deque>

namespace ko {
	/**
	 * @brief
	 */
	class FIR : public Filter {
		protected:
			/**
			 * @brief Numerator coefficients of the FIR filter.
			 * These coefficients define the impulse response of the filter.
			 */
			std::vector<double> m_b;

			/**
			 * @brief Input delay line.
			 * Stores the recent input samples required for the convolution sum.
			 */
			std::deque<double> m_input_buff;

		public:
			/**
			 * @brief Parametrized constructor of FIR derived class.
			 * Initializes the filter order, cut-off frequency and sampling frequency.
			 *
			 * @param order	The filter order.
			 * @param fc	Cut-off frequency.
			 * @param fs	Sampling frequency.
			 */
			FIR(int order, double fc, double fs);

			/**
			 * @brief Processes a single sample through the FIR filter.
			 * Implements the difference equation by performing a convolution between
			 * the input buffer and the filter coefficients.
			 *
			 * @param sample	The new incoming data value.
			 *
			 * @return The filtered output value (sum of weighted inputs).
			 */
			double processSample(const double sample) override;

			/**
			 * @brief Processes an entire vector of samples.
			 * Iteratively applies the FIR algorithm to each sample in the input vector.
			 *
			 * @param sample	A refernce to the input data vector.
			 *
			 * @return A vector containing the filtered output data.
			 */
			std::vector<double> processSamples(const std::vector<double> &samples) override;

			/**
			 * @brief
			 */
			std::vector<double> getImpulseResponse();

			/**
			 * @brief
			 */
			friend FIR operator+ (const FIR& filter1, const FIR& filter2);

			/**
			 * @brief
			 */
			friend FIR operator* (const FIR& filter1, const FIR& filter2);
	};
}
