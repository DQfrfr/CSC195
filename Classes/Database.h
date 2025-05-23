#pragma once
#include <vector>
#include <iostream>
#include "Media.h"
using namespace std;

class Database
{
public:
	~Database();
	void Create(eType type);
	void DisplayAll();
	void Display(const std::string& name);
	void Display(eType type);

protected: 
	vector<Media*> m_media;

private:
	void lowerCase(string& str)
	{
		for (auto& c : str)
		{
			c = tolower(c);
		}
	}
};

