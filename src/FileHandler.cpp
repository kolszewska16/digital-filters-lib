#include "FileHandler.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace ko {
	FileHandler::FileHandler() {
		m_read_filename = "../src/input_data.txt";
		m_write_filename = "../src/output_data.txt";
		m_read_data = {0.0};
		m_write_data = {0.0};
	}

	FileHandler::FileHandler(const std::string read_file, const std::string write_file)
	:m_read_filename(read_file), m_write_filename(write_file) {
		if(read_file.empty() || write_file.empty()) {
			throw std::invalid_argument("Filename can not be empty");
		}
	}

	void FileHandler::readData() {
		std::fstream file;
		file.open(m_read_filename, std::ios::in);
		if(file.good() != true) {
			throw std::runtime_error("File can not be opened");
		}
		std::string line;
		while(!file.eof()) {
			while(std::getline(file, line)) {
				std::stringstream ss_line(line);
				std::string element;
				double num_l {0.0};
				while(ss_line >> num_l) {
					m_read_data.push_back(num_l);
				}

				while(std::getline(file, element, ',')) {
					std::stringstream ss_element(element);
					double num_e {0.0};
					while(ss_element >> num_e) {
						m_read_data.push_back(num_e);
					}
				}
			}
		}
		file.close();
	}

	void FileHandler::writeData(const std::vector<double> &data) {
		std::fstream file;
		file.open(m_write_filename, std::ios::out);
		if(file.good() != true) {
			throw std::runtime_error("File can not be opened");
		}
		for(int i = 0; i < data.size(); i++) {
			file << data[i] << " ";
		}
		file.close();
	}

	void FileHandler::setFilenameToRead(const std::string filename) {
		if(filename.empty()) {
			throw std::invalid_argument("Filename can not be empty");
		}
		m_read_filename = filename;
	}
	
	void FileHandler::setFilenameToWrite(const std::string filename) {
		if(filename.empty()) {
			throw std::invalid_argument("Filename can not be empty");
		}
		m_write_filename = filename;
	}

	std::string FileHandler::getFilenameToRead() {
		return m_read_filename;
	}

	std::string FileHandler::getFilenameToWrite() {
		return m_write_filename;
	}

	std::vector<double> FileHandler::getReadData() {
		return m_read_data;
	}
}
