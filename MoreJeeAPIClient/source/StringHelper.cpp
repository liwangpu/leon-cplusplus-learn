#include <codecvt>
#include <sstream>
#include <string>
#include "../include/StringHelper.h"


namespace MoreJeeAPI
{

	wstring s2ws(const string & str)
	{
		return wstring_convert<codecvt_utf8<wchar_t>>().from_bytes(str);
		wstring_convert<codecvt_utf8<wchar_t>> converterX;
		return converterX.from_bytes(str);
	}

	string ws2s(const wstring & wstr)
	{
		wstring_convert<codecvt_utf8<wchar_t>> converterX;
		string s = converterX.to_bytes(wstr);
		return s;
	}

	//const char* ws2cptr(const wstring & wstr)
	//{
	//	string str;
	//	ws2s(wstr, str);
	//	return str.c_str();
	//}

	//const wchar_t * s2wcptr(const string & str)
	//{
	//	wstring wstr;
	//	s2ws(str, wstr);
	//	return wstr.c_str();
	//}

}