#include "Video.h"

void Video::Read(std::ostream& ostream, std::istream& istream)
{
	Media::Read(ostream, istream);
	ostream << "Enter duration(seconds): " << endl;
	istream >> m_DurationSec;
	ostream << "Enter video width: " << endl;
	istream >> m_Width;
	ostream << "Enter video height: " << endl;
	istream >> m_Height;
}

void Video::Write(std::ostream& ostream)
{
	Media::Write(ostream);
	ostream << "Duration in seconds: " << m_DurationSec << endl;
	ostream << "Video Size: " << m_Width << " x " << m_Height << endl;
	ostream << endl;
}
