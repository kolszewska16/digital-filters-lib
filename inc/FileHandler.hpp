#pragma once
#include <string>
#include <vector>

namespace ko {
	class FileHandler {
		private:
			std::string m_read_filename;
			std::string m_write_filename;
			std::vector<double> m_read_data;
			std::vector<double> m_write_data;

		public:
			FileHandler();
			FileHandler(std::string read_file, std::string write_file) : 
				m_read_filename(read_file), m_write_filename(write_file) {}
			~FileHandler() {}

			void readData();
			void writeData(const std::vector<double> data);

			void setFilenameToRead(const std::string filename);
			void setFilenameToWrite(const std::string filename);
			
			std::string getFilenameToRead();
			std::string getFilenameToWrite();
			std::vector<double> getReadData();
	};
}
