#include "FIR.hpp"
#include <stdexcept>

namespace ko {
	FIR::FIR() {
		m_order = 0;
		m_fc = 0.0;
		m_fs = 0.0;
	}

	FIR::FIR(int order, double fc, double fs) : m_order(order), m_fc(fc), m_fs(fs) {
		if(order < 1) {
			throw std::invalid_argument("Filter order must be greater or equal 1");
		}
		if(fc <= 0.0) {
			throw std::invalid_argument("Cut-off frequency must be greater than 0.0");
		}
		if(fs <= 0.0) {
			throw std::invalid_argument("Sampling frequency must be greater than 0.0");
		}
		if(fc > fs / 2) {
			throw std::invalid_argument("Cut-off frequency can not be greater than 0.5 * fs");
		}

		m_b.resize(order + 1);
//		m_b.assign((order + 1), 0.0);
	}

	double FIR::processSample(const double sample) {
		m_input_buff.push_front(sample);

		if(m_input_buff.size() > m_b.size()) {
			m_input_buff.pop_back();
		}

		double output {0.0};
		for(int i = 0; i < m_b.size(); i++) {
			output += m_b[i] * m_input_buff[i];
		}
		
		return output;
	}

	std::vector<double> FIR::processSamples(const std::vector<double> &samples) {
		std::vector<double> output(samples.size());
		for(int i = 0; i < samples.size(); i++) {
			m_input_buff.push_front(samples[i]);

			if(m_input_buff.size() > m_b.size()) {
				m_input_buff.pop_back();
			}

			for(int j = 0; j < m_b.size(); j++) {
				output[i] += m_b[j] * m_input_buff[j];
			}
		}

		return output;
	}

	void FIR::setOrder(int order) {
		if(order < 1) {
			throw std::invalid_argument("Filter order must be greater or equal 1");
		}
		m_order = order;
	}

	void FIR::setCutOffFrequency(double fc) {
		if(fc <= 0.0) {
			throw std::invalid_argument("Cut-off frequency must be greater than 0.0");
		}
		m_fc = fc;
	}

	void FIR::setSamplingFrequency(double fs) {
		if(fs <= 0.0) {
			throw std::invalid_argument("Sampling frequency must be greater than 0.0");
		}
		m_fs = fs;
	}

	int FIR::getOrder() {
		return m_order;
	}

	double FIR::getCutOffFrequency() {
		return m_fc;
	}

	double FIR::getSamplingFrequency() {
		return m_fs;
	}

	std::vector<double> FIR::getImpulseResponse() {
		return m_b;
	}

	FIR operator+ (const FIR& filter1, const FIR& filter2) {
		if((filter1.m_order != filter2.m_order) || (filter1.m_fs != filter2.m_fs)) {
			throw std::invalid_argument("Filters' order and sampling frequency must be the same");
		}

		FIR result(filter1.m_order, filter1.m_fc, filter1.m_fs);

		for(int i = 0; i < filter1.m_b.size(); i++) {
			result.m_b[i] = filter1.m_b[i] + filter2.m_b[i];
		}

		return result;
	}

	FIR operator* (const FIR& filter1, const FIR& filter2) {
		if((filter1.m_order != filter2.m_order) || (filter1.m_fs != filter2.m_fs)) {
			throw std::invalid_argument("Filters' order and sampling frequency must be the same");
		}

		int new_order = filter1.m_order + filter2.m_order;
		FIR result(new_order, filter1.m_fc, filter1.m_fs);

		int size1 = filter1.m_b.size();
		int size2 = filter2.m_b.size();
		for(int i = 0; i < size1; i++) {
			for(int j = 0; j < size2; j++) {
				result.m_b[i + j] += filter1.m_b[i] * filter2.m_b[j];
			}
		}

		return result;
	}
}
