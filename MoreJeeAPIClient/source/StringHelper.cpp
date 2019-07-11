#include <codecvt>
#include <sstream>
#include <string>
#include "../include/StringHelper.h"


namespace MoreJeeAPI
{

	wstring s2ws(const string & str)
	{
		return wstring_convert<codecvt_utf8<wchar_t>>().from_bytes(str);
	}

	string ws2s(const wstring & wstr)
	{
		wstring_convert<codecvt_utf8<wchar_t>> converterX;
		string s = converterX.to_bytes(wstr);
		return s;
	}

}