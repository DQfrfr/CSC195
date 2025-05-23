#pragma once
#include <iostream>
#include <string>
using namespace std;

enum class eType
{
	Audio = 1,
	Video = 2,
	Image = 3,
};

class Media
{
public:
	virtual void Read(std::ostream& ostream, std::istream& istream);
	virtual void Write(std::ostream& ostream);
	string GetName() { return m_name; }
	virtual eType GetType() = 0;
	Media(string name, int size, eType type)
		:m_name(name), m_size(size), m_type(type) {
	}

protected:
	string m_name;
	int m_size;
	eType m_type;
};