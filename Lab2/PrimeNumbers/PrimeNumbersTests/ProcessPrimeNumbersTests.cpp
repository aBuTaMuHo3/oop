#include "stdafx.h"
#include "../PrimeNumbers/ProcessPrimeNumbers.h"
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
BOOST_AUTO_TEST_SUITE(prime_numbers_tests)

BOOST_AUTO_TEST_CASE(Create_set_when_user_upper_bound_is_10)
{
	set<int> setForCheck = {2, 3, 5, 7 };
	BOOST_CHECK(GeneratePrimeNumbersSet(10) == setForCheck);
}

 BOOST_AUTO_TEST_CASE(Create_set_when_user_upper_bound_is_100)
 {
	 set<int> setForCheck = { 2, 3, 5, 7, 11, 13, 17, 19, 23,
		 29, 31, 37, 41, 43, 47, 53, 59,
		 61, 67, 71, 73, 79, 83, 89, 97 };
	 BOOST_CHECK(GeneratePrimeNumbersSet(100) == setForCheck);
 }
 BOOST_AUTO_TEST_CASE(Can_create_set_when_user_upper_bound_is_max)
 {
	 BOOST_CHECK(GeneratePrimeNumbersSet(100000000).size() == 5761455);
 }
 BOOST_AUTO_TEST_SUITE_END()

/*BOOST_AUTO_TEST_SUITE(checking_the_count_of_elements_in_the_set)

BOOST_AUTO_TEST_CASE(upper_bound_is_equal_to_the_maximum_value)
{
	 BOOST_CHECK(GeneratePrimeNumbersSet(100000000).size() == 5761455);
 }
 BOOST_AUTO_TEST_SUITE_END()*/