#pragma once
#include "Filter.hpp"
#include <vector>

namespace ko {
	/**
	 * @brief Class for IIR filters.
	 * Class representing infinite impulse response (IIR) filters, characterized by recursive structure.
	 * Provides a common interface for IIR-based filter implementation.
	 */
	class IIR : public Filter {
		protected:
			/**
			 * @brief Feedback (denominator) coefficients of the IIR filter.
			 * These coefficients define the recursive part of the filter difference
			 * equation.
			 */
			std::vector<double> m_a;
			
			/**
			 * @brief Feedforward (numerator) coefficients of the IIR filter.
			 * These coefficients define the non-recursive part of the filter difference
			 * equation.
			 */
			std::vector<double> m_b;
			
			/**
			 * @brief History of input samples.
			 * Stores previous input samples required for recursive filtering.
			 */
			std::vector<double> m_x_history;
			
			/**
			 * @brief History of output samples.
			 * Stores previous output samples required for recursive filtering.
			 */
			std::vector<double> m_y_history;

		public:
			/**
			 * @brief Parametrized constructor of IIR derived  class.
			 * Initializes an Infinite Impulse Response (IIR) filter of a specified order,
			 * cut-off frequency and sampling frequency.
			 *
			 * @param order	Filter order.
			 * @param fc	Cut-off frequency in Hz.
			 * @param fs	Sampling frequency in Hz.
			 */
			IIR(const int order, const double fc, const double fs);
			
			/**
			 * @brief Processes a single input sample.
			 * Applies the IIR filter difference equation to the input sample and returns the
			 * filtered output value.
			 *
			 * @param sample	Input signal sample.
			 *
			 * @return Filtered output sample.
			 */
			double processSample(const double sample) override;
			
			/**
			 * @brief Processes a vector of input samples.
			 * Applies the IIR filter to the entire input signal and returns the filtered
			 * signal.
			 *
			 * @param samples	Vector of input signal samples.
			 *
			 * @return Vector of filtered output samples.
			 */
			std::vector<double> processSamples(const std::vector<double> &samples) override;
	
			/**
			 * @brief Adds two IIR filters.
			 * The operator creates a new IIR filter that represents a parallel connection
			 * of the two input filters. Both filters must be compatible, they must have
			 * the same sampling frequency.
			 *
			 * @param filter1	First IIR filter.
			 * @param filter2	Second IIR filter.
			 *
			 * @return Combined IIR filter. 
			 */
			friend IIR operator+ (const IIR& filter1, const IIR& filter2);

			/**
			 * @brief Multiplies two IIR filters.
			 * The operator creates a new IIR filter that represents a cascade connection
			 * of the two input filters. Both filters must be compatible, they must have
			 * the same sampling frequency.
			 *
			 * @param filter1	First IIR filter.
			 * @param filter2	Second IIR filter.
			 *
			 * @return Cascaded IIR filter. 
			 */
			friend IIR operator* (const IIR& filter1, const IIR& filter2);

			/**
			 * @brief Returns the feedback coefficients of the filter.
			 *
			 * @return Vector containing the denominator (feedback) coefficients.
			 */
			std::vector<double> getFeedBackCoeffs() const;

			/**
			 * @brief Returns the feedforward coefficients of the filter.
			 *
			 * @return Vector containing the numerator (feedforward) coefficients.
			 */
			std::vector<double> getFeedForwardCoeffs() const;
	};
}
