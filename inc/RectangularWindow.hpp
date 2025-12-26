#pragma once
#include "Window.hpp"

namespace ko {
	class RectangularWindow : public Window {
		public:
			RectangularWindow(int size);
			void generateCoeffs() override;
	};
}
