#include "stdafx.h"
#include "../StringList/StringList.h"
#
struct StringList
{
	CStringList list;
	CStringList baseList;
	std::vector<std::string> expectedStringVector;

	StringList()
	{
		baseList.Append("Sic");
		baseList.Append("Parvis");
		baseList.Append("Magna");
		expectedStringVector.push_back("Sic");
		expectedStringVector.push_back("Parvis");
		expectedStringVector.push_back("Magna");
	}
};

void VerifyStringList(CStringList const & list, std::vector<std::string> const & expectedStrings)
{
	BOOST_CHECK_EQUAL(list.GetSize(), expectedStrings.size());

	size_t expectedStringPos = 0;
	for (auto it = list.cbegin(); it != list.cend(); ++it)
	{
		BOOST_CHECK_EQUAL(*it, expectedStrings[expectedStringPos]);
		expectedStringPos++;
	}
}

BOOST_FIXTURE_TEST_SUITE(String_list, StringList)
	BOOST_AUTO_TEST_CASE(has_default_constructor)
	{
		BOOST_CHECK(list.IsEmpty());
	}

	BOOST_AUTO_TEST_CASE(has_copy_constructor)
	{
		CStringList copyList(baseList);
		BOOST_CHECK_EQUAL(copyList.GetSize(), 3);
		BOOST_CHECK_EQUAL(baseList.GetSize(), 3);
		VerifyStringList(copyList, expectedStringVector);
	}
	
	BOOST_AUTO_TEST_CASE(has_move_constructor)
	{
		auto moveList = std::move(baseList);
		BOOST_CHECK_EQUAL(moveList.GetSize(), 3);
		BOOST_CHECK_EQUAL(moveList.GetFrontElement(), "Sic");
		BOOST_CHECK(baseList.IsEmpty());
		VerifyStringList(baseList, {});
	}

	BOOST_AUTO_TEST_CASE(has_const_iterators)
	{
		CStringList myList;
		for (size_t i = 0; i < expectedStringVector.size(); ++i)
		{
			myList.Append(expectedStringVector[i]);
		}
		size_t counter = 0;
		for (auto it = myList.cbegin(); it != myList.cend(); ++it)
		{
			BOOST_CHECK_EQUAL(*it, expectedStringVector[counter]);
			counter++;
		}
	}

	BOOST_AUTO_TEST_SUITE(by_default)
		BOOST_AUTO_TEST_CASE(is_empty)
		{
			BOOST_CHECK(list.IsEmpty());
			BOOST_CHECK_EQUAL(list.GetSize(), 0);
		}

		BOOST_AUTO_TEST_CASE(all_iterators_point_at_first_node)
		{
			BOOST_CHECK(list.begin() == list.end());
			BOOST_CHECK(list.cbegin() == list.cend());
			BOOST_CHECK(list.rbegin() == list.rend());
			BOOST_CHECK(list.crbegin() == list.crend());
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_CASE(can_erase_element_at_iterator_position)
	{
		CStringList list;
		list.Append("Screaming");
		list.Append("At");
		list.Append("Myself");
		list.Append("Stay");
		list.Erase(list.begin());
		VerifyStringList(list, { "At", "Myself", "Stay" });

		list.Erase(++list.begin());
		VerifyStringList(list, { "At", "Stay" });

		list.Erase(++list.begin());
		VerifyStringList(list, { "At" });

		list.Erase(list.begin());
		VerifyStringList(list, {});
		BOOST_CHECK(list.IsEmpty());
	}
	BOOST_AUTO_TEST_CASE(can_push_back)
	{
		list.Append("Hello");
		BOOST_CHECK_EQUAL(list.GetBackElement(), "Hello");
		list.Append("World");
		BOOST_CHECK_EQUAL(list.GetBackElement(), "World");
	}

	BOOST_AUTO_TEST_CASE(can_push_front)
	{
		list.PushFront("Hello");
		BOOST_CHECK_EQUAL(list.GetFrontElement(), "Hello");
		list.PushFront("World");
		BOOST_CHECK_EQUAL(list.GetFrontElement(), "World");
	}

	BOOST_AUTO_TEST_CASE(can_insert_element_by_iterator)
	{
		auto it = ++baseList.begin();
		baseList.Insert(it, "Dear");
		BOOST_CHECK_EQUAL(*++baseList.begin(), "Dear");

		it = baseList.begin()++;
		baseList.Insert(it, "Morning");
		BOOST_CHECK_EQUAL(*baseList.begin()++, "Morning");

		baseList.Insert(baseList.end(), "Goodbye");
		std::vector<std::string> expectedStrings = { "Morning", "Sic", "Dear", "Parvis", "Magna", "Goodbye" };
		size_t i = 0;
		for (auto str : baseList)
		{
			BOOST_CHECK_EQUAL(str, expectedStrings[i]);
			i++;
		}
	}
	BOOST_AUTO_TEST_SUITE(after_appending_element)
		BOOST_AUTO_TEST_CASE(increase_size)
		{
			list.Append("Sic");
			BOOST_CHECK_EQUAL(list.GetSize(), 1);
			list.Append("Parvis");
			BOOST_CHECK_EQUAL(list.GetSize(), 2);
			list.PushFront("Magna");
			BOOST_CHECK_EQUAL(list.GetSize(), 3);
		}

		BOOST_AUTO_TEST_CASE(can_use_GetBackElement_and_GetFrontElement_methods)
		{
			list.Append("Parvis");
			BOOST_CHECK_EQUAL(list.GetFrontElement(), "Parvis");
			BOOST_CHECK_EQUAL(list.GetBackElement(), "Parvis");
			list.Append("Magna");
			BOOST_CHECK_EQUAL(list.GetFrontElement(), "Parvis");
			BOOST_CHECK_EQUAL(list.GetBackElement(), "Magna");
			list.PushFront("Sic");
			BOOST_CHECK_EQUAL(list.GetFrontElement(), "Sic");
			BOOST_CHECK_EQUAL(list.GetBackElement(), "Magna");
		}

		BOOST_AUTO_TEST_CASE(can_get_access_to_elements_from_range_based_for)
		{
			size_t counter = 0;
			for (auto str : baseList)
			{
				BOOST_CHECK_EQUAL(str, expectedStringVector[counter]);
				counter++;
			}
		}
		BOOST_AUTO_TEST_CASE(can_be_cleared)
		{
			baseList.Clear();
			VerifyStringList(baseList, {});
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()