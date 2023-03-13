#pragma once

#include <Neon/NeonCommon.h>

namespace Neon {

	class NeonFile
	{
	public:
		NeonFile();
		~NeonFile();

		void Create(string fileName, bool isBinary);
		bool Open(string fileName, bool isBinary);
		void Close();
		bool isOpen();

		bool GetWord(string& word);
		bool GetLine(string& line);

		void Read(char* buffer, int length);
		void Write(char* buffer, int length);

		string ReadAll();

		fstream& operator << (bool data);
		fstream& operator << (short data);
		fstream& operator << (unsigned short data);
		fstream& operator << (int data);
		fstream& operator << (unsigned int data);
		fstream& operator << (long data);
		fstream& operator << (unsigned long data);
		fstream& operator << (float data);
		fstream& operator << (double data);
		fstream& operator << (string& data);
		fstream& operator << (const string& data);
		fstream& operator << (char* data);
		fstream& operator << (const char* data);

		fstream& operator >> (bool& data);
		fstream& operator >> (short& data);
		fstream& operator >> (unsigned short& data);
		fstream& operator >> (int& data);
		fstream& operator >> (unsigned int& data);
		fstream& operator >> (long& data);
		fstream& operator >> (unsigned long& data);
		fstream& operator >> (float& data);
		fstream& operator >> (double& data);
		fstream& operator >> (string& data);
		//fstream& operator >> (char* data);

		inline long GetFileLength() const { return fileLength; }

	private:
		fstream* fileStream;
		string fileName;
		long fileLength;
	};
}
