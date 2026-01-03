#pragma once
#include <vector>

namespace ko {
	class Window {
		protected:
			/**
			 * @brief Stores the length of the window (number of samples).
			 */
			int m_size;
			
			/*
			 * @brief stores calculated window coefficients
			 */
			std::vector<double> m_coeffs;

		public:
			/**
			 * @brief Default constructor of Window base class.
			 * Initializes the window with zero size and an empty coefficients vector.
			 */
			Window();

			/**
			 * @brief Parametrized constructor of Window base class.
			 * Initializes the window size and resizes the coefficient vector.
			 *
			 * @param size	Length of the window (must be a positive integer).
			 */
			Window(int size) : m_size(size), m_coeffs(size) {}
			
			/**
			 * @brief Virtual destructor of Window base class.
			 * Ensures proper cleanup of derived window classes.
			 */
			virtual ~Window() {}

			/**
			 * @brief Gets the current size of the window.
			 * 
			 * @return The number of samples in the window.
			 */
			int getSize();
			
			/**
			 * @brief Gets the window coefficients.
			 *
			 * @return A vector containing the calculated window coefficients.
			 */
			std::vector<double> getCoeffs();
			
			/**
			 * @brief Pure virtual method to generate window coefficients.
			 * This method must be implemented by derived classes (e.g., HammingWindow)
			 * to calculate specific coefficients based on the window type.
			 */
			virtual void generateCoeffs() = 0;

			/**
			 * @brief Overloaded multiplication operator to apply the window to a signal.
			 * Performs point-by-point multiplication between the window coefficients and
			 * the input signal.
			 *
			 * @param w		The window object to be applied.
			 * @param signal	The input signal vector.
			 *
			 * @return		A new vector containing the windowed signal.
			 */
			friend std::vector<double> operator* (const Window &w, const std::vector<double> &signal);
			
			/**
			 * @brief Overloaded multiplication operator to apply the window to a signal.
			 * This version allows for commutative multiplication (signal * window).
			 *
			 * @param signal	The input signal vector.
			 * @param w		The window object to be applied.
			 *
			 * @return		A new vector containing the windowed signal.
			 */
			friend std::vector<double> operator* (const std::vector<double> &signal, const Window &w);
	};
}
