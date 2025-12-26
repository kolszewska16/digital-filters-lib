#pragma once
#include "Window.hpp"

namespace ko {
	class BlackmanWindow : public Window {
		public:
			BlackmanWindow(int size);
			void generateCoeffs() override;
	};
}
