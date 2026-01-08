#pragma once
#include "IIR.hpp"

namespace ko {
	/**
	 * @brief
	 */
	class HighPassButterworth : public IIR {
		public:
			/**
			 * @brief
			 */
			HighPassButterworth(const int order, const double fc, const double fs);
			
			/**
			 * @brief
			 */
			void designFilter();
	};
}
