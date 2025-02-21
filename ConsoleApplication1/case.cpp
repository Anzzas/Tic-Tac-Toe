#include "case.h"

std::ostream& operator<< (std::ostream& out, const Case& c)
{
	out << "[" << c.m_sign << "]";

	return out;
}