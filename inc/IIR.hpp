#pragma once
#include "Filter.hpp"
#include <vector>

namespace ko {
	class IIR : public Filter {
		protected:
			/**
			 * @brief
			 */
			std::vector<double> m_a;
			
			/**
			 * @brief
			 */
			std::vector<double> m_b;
			
			/**
			 * @brief
			 */
			std::vector<double> m_x_history;
			
			/**
			 * @brief
			 */
			std::vector<double> m_y_history;

		public:
			/**
			 * @brief
			 */
			IIR(const int order, const double fc, const double fs);
			
			/**
			 * @brief
			 */
			double processSample(const double sample) override;
			
			/**
			 * @brief
			 */
			std::vector<double> processSamples(const std::vector<double> &samples) override;
	
			/**
			 * @brief
			 */
			friend IIR operator+ (const IIR& filter1, const IIR& filter2);

			/**
			 * @brief
			 */
			friend IIR operator* (const IIR& filter1, const IIR& filter2);

			/**
			 * @brief
			 */
			std::vector<double> getFeedBackCoeffs();

			/**
			 * @brief
			 */
			std::vector<double> getFeedForwardCoeffs();
	};
}
