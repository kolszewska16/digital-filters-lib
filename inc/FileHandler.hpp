#pragma once
#include <string>
#include <vector>

namespace ko {
	/**
	 * @brief Input/output data handler.
	 * Class responsible for handling input and output data operations, including reading signal
	 * data from file and saving processed signal.
	 */
	class FileHandler {
		private:
			/**
			 * @brief Stores the path or name of the input file to be read.
			 */
			std::string m_read_filename;
			
			/**
			 * @brief Stores the path or name of the output file where data will be saved.
			 */
			std::string m_write_filename;
			
			/**
			 * @brief Buffer contatining data loaded from the input file.
			 */
			std::vector<double> m_read_data;
			
			/**
			 * @brief Buffer containing data ready to be written to an output file.
			 */
			std::vector<double> m_write_data;

		public:
			/**
			 * @brief Default constructor.
			 * Initializes the FileHandler object with default file paths.
			 */
			FileHandler();

			/**
			 * @brief Parametrized constructor.
			 * Sets the input and output file paths during the object initialization.
			 *
			 * @param read_file	Path to the input file.
			 * @param write_file	Path to the output file.
			 */
			FileHandler(std::string read_file, std::string write_file);
			
			/**
			 * @brief Destructor.
			 * Cleans up resources used by the FileHandler.
			 */
			~FileHandler() {}

			/**
			 * @brief Reads data from the source file.
			 * Opens the file specified in m_read_filename and fill the vector m_read_data
			 * with read data from file.
			 */
			void readData();

			/**
			 * @brief Writes provided data to the destination file.
			 *
			 * @param data	A vector of data to be saved.
			 */
			void writeData(const std::vector<double> &data);

			/**
			 * @brief Sets the filename for read operation.
			 *
			 * @param filename	The path to the source file.
			 */
			void setFilenameToRead(const std::string filename);

			/**
			 * @brief Sets the filename for write operation.
			 *
			 * @param filename	The path to the destination file.
			 */
			void setFilenameToWrite(const std::string filename);
			
			/**
			 * @brief Gets the current input filename.
			 *
			 * @return The path to the source file as a string.
			 */
			std::string getFilenameToRead();

			/**
			 * @brief Gets the current output filename.
			 *
			 * @return The path to the destination file as a string.
			 */
			std::string getFilenameToWrite();

			/**
			 * @brief Provides access to the data loaded from the file.
			 *
			 * @return A vector containing data read during last readData() call.
			 */
			std::vector<double> getReadData();
	};
}
