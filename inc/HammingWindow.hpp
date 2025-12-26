#pragma once
#include "Window.hpp"

namespace ko {
	class HammingWindow : public Window {
		public:
			HammingWindow(int size);
			void generateCoeffs() override;
	};
}
