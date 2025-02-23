#include "case.h"

std::ostream& operator<< (std::ostream& out, const Case& c)
{
	out << "[" << c.m_sign << "]";

	return out;
}

bool Case::isEmpty() const
{
	if (m_sign == 'X' || m_sign == 'O')
		return false;

	return true;
}

void Case::fillCase(char player) { this->m_sign = player; }

const char& Case::getSign() const { return m_sign; }

bool Case::operator== (const Case& c) const { return (this->m_sign == c.getSign()); }

bool Case::operator== (char c) const { return m_sign == c; }

Case& Case::operator= (const Case& c)
{
	this->m_sign = c.getSign();
	return *this;
}

Case* findEmptyCases(Case& a, Case& b, Case& c)
{
	if (a.isEmpty())
		return &a;
	if (b.isEmpty())
		return &b;
	if (c.isEmpty())
		return &c;

	return nullptr;
}