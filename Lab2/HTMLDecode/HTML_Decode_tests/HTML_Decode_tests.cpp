// HTML_Decode_tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\HTML_Decode\htmlDecode.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(HtmlDecode_function)
BOOST_AUTO_TEST_CASE(returns_empty_string_if_input_empty_string)
{
	BOOST_CHECK_EQUAL(HtmlDecode(""), "");
}

BOOST_AUTO_TEST_CASE(does_not_change_invalid_HTML_syntax)
{
	BOOST_CHECK_EQUAL(HtmlDecode("&amp;amp;&amp"), "&amp;&amp");
}

BOOST_AUTO_TEST_CASE(returns_source_string_if_it_does_not_have_HTML_syntax)
{
	string strWithoutHtmlSyntax = "This is the string without HTML syntax";
	BOOST_CHECK_EQUAL(HtmlDecode(strWithoutHtmlSyntax), strWithoutHtmlSyntax);
}

BOOST_AUTO_TEST_CASE(returns_source_string_if_HTML_syntax_is_wrong)
{
	string strWithoutHtmlSyntax = "This &ltis&gt the string without &quotHTML&quot syntax &yen;";
	BOOST_CHECK_EQUAL(HtmlDecode(strWithoutHtmlSyntax), strWithoutHtmlSyntax);
}

BOOST_AUTO_TEST_CASE(replaces_HTML_syntax)
{
	string strWithHtmlSyntax = "This&apos;s the &lt;string&gt; with &quot;HTML&quot; syntax";
	string requiredStr = "This's the <string> with \"HTML\" syntax";
	BOOST_CHECK_EQUAL(HtmlDecode(strWithHtmlSyntax), requiredStr);
}
BOOST_AUTO_TEST_SUITE_END()

