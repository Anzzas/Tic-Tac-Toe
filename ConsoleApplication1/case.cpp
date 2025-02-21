#include "case.h"

std::ostream& operator<< (std::ostream& out, const Case& c)
{
	out << "[" << c.m_sign << "]";

	return out;
}

bool Case::isEmpty() const { return this->m_sign == '\0' ? true : false; }

void Case::fillCase(char player) { this->m_sign = player; }

const char& Case::getSign() const { return m_sign; }