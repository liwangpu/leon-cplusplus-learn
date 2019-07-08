#include "../include/StringHelper.h"


namespace MoreJeeAPI
{
	//wstring s2ws(const string& str)
	//{
	//	using convert_typeX = codecvt_utf8<wchar_t>;
	//	wstring_convert<convert_typeX, wchar_t> converterX;
	//	return converterX.from_bytes(str);
	//}

	//string ws2s(const wstring& wstr)
	//{
	//	using convert_typeX = codecvt_utf8<wchar_t>;
	//	wstring_convert<convert_typeX, wchar_t> converterX;
	//	return converterX.to_bytes(wstr);
	//}

	void s2ws(const string & str, wstring & wstr)
	{
		using convert_typeX = codecvt_utf8<wchar_t>;
		wstring_convert<convert_typeX, wchar_t> converterX;
		wstr = converterX.from_bytes(str);
	}

	void ws2s(const wstring & wstr, string & str)
	{
		using convert_typeX = codecvt_utf8<wchar_t>;
		wstring_convert<convert_typeX, wchar_t> converterX;
		str = converterX.to_bytes(wstr);
	}

	const char* ws2cptr(const wstring & wstr)
	{
		string str;
		ws2s(wstr, str);
		return str.c_str();
	}



	//char * ws2cptr(const wstring & wstr)
	//{
	//	string str = ws2s(wstr);
	//	return str.c_str();
	//}
}