#include "Media.h"

void Media::Read(std::ostream& ostream, std::istream& istream) {
	ostream << "Enter name: " << endl;
	istream >> m_name;
	while (1)
	{
		ostream << "Enter size(mb): " << endl;
		istream >> m_size;
		if (istream.fail()) {
			istream.clear();
			istream.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a number." << endl;
			continue;
		}
		break;
	}
}
void Media::Write(std::ostream& ostream) 
{
	ostream << endl << "Name: " << m_name << endl;
	ostream << "Size: " << m_size << endl;
}