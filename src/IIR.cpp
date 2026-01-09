#include "IIR.hpp"
#include <stdexcept>

namespace ko {
	IIR::IIR(const int order, const double fc, const double fs) : Filter(order, fc, fs) {
		m_x_history.resize(order + 1);
		m_y_history.resize(order + 1);
	}

	double IIR::processSample(const double sample) {
		int N = m_a.size();
		for(int i = N - 1; i > 0; i--) {
			m_x_history[i] = m_x_history[i - 1];
			m_y_history[i] = m_y_history[i - 1];
		}
		m_x_history[0] = sample;

		double y {0.0};
		for(int i = 0; i < N; i++) {
			y += m_b[i] * m_x_history[i];
		}
		for(int i = 1; i < N; i++) {
			y -= m_a[i] * m_y_history[i];
		}
		m_y_history[0] = y;

		return y;
	}

	std::vector<double> IIR::processSamples(const std::vector<double> &samples) {
		std::vector<double> output(samples.size());
		double y {0.0};
		for(int i = 0; i < samples.size(); i++) {
			y = processSample(samples[i]);
			output[i] = y;
		}

		return output;
	}

	std::vector<double> convolve(const std::vector<double> &v1, const std::vector<double> &v2) {
		int n = v1.size() + v2.size() - 1;
		std::vector<double> result(n, 0.0);

		for(int i = 0; i < v1.size(); i++) {
			for(int j = 0; j < v2.size(); j++) {
				result[i + j] += v1[i] * v2[j];
			}
		}

		return result;
	}

	std::vector<double> add_vectors(const std::vector<double> &v1, const std::vector<double> &v2) {
		int size1 = v1.size();
		int size2 = v2.size();
		int max_size = std::max(size1, size2);

		std::vector<double> result(max_size, 0.0);

		for(int i = 0; i < max_size; i++) {
			if(i < size1) {
				result[i] += v1[i];
			}
			if(i < size2) {
				result[i] += v2[i];
			}
		}

		return result;
	}

	IIR operator+ (const IIR& filter1, const IIR& filter2) {
		if(filter1.m_fs != filter2.m_fs) {
			std::invalid_argument("Filters' sampling frequency must be the same");
		}

		int new_order = filter1.m_order + filter2.m_order;

		IIR result(new_order, filter1.m_fc, filter1.m_fs);
		std::vector<double> b1 = convolve(filter1.m_b, filter2.m_a);
		std::vector<double> b2 = convolve(filter2.m_b, filter1.m_a);

		result.m_a = convolve(filter1.m_a, filter2.m_a);
		result.m_b = add_vectors(b1, b2);

		return result;
	}

	IIR operator* (const IIR& filter1, const IIR& filter2) {
		if(filter1.m_fs != filter2.m_fs) {
			std::invalid_argument("Filters' sampling frequency must be the same");
		}

		int new_order = filter1.m_order + filter2.m_order;

		IIR result(new_order, filter1.m_fc, filter1.m_fs);
		result.m_a = convolve(filter1.m_a, filter2.m_a);
		result.m_b = convolve(filter1.m_b, filter2.m_b);

		return result;
	}

	std::vector<double> IIR::getFeedBackCoeffs() {
		return m_a;
	}

	std::vector<double> IIR::getFeedForwardCoeffs() {
		return m_b;
	}
}
