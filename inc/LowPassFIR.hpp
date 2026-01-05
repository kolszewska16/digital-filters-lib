#pragma once
#include "FIR.hpp"
#include "Window.hpp"
#include <vector>

namespace ko {
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
			LowPassFIR(int order, double fc, double fs, ko::Window &window);

			/**
                         * @brief Calculates the FIR filter coefficients for a high-pass response.
                         * Uses the specified parameters to design the filter impulse response.
                         *
                         * @param window
                         *
                         * @return A vector containing the designed b-coefficients.
                         */
			void designFilter(ko::Window &window);
	};
}
