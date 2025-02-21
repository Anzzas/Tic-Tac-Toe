#include "case.h"

std::ostream& operator<< (std::ostream& out, const Case& c)
{
	out << "[" << c.m_sign << "]";

	return out;
}

bool Case::isEmpty() const { return this->m_sign == ' ' ? true : false; }

void Case::checkCase() { this->m_sign = 'X'; }