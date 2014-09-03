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

#include "format_it.hpp"

static const char * reason_to_message(fmt::format_error::Reason reason)
{
	switch(reason)
	{
	case fmt::format_error::UnusedArgument:
		return "Not all arguments were used in the format string";
	case fmt::format_error::PercentNotFollowedByNumber:
		return "A percent sign '%' was not followed by a number. If you intended to print a percent sign use two percents %%";
	case fmt::format_error::OpenPercentAtEndOfInput:
		return "A percent sign '%' was used at the end of the sequence without a number following it. If you intended to print a percent sign use two percents %%";
	case fmt::format_error::FormatIndexOutOfRange:
		return "Format index out of range";
	}
	// forgot to handle a case in the switch statement above;
	return "Unknown reason";
}

fmt::format_error::format_error(Reason reason)
	: std::runtime_error(reason_to_message(reason)), _reason(reason)
{
}
