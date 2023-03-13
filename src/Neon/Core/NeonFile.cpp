#include <Neon/Core/NeonFile.h>

namespace Neon {

	NeonFile::NeonFile()
		: fileStream(nullptr)
	{
		fileStream = new fstream();
	}

	NeonFile::~NeonFile()
	{
		if (fileStream != nullptr) {
			delete fileStream;
		}
	}

	void NeonFile::Create(string fileName, bool isBinary)
	{
		if (isBinary) {
			(*fileStream).open(fileName, ios::binary | ios::in | ios::out | ios::trunc);
		}
		else {
			(*fileStream).open(fileName, ios::in | ios::out | ios::trunc);
		}
	}

	bool NeonFile::Open(string fileName, bool isBinary)
	{
		if (isBinary) {
			(*fileStream).open(fileName, ios::binary | ios::in);
		}
		else {
			(*fileStream).open(fileName, ios::in);
		}

		if ((*fileStream).is_open()) {
			(*fileStream).seekg(0, ios::end);
			fileLength = (long)(*fileStream).tellg();
			(*fileStream).seekg(0, ios::beg);

			return true;
		}

		return false;
	}

	void NeonFile::Close()
	{
		(*fileStream).close();
	}

	bool NeonFile::isOpen()
	{
		return (*fileStream).is_open();
	}

	bool NeonFile::GetWord(string& word)
	{
		return !((*fileStream) >> word).eof();
	}

	bool NeonFile::GetLine(string& line)
	{
		return !(getline((*fileStream), line).eof());
	}

	void NeonFile::Read(char* buffer, int length)
	{
		(*fileStream).read(buffer, length);
	}

	void NeonFile::Write(char* buffer, int length)
	{
		(*fileStream).write(buffer, length);
	}

	string NeonFile::ReadAll()
	{
		string data;
		string line;
		while (GetLine(line))
		{
			data += line;
			data += "\n";
		}
		return data;
	}

	fstream& NeonFile::operator << (bool data)
	{
		return (fstream&)((*fileStream) << data);
	}

	fstream& NeonFile::operator << (short data)
	{
		return (fstream&)((*fileStream) << data);
	}

	fstream& NeonFile::operator << (unsigned short data)
	{
		return (fstream&)((*fileStream) << data);
	}

	fstream& NeonFile::operator << (int data)
	{
		return (fstream&)((*fileStream) << data);
	}

	fstream& NeonFile::operator << (unsigned int data)
	{
		return (fstream&)((*fileStream) << data);
	}

	fstream& NeonFile::operator << (long data)
	{
		return (fstream&)((*fileStream) << data);
	}

	fstream& NeonFile::operator << (unsigned long data)
	{
		return (fstream&)((*fileStream) << data);
	}

	fstream& NeonFile::operator << (float data)
	{
		return (fstream&)((*fileStream) << data);
	}

	fstream& NeonFile::operator << (double data)
	{
		return (fstream&)((*fileStream) << data);
	}

	fstream& NeonFile::operator << (string& data)
	{
		return (fstream&)((*fileStream) << data);
	}

	fstream& NeonFile::operator << (const string& data)
	{
		return (fstream&)((*fileStream) << data);
	}

	fstream& NeonFile::operator << (char* data)
	{
		return (fstream&)((*fileStream) << data);
	}

	fstream& NeonFile::operator << (const char* data)
	{
		return (fstream&)((*fileStream) << data);
	}

	//

	fstream& NeonFile::operator >> (bool& data)
	{
		return (fstream&)((*fileStream) >> data);
	}

	fstream& NeonFile::operator >> (short& data)
	{
		return (fstream&)((*fileStream) >> data);
	}

	fstream& NeonFile::operator >> (unsigned short& data)
	{
		return (fstream&)((*fileStream) >> data);
	}

	fstream& NeonFile::operator >> (int& data)
	{
		return (fstream&)((*fileStream) >> data);
	}

	fstream& NeonFile::operator >> (unsigned int& data)
	{
		return (fstream&)((*fileStream) >> data);
	}

	fstream& NeonFile::operator >> (long& data)
	{
		return (fstream&)((*fileStream) >> data);
	}

	fstream& NeonFile::operator >> (unsigned long& data)
	{
		return (fstream&)((*fileStream) >> data);
	}

	fstream& NeonFile::operator >> (float& data)
	{
		return (fstream&)((*fileStream) >> data);
	}

	fstream& NeonFile::operator >> (double& data)
	{
		return (fstream&)((*fileStream) >> data);
	}

	fstream& NeonFile::operator >> (string& data)
	{
		return (fstream&)((*fileStream) >> data);
	}

	//fstream& NeonFile::operator >> (char* data)
	//{
	//	return (fstream&)((*fileStream) >> data);
	//}

}
