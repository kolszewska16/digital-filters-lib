#pragma once
#include "IIR.hpp"

namespace ko {
	/**
	 * @brief
	 */
	class LowPassButterworth : public IIR {
		public:
			/**
			 * @brief
			 */
			LowPassButterworth(const int order, const double fc, const double fs);
			
			/**
			 * @brief
			 */			
			void designFilter();
	};
}
