#include <codecvt>
#include <sstream>
#include <string>
#include "../self/StringHelper.h"


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

	string appendstr(const string & str1, const string & str2)
	{
		size_t size = str1.size() + str2.size();
		string str;
		str.reserve(size);
		str += str1;
		str += str2;
		return str;
	}

	string appendstr(const string & str1, const string & str2, const string & str3)
	{
		size_t size = str1.size() + str2.size() + str3.size();
		string str;
		str.reserve(size);
		str += str1;
		str += str2;
		str += str3;
		return str;
	}

	string appendstr(const string & str1, const string & str2, const string & str3, const string & str4)
	{
		size_t size = str1.size() + str2.size() + str3.size() + str4.size();
		string str;
		str.reserve(size);
		str += str1;
		str += str2;
		str += str3;
		str += str4;
		return str;
	}

	string appendstr(const string & str1, const string & str2, const string & str3, const string & str4, const string & str5)
	{
		size_t size = str1.size() + str2.size() + str3.size() + str4.size() + str5.size();
		string str;
		str.reserve(size);
		str += str1;
		str += str2;
		str += str3;
		str += str4;
		str += str5;
		return str;
	}

	string appendstr(const vector<string>& list)
	{
		string str;
		size_t size = 0;
		for (string s : list)
			size += s.size();
		str.reserve(size);
		for (string s : list)
			str += s;
		return str;
	}



}