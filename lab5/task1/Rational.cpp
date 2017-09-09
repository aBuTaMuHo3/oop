#include "stdafx.h"
#include "Rational.h"
#include <utility>
#include <stdexcept>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator must not be equal to zero");
	}
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
//////////////////////////////////////////////////////////////////////////

double CRational::ToDouble() const
{
	return static_cast<double> (m_numerator) / (m_denominator);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
//////////////////////////////////////////////////////////////////////////

CRational const CRational::operator +() const
{
	return *this;
}

CRational const CRational::operator -() const
{
	return CRational(-m_numerator, m_denominator);
}



//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный +
//////////////////////////////////////////////////////////////////////////

CRational const operator+(CRational const& first, CRational const& second)
{
	int numerator = first.GetNumerator() * second.GetDenominator() + first.GetDenominator() * second.GetNumerator();
	int denomirator = first.GetDenominator() * second.GetDenominator();
	return CRational(numerator, denomirator);
}


//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
//////////////////////////////////////////////////////////////////////////


CRational const operator-(CRational const& first, CRational const& second)
{
	int numerator = first.GetNumerator() * second.GetDenominator() - first.GetDenominator() * second.GetNumerator();
	int denomirator = first.GetDenominator() * second.GetDenominator();
	return CRational(numerator, denomirator);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
//////////////////////////////////////////////////////////////////////////

CRational &CRational::operator +=(CRational const& first)
{
	*this = *this + first;
	return *this;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
//////////////////////////////////////////////////////////////////////////

CRational &CRational::operator -=(CRational const& first)
{
	*this = *this - first;
	return *this;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
//////////////////////////////////////////////////////////////////////////

CRational const operator *(CRational const& first, CRational const& second)
{
	return CRational((first.GetNumerator() * second.GetNumerator()),
					 (first.GetDenominator() * second.GetDenominator()));
}


//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
//////////////////////////////////////////////////////////////////////////

CRational const operator /(CRational const& first, CRational const& second)
{
	return CRational((first.GetNumerator() * second.GetDenominator()),
		(first.GetDenominator() * second.GetNumerator()));
}


//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
//////////////////////////////////////////////////////////////////////////


CRational &CRational::operator *=(CRational const& first)
{
	*this = *this * first;
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
//////////////////////////////////////////////////////////////////////////

CRational &CRational::operator /=(CRational const& first)
{
	*this = *this / first;
	return *this;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
//////////////////////////////////////////////////////////////////////////

bool const operator ==(CRational const& first, CRational const& second)
{
	return (first.GetNumerator() == second.GetNumerator()) &&
		(first.GetDenominator() == second.GetDenominator());
}

bool const operator !=(CRational const& first, CRational const& second)
{
	return (first.GetNumerator() != second.GetNumerator()) ||
		(first.GetDenominator() != second.GetDenominator());
}
//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
//////////////////////////////////////////////////////////////////////////

bool const operator <(CRational const& first, CRational const& second)
{
	return ((first.GetNumerator() * second.GetDenominator()) < (first.GetDenominator() * second.GetNumerator()));
}



bool const operator >(CRational const& first, CRational const& second)
{
	return ((first.GetNumerator() * second.GetDenominator()) > (first.GetDenominator() * second.GetNumerator()));
}
bool const operator <=(CRational const& first, CRational const& second)
{
	return !(first > second);
}

bool const operator >=(CRational const& first, CRational const& second)
{
	return !(first < second);
}


//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//////////////////////////////////////////////////////////////////////////

std::ostream & operator <<(std::ostream &stream, CRational const& rational)
{
	return(stream << rational.GetNumerator() << '/'
		  << rational.GetDenominator()
		);
	
}



//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//////////////////////////////////////////////////////////////////////////

std::istream & operator >> (std::istream &stream, CRational & rational)
{
	unsigned numerator = 0;
	unsigned denominator = 1;
	if (
		(stream >> numerator) && (stream.get() == '/') &&
		(stream >> denominator)
		)
	{
		rational = CRational(numerator, denominator);
	}
	else
	{
		stream.setstate(std::ios_base::failbit | stream.rdstate());
	}
	return stream;
}