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
	void checkCase();

private:

	char m_sign{};
};
#endif