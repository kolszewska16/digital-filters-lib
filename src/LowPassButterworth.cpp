#include "LowPassButterworth.hpp"
#include <vector>
#include <complex>
#include <cmath>
#include <numeric>
#include <assert.h>
#include <algorithm>

namespace ko {
	LowPassButterworth::LowPassButterworth(const int order, const double fc, const double fs)
		: IIR(order, fc, fs) {
			designFilter();
		}

	using Polynomial = std::vector<std::complex<double>>;

	static Polynomial operator* (const Polynomial& p, const Polynomial& q) {
		int n = p.size() + q.size() - 1;
		Polynomial result(n);
		for(int i = 0; i < p.size(); i++) {
			for(int j = 0; j < q.size(); j++) {
				result[i + j] += p[i] * q[j];
			}
		}

		return result;
	}

	static std::vector<std::complex<double>> poly(std::vector<std::complex<double>> roots) {
		Polynomial result {1.0};
		for(auto root : roots) {
			Polynomial factor({-root, 1.0});
			result = result * factor;
		}
		std::reverse(result.begin(), result.end());
	
		return result;
	}

	static std::complex<double> sum(const std::vector<std::complex<double>> &v) {
		return std::accumulate(v.begin(), v.end(), std::complex<double>(0.0, 0.0));
	}

	void LowPassButterworth::designFilter() {
		if(m_fc > m_fs / 2.0) {
			throw std::invalid_argument("Cut-off frequency can not be greater than 0.5 * fs");
		}

		std::vector<std::complex<double>> pa(m_order);
		std::vector<std::complex<double>> p(m_order);
		std::vector<std::complex<double>> q(m_order, -1.0);

		for(int i = 0; i < m_order; i++) {
			int k = i + 1;
			double theta = (2 * k - 1) * M_PI / (2 * m_order);
//			pa[i] = -std::sin(theta) + 1.0i * std::cos(theta);
			pa[i] = std::complex<double>(-std::sin(theta), std::cos(theta));
		}

		double Fc = m_fs / M_PI * std::tan(M_PI * m_fc / m_fs);
		for(int i = 0; i < pa.size(); i++) {
			pa[i] *= 2 * M_PI * Fc;
		}

		for(int i = 0; i < m_order; i++) {
			p[i] = (1.0 + pa[i] / (2 * m_fs)) / (1.0 - pa[i] / (2 * m_fs));
		}

		auto a = poly(p);
		for(int i = 0; i < a.size(); i++) {
			a[i] = a[i].real();
		}

		auto b = poly(q);
		auto K = sum(a) / sum(b);
		for(int i = 0; i < b.size(); i++) {
			b[i] *= K;
		}

		for(auto coeff : a) {
			m_a.push_back(coeff.real());
		}

		for(auto coeff : b) {
			m_b.push_back(coeff.real());
		}
	}
}
