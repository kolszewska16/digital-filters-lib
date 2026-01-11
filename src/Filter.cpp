#include "Filter.hpp"
#include <stdexcept>

namespace ko {
	Filter::Filter() {
		m_order = 0;
		m_fc = 0.0;
		m_fs = 0.0;
	}

	Filter::Filter(const int order, const double fc, const double fs) : m_order(order), m_fc(fc), m_fs(fs) {
		if(order < 1) {
			throw std::invalid_argument("Filter order must be greater or equal 1");
		}
		if(fc <= 0.0) {
			throw std::invalid_argument("Cut-off frequency must be greater than 0.0");
		}
		if(fs <= 0.0) {
			throw std::invalid_argument("Sampling frequency must be greater than 0.0");
		}
		if(fc > fs / 2.0) {
			throw std::invalid_argument("Cut-off frequency can not be greater than 0.5 * fs");
		}
	}

	void Filter::setOrder(const int order) {
		if(order < 1) {
			throw std::invalid_argument("Filter order must be greater or equal 1");
		}
		m_order = order;
	}

	void Filter::setCutOffFrequency(const double fc) {
		if(fc <= 0.0) {
			throw std::invalid_argument("Cut-off frequency must be greater than 0.0");
		}
		m_fc = fc;
	}

	void Filter::setSamplingFrequency(const double fs) {
		if(fs <= 0.0) {
			throw std::invalid_argument("Sampling frequency must be greater than 0.0");
		}
		m_fs = fs;
	}

	int Filter::getOrder() const {
		return m_order;
	}

	double Filter::getCutOffFrequency() const {
		return m_fc;
	}

	double Filter::getSamplingFrequency() const {
		return m_fs;
	}
}
