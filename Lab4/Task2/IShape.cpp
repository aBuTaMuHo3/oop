#include "stdafx.h"
#include "IShape.h"


IShape::IShape(std::string const& type):m_type(type)
{
}


IShape::~IShape()
{
}

std::string IShape::ToString() const
{
	std::ostringstream strm;
	strm << m_type + ": "
		<< "  S = " << GetArea()
		<< "  P = " << GetPerimeter()
		<< "  ColorOutline = " << GetOutlineColor();
	return strm.str();
}