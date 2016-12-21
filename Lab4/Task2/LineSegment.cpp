#include "stdafx.h"
#include "LineSegment.h"


CLineSegment::CLineSegment::CLineSegment(Point const& startPoint, Point const& endPoint, std::string const& outlineColor)
	:IShape("Line"),
	m_startPoint(startPoint),
	m_endPoint(endPoint),
	m_outlineColor(outlineColor)
{
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return hypot((m_endPoint.x - m_startPoint.x), (m_endPoint.y - m_startPoint.y));
}

std::string CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

Point const& CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

Point const& CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

std::string CLineSegment::ToString() const
{
	std::string data = 
		"Start Point: (" 
}
CLineSegment::~CLineSegment()
{
}
