/*
This is free and unencumbered software released into the public domain.
Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.
In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
For more information, please refer to <http://unlicense.org/>
*/

#include <gtest/gtest.h>

#include "format_it.hpp"

namespace
{
TEST(format_it, format_to_string)
{
	std::string test;
	fmt::make_format_it<char>(std::back_inserter(test)).format("[%0, %1, %2]", "Hello", "World", 5);
	ASSERT_EQ("[Hello, World, 5]", test);
}
TEST(format_it, wchar)
{
	std::wstring test;
	fmt::make_format_it<wchar_t>(std::back_inserter(test)).format(L"%0: %1, %2, %3", 5, L"bar", "baz", 0.7);
	ASSERT_EQ(L"5: bar, baz, 0.7", test);
}
TEST(format_it, utf32)
{
	std::u32string test;
	char bytes[4] = "foo";
	fmt::make_format_it<char32_t>(std::back_inserter(test)).format(U"%0: %1, %2, %3, %4", 5, U"bar", "baz", 0.7, bytes);
	ASSERT_EQ(U"5: bar, baz, 0.7, foo", test);
}
TEST(format_it, percent)
{
	std::string foo;
	fmt::make_format_it<char>(std::back_inserter(foo)).format("%0%%", 10);
	ASSERT_EQ("10%", foo);
}
TEST(format_it, order_independent)
{
	std::string foo;
	fmt::make_format_it<char>(std::back_inserter(foo)).format("%1%0%0%1", "foo", std::string("bar"));
	ASSERT_EQ("barfoofoobar", foo);
}
TEST(format_it, out_of_range)
{
	bool did_throw = false;
	try
	{
		std::string foo;
		fmt::make_format_it<char>(std::back_inserter(foo)).format("%0%1", 1.0f);
	}
	catch(const fmt::format_error & error)
	{
		did_throw = true;
		ASSERT_EQ(fmt::format_error::FormatIndexOutOfRange, error.reason());
	}
	ASSERT_TRUE(did_throw);
}
TEST(format_it, invalid_format_string)
{
	bool did_throw = false;
	const char format[] = "%%%0";
	try
	{
		std::string foo;
		fmt::make_format_it<char>(std::back_inserter(foo)).format(format + 0, format + 3);
	}
	catch(const fmt::format_error & error)
	{
		did_throw = true;
		ASSERT_EQ(fmt::format_error::OpenPercentAtEndOfInput, error.reason());
	}
	ASSERT_TRUE(did_throw);
}
TEST(format_it, print_separator)
{
	std::string print;
	fmt::make_format_it<char>(std::back_inserter(print)).print("Hello","World","!");
	ASSERT_EQ("Hello World !", print);
	std::string print_comma;
	fmt::make_format_it<char>(std::back_inserter(print_comma)).print<','>("Hello","World","!");
	ASSERT_EQ("Hello,World,!", print_comma);
	std::string printpacked;
	fmt::make_format_it<char>(std::back_inserter(printpacked)).printpacked("Hello","World","!");
	ASSERT_EQ("HelloWorld!", printpacked);
	std::string print_separated;
	fmt::make_format_it<char>(std::back_inserter(print_separated)).print_separated(", ", "Hello","World","!");
	ASSERT_EQ("Hello, World, !", print_separated);
}
}

