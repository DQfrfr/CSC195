#pragma once
#include "Media.h"

class Video : public Media
{
public:
	void Read(std::ostream& ostream, std::istream& istream) override;
	void Write(std::ostream& ostream) override;
	eType GetType() override { return eType::Video; }

	Video() : Media("", 0, eType::Video) {}
	Video(string name, int size, int duration, int width, int height) : Media(name, size, eType::Video)
	{
		this->m_DurationSec = duration;
		this->m_Width = width;
		this->m_Height = height;
	}

protected:
	int m_DurationSec;
	int m_Width;
	int m_Height;
};

