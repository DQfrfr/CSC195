#include "Image.h"

void Image::Read(std::ostream& ostream, std::istream& istream)
{
	Media::Read(ostream, istream);
	ostream << "Enter image width: " << endl;
	istream >> m_width;
	ostream << "Enter image height: " << endl;
	istream >> m_height;
	ostream << "Enter year taken: " << endl;
	istream >> m_YearTaken;
}

void Image::Write(std::ostream& ostream)
{
	Media::Write(ostream);
	ostream << "Image Size: " << m_width << " x " << m_height << endl;
	ostream << "Year Taken: " << m_YearTaken << endl;
	ostream << endl;
}
