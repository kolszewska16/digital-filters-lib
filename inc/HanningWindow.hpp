#pragma once
#include "Window.hpp"

namespace ko {
	class HanningWindow : public Window {
		public:
			HanningWindow(int size);
			void generateCoeffs() override;
	};
}
