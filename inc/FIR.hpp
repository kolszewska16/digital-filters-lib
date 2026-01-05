#pragma once
#include "Filter.hpp"
#include <vector>
#include <deque>

namespace ko {
	class FIR : public Filter {
		protected:
			/**
                         * @brief The order of the filter.
                         * Represents the number of taps minus one. A higher order provides
                         * a steeper roll-off but increases computational cost and latency.
                         */
			int m_order;
			
			/**
                         * @brief Cut-off frequency (Hz).
                         * The frequency at which the filter starts to attentuate the signal.
                         */
			double m_fc;

			 /**
                         * @brief Sampling frequency (Hz).
                         * The frequency at which the input signal was digitized.
                         */
			double m_fs;

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
			 * @brief
			 */
			FIR();

			/**
			 * @brief
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
                         * @brief Sets a new filter order.
                         *
                         * @param order The desired filter order.
                         */
			void setOrder(int order);

			/**
                         * @brief Sets a new cut-off frequency.
                         *
                         * @param fc    Cut-off frequency in Hz.
                         */
			void setCutOffFrequency(double fc);

			/**
                         * @brief Sets a new sampling frequency.
                         *
                         * @param fs    Sampling frequency in Hz.
                         */
			void setSamplingFrequency(double fs);

			/**
                         * @brief Gets the current filter order.
                         *
                         * @return The filter order.
                         */
			int getOrder();

			/**
                         * @brief Gets the current cut-off frequency.
                         *
                         * @return Cut-off frequency in Hz.
                         */
			double getCutOffFrequency();

			/**
                         * @brief Gets the current sampling frequency.
                         *
                         * @return Sampling frequency in Hz.
                         */
			double getSamplingFrequency();

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
