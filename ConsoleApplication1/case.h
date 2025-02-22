#ifndef CASE_H
#define CASE_H
#include <iostream>

class Case
{
public:

	Case() = default;

	Case(char sign)
		: m_sign{ sign }
	{
	}

	friend std::ostream& operator<< (std::ostream& out, const Case& point);
	bool isEmpty() const;
	void fillCase(char player);
	const char& getSign() const;
	bool operator== (const Case& c) const;
	bool operator== (char c) const;
	Case& operator= (const Case& c);

private:

	char m_sign{};
};
#endif