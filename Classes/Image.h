#pragma once
#include "Media.h"
class Image : public Media
{
public:
	void Read(std::ostream& ostream, std::istream& istream) override;
	void Write(std::ostream& ostream) override;
	eType GetType() override { return eType::Image; }
	Image() : Media("", 0, eType::Image) {}
	Image(string name, int size, int width, int height, string yearTaken) : Media(name, size, eType::Image)
	{
		this->m_width = width;
		this->m_height = height;
		this->m_YearTaken = yearTaken;
	}

protected:
	int m_width;
	int m_height;
	string m_YearTaken;
};

