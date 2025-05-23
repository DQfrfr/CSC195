#include "Database.h"
#include "Image.h"
#include "Video.h"

Database::~Database()
{
	for (auto& media : m_media)
	{
		delete media;
	}
}

void Database::Create(eType type)
{
	Media* media = nullptr;

	switch (type)
	{
	case eType::Video:
		media = new Video();
		break;
	case eType::Image:
		media = new Image();
		break;
	}

	(*media).Read(std::cout, std::cin);
	m_media.push_back(media);
}

void Database::DisplayAll()
{
	if (m_media.empty())
	{
		std::cout << "No media found." << std::endl;
		return;
	}
	for (auto& media : m_media)
	{
		media->Write(std::cout);
	}
	std::cout << std::endl;
}

void Database::Display(const std::string& name)
{
	string lowercaseName = name;
	lowerCase(lowercaseName);
	if (m_media.empty())
	{
		std::cout << "No media found." << std::endl;
		return;
	}
	for (auto& media : m_media)
	{
		if (media->GetName() == name);
		{
			media->Write(std::cout);
		}
	}
}

void Database::Display(eType type)
{
	if (m_media.empty())
	{
		std::cout << "No media found." << std::endl;
		return;
	}
	for (auto& media : m_media)
	{
		if (media->GetType() == type);
		{
			media->Write(std::cout);
		}
	}
}
