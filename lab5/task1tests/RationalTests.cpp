// task1tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../task1/Rational.h"

BOOST_AUTO_TEST_CASE(Test_Greatest_Common_Denominator)
{
	BOOST_CHECK_EQUAL(GCD(2, 3), 1u);
	BOOST_CHECK_EQUAL(GCD(3, 2), 1u);
	BOOST_CHECK_EQUAL(GCD(12, 8), 4u);
	BOOST_CHECK_EQUAL(GCD(8, 12), 4u);
	BOOST_CHECK_EQUAL(GCD(0, 2), 2u);
	BOOST_CHECK_EQUAL(GCD(2, 0), 2u);
	BOOST_CHECK_EQUAL(GCD(0, 0), 1u);
}

void VerifyRational(const CRational & r, int expectedNumerator, int expectedDenominator)
{
	BOOST_CHECK_EQUAL(r.GetNumerator(), expectedNumerator);
	BOOST_CHECK_EQUAL(r.GetDenominator(), expectedDenominator);
}

BOOST_AUTO_TEST_SUITE(Rational_number)
	BOOST_AUTO_TEST_CASE(is_0_by_default)
	{
		VerifyRational(CRational(), 0, 1);
	}
	BOOST_AUTO_TEST_CASE(can_be_constructed_from_integer)
	{
		VerifyRational(CRational(10), 10, 1);
		VerifyRational(CRational(-10), -10, 1);
		VerifyRational(CRational(0), 0, 1);
	}
	BOOST_AUTO_TEST_CASE(can_be_constructed_with_numerator_and_denominator)
	{
		VerifyRational(CRational(5, 2), 5, 2);
		VerifyRational(CRational(-5, 2), -5, 2);
		VerifyRational(CRational(5, -2), -5, 2);
		VerifyRational(CRational(-5, -2), 5, 2);
	}
	BOOST_AUTO_TEST_CASE(is_normalized_after_construction)
	{
		VerifyRational(CRational(6, 8), 3, 4);
		VerifyRational(CRational(6, -8), -3, 4);
		VerifyRational(CRational(-6, 8), -3, 4);
		VerifyRational(CRational(-6, -8), 3, 4);
		VerifyRational(CRational(-10, 20), -1, 2);
	}
	BOOST_AUTO_TEST_CASE(cant_have_zero_denominator)
	{
		BOOST_REQUIRE_THROW(CRational(1, 0), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(can_be_converted_to_double)
	{
	    CRational rational(2, 4);
		BOOST_CHECK_CLOSE_FRACTION(rational.ToDouble(), 0.5, DBL_EPSILON);
	}

	BOOST_AUTO_TEST_SUITE(unar_operators)
		BOOST_AUTO_TEST_CASE(unar_plus)
		{
			VerifyRational(+CRational(3, 5), 3, 5);
		}
		BOOST_AUTO_TEST_CASE(unar_minus)
		{
			VerifyRational(-CRational(6, 11), -6, 11);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(binary_operator_plus)
		BOOST_AUTO_TEST_CASE(can_sum_two_rational_numbers)
		{
			VerifyRational(CRational(1, 2) + CRational(1, 6), 2, 3);
		}

		BOOST_AUTO_TEST_CASE(can_sum_rational_number_and_integer)
		{
			VerifyRational(CRational(1, 2) + 9, 19, 2);
		}

		BOOST_AUTO_TEST_CASE(can_sum_integer_and_rational_number)
		{
			VerifyRational(10 + CRational(1, 2), 21, 2);
		}
	BOOST_AUTO_TEST_SUITE_END()
	
	BOOST_AUTO_TEST_SUITE(binary_minus)
		BOOST_AUTO_TEST_CASE(can_substract_two_rational_numbers)
		{
			VerifyRational(CRational(3, 5) - CRational(2, 5), 1, 5);
		}
		BOOST_AUTO_TEST_CASE(can_substract_rational_number_and_integer)
		{
			VerifyRational(CRational(1, 2) - CRational(2), -3, 2);
		}
		BOOST_AUTO_TEST_CASE(can_substract_integer_and_rational_number)
		{
			VerifyRational(CRational(2) - CRational(7, 5), 3, 5);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(operator_plus_equal)
		BOOST_AUTO_TEST_CASE(can_sum_two_rational_numbers)
		{
			VerifyRational(CRational(1, 2) += CRational(1, 6), 2, 3);
		}

		BOOST_AUTO_TEST_CASE(can_sum_rational_number_and_integer)
		{
			VerifyRational(CRational(1, 2) += 9, 19, 2);
		}
	BOOST_AUTO_TEST_SUITE_END()
	
	BOOST_AUTO_TEST_SUITE(operator_minus_equal)
		BOOST_AUTO_TEST_CASE(can_substract_two_rational_numbers)
		{
			VerifyRational(CRational(3, 5) -= CRational(2, 5), 1, 5);
		}
		BOOST_AUTO_TEST_CASE(can_substract_rational_number_and_integer)
		{
			VerifyRational(CRational(1, 2) -= CRational(2), -3, 2);
		}
	BOOST_AUTO_TEST_SUITE_END()
	
	BOOST_AUTO_TEST_SUITE(operator_multiply)
		BOOST_AUTO_TEST_CASE(can_multiply_rational_number_and_integer)
		{
			VerifyRational(CRational(1, 6) * CRational(2), 1, 3);
		}
		BOOST_AUTO_TEST_CASE(can_multiply_two_rational_numbers)
		{
			VerifyRational(CRational(1, 6) * CRational(2, 7), 1, 21);
		}
		BOOST_AUTO_TEST_CASE(can_multiply_integer_and_rational_number)
		{
			VerifyRational(CRational(2) * CRational(1, 4), 1, 2);
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(operator_multiply_equal)
		BOOST_AUTO_TEST_CASE(can_multiply_rational_number_and_integer)
		{
			VerifyRational(CRational(1, 6) *= CRational(2), 1, 3);
		}
		BOOST_AUTO_TEST_CASE(can_multiply_two_rational_numbers)
		{
			VerifyRational(CRational(1, 6) *= CRational(2, 7), 1, 21);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(operator_division)
		BOOST_AUTO_TEST_CASE(can_divide_rational_number_by_integer)
		{
			VerifyRational(CRational(1, 6) / CRational(2), 1, 12);
		}
		BOOST_AUTO_TEST_CASE(can_divide_rational_number_by_rational_number)
		{
			VerifyRational(CRational(1, 6) / CRational(2, 7), 7, 12);
		}
		BOOST_AUTO_TEST_CASE(can_divide_integer_by_rational_number)
		{
			VerifyRational(CRational(2) / CRational(1, 4), 8, 1);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(operator_division_equal)
		BOOST_AUTO_TEST_CASE(can_divide_rational_number_by_integer)
		{
			VerifyRational(CRational(1, 6) /= CRational(2), 1, 12);
		}
		BOOST_AUTO_TEST_CASE(can_divide_rational_number_by_rational_number)
		{
			VerifyRational(CRational(1, 6) /= CRational(2, 7), 7, 12);
		}
		BOOST_AUTO_TEST_CASE(can_divide_integer_by_rational_number)
		{
			VerifyRational(CRational(2) /= CRational(1, 4), 8, 1);
		}
	BOOST_AUTO_TEST_SUITE_END()


	BOOST_AUTO_TEST_SUITE(operator_equal)
		BOOST_AUTO_TEST_CASE(compares_equal)
		{
			BOOST_CHECK(CRational(1, 6) == CRational(1, 6));
			BOOST_CHECK(4 == CRational(4, 1));
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(operator_unequal)
		BOOST_AUTO_TEST_CASE(compares_unequal)
		{
			BOOST_CHECK(CRational(1, 3) != CRational(4, 2));
			BOOST_CHECK(CRational(3, 4) != CRational(3, 8));
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(compare_operators)
		BOOST_AUTO_TEST_CASE(less)
		{
			BOOST_CHECK(CRational(1, 4) < CRational(1, 2));
		}
		BOOST_AUTO_TEST_CASE(less_equal)
		{
			BOOST_CHECK(CRational(1, 4) <= CRational(1, 2));
			BOOST_CHECK(CRational(1, 4) <= CRational(1, 4));
		}
		BOOST_AUTO_TEST_CASE(more)
		{
			BOOST_CHECK(CRational(1, 2) > CRational(1, 3));
		}
		BOOST_AUTO_TEST_CASE(more_equal)
		{
			BOOST_CHECK(CRational(6, 3) >= 2);
			BOOST_CHECK(CRational(2, 3) >= CRational(1, 6));
		}
	BOOST_AUTO_TEST_SUITE_END()


//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//	std::ostream в формате <числитель>/<знаменатель>, 
//	например: 7/15
//////////////////////////////////////////////////////////////////////////

	BOOST_AUTO_TEST_SUITE(output_operator)
		BOOST_AUTO_TEST_CASE(can_write_rational_number_to_ostream)
		{
			boost::test_tools::output_test_stream output;
			output << CRational(4, 7);
			BOOST_CHECK(output.is_equal("4/7"));
		}
	BOOST_AUTO_TEST_SUITE_END()


//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//	std::istream в формате <числитель>/<знаменатель>, 
//	например: 7/15
//////////////////////////////////////////////////////////////////////////

	BOOST_AUTO_TEST_SUITE(input_operator)
		BOOST_AUTO_TEST_CASE(can_read_rational_number_from_istream)
		{
			std::istringstream stream("1/2");
			CRational rational;
			stream >> rational;
			VerifyRational(rational, 1, 2);
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
