#include "stdafx.h"
#include "..\Lab2\ProcessVector.h"

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}


BOOST_AUTO_TEST_SUITE(ProcessVector_function)

	BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
	{
		vector<double> emptyVector;
		ProcessVector(emptyVector);
		BOOST_CHECK(emptyVector.empty());
	}

	BOOST_AUTO_TEST_CASE(does_not_change_vector_containing_no_negative_numbers)
	{
		vector<double> numbers = { 0, 1, 0 };
		auto copy(numbers); 
		ProcessVector(numbers);
		BOOST_CHECK(numbers == copy);
	}


BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(when_processing_a_vector_with_one_positive_number)

	BOOST_AUTO_TEST_CASE(should_multiply_negative_on_min_and_max_elements)
	{
		vector<double> numbers = { -1, 3.5 };
		ProcessVector(numbers);
		BOOST_CHECK(VectorsAreEqual(numbers, { 3.5, 3.5}));
	}

	BOOST_AUTO_TEST_CASE(change_vector_containing_all_negative_numbers)
	{
		vector<double> numbers = {1, 2, 3, 4, 5};
		ProcessVector(numbers);
		BOOST_CHECK(VectorsAreEqual(numbers, {2, -13, 6, -11, 10 }));
	}

BOOST_AUTO_TEST_SUITE_END()


