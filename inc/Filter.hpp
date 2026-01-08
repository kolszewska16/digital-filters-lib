#pragma once
#include <vector>

namespace ko {
	/**
	 * @brief
	 */
	class Filter {
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

		public:
			/**
			 * @brief Default constructor of Filter base class.
			 * Initializes the filter with zero order, cut-off frequency and sampling frequency.
			 */
			Filter();

			/**
			 * @brief Parametrized constructor of Filter base class.
			 * Initializes the filter order, cut-off frequency and sampling frequency.
			 *
			 * @param order	The filter order.
			 * @param fc	Cut-off frequency in Hz.
			 * @param fs	Sampling frequency in Hz.
			 */
			Filter(int order, double fc, double fs);

			/**
			 * @brief Virtual destructor.
			 * Ensures that destructors in derived classes are called correctly during
			 * object deletion.
			 */
			virtual ~Filter() {}

			/**
			 * @brief Processes a single input sample.
			 * This is a pure virtual function. It must be implemented by specific filter types
			 * (e.g., LowPass) to apply the filtering algorithm.
			 *
			 * @param sample	The input value to be processed.
			 *
			 * @return The output filtered value.
			 */
			virtual double processSample(const double sample) = 0;

			/**
			 * @brief Processes a batch of signal samples.
			 * This is a pure virtual function. It must be implemented by specific filter types
			 * (e.g., HighPass) to apply the filtering algorithm.
			 *
			 * @param samples	A refernece to a vector containing the input samples.
			 *
			 * @return A new vector containing the filtered output data samples.
			 */
			virtual std::vector<double> processSamples(const std::vector<double> &samples) = 0;

			/**
			 * @brief Sets a new filter order.
			 *
			 * @param order	The desired filter order.
			 */
			void setOrder(const int order);
			
			/**
			 * @brief Sets a new cut-off frequency.
			 *
			 * @param fc	Cut-off frequency in Hz.
			 */
			void setCutOffFrequency(const double fc);
			
			/**
			 * @brief Sets a new sampling frequency.
			 *
			 * @param fs	Sampling frequency in Hz.
			 */
			void setSamplingFrequency(const double fs);
			
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
			 * @brief Gets the sampling frequency.
			 *
			 * @return Sampling frequency in Hz.
			 */
			double getSamplingFrequency();
	};
}
