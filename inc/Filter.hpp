#pragma once
#include <vector>

namespace ko {
	class Filter {	
		public:
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
	};
}
