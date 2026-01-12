#pragma once
#include "Filter.hpp"
#include <vector>
#include <deque>

namespace ko {
	/**
	 * @brief Class for FIR filters.
	 * Class representing finite impulse response (FIR) filters. Provides a common interface
	 * for FIR-based filter implementation.
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
			 * @brief Resets the FIR filter delay line.
			 * Fills the input sample buffer with zeros. Since FIR filters do not have
			 * feedback, this operation completely removes the influence of any previously
			 * processed signals.
			 */
			void reset() override;

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
			 * @brief Returns the impulse response of the FIR filter.
			 * 
			 * @return Vector containing the impulse response samples.
			 */
			std::vector<double> getImpulseResponse() const;

			/**
			 * @brief Adds two FIR filters.
			 * The operator creates a new FIR filter whose impulse response is the sum of
			 * the impulse responses of the input filters, which corresponds to a parallel
			 * connection. Both filters must be compatible, they must have the same sampling
			 * frequency.
			 *
			 * @param filter1	First FIR filter.
			 * @param filter2	Second FIR filter.
			 *
			 * @return FIR filter resulting from the addition.
			 */
			friend FIR operator+ (const FIR& filter1, const FIR& filter2);

			/**
			 * @brief Cascades two FIR filters.
			 * The operator creates a new FIR filter by convolving the impulse responses of
			 * the input filters, which corresponds to a cascade connection in the time domain.
			 * Both filters must be compatible, they must have the same sampling frequency.
			 *
			 * @param filter1	First FIR filter.
			 * @param filter2	Second FIR filter.
			 *
			 * @return FIR filter resulting from the cascade (convolution).
			 */
			friend FIR operator* (const FIR& filter1, const FIR& filter2);
	};
}
