#pragma once

class IShape
{
public:
	IShape(std::string const& type);
	virtual double GetArea() const;
	virtual double GetPerimeter() const;
	virtual std::string ToString() const;
	virtual std::string GetOutlineColor() const;
	virtual ~IShape() = default;
private:
	std::string m_type;
};

