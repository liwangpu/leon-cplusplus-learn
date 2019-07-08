#pragma once
#include <string>
#include <locale>
#include <codecvt>

namespace MoreJeeAPI
{
	using namespace std;

	void s2ws(const string& str, wstring& wstr);
	void ws2s(const wstring& wstr, string& str);
	const char* ws2cptr(const wstring& wstr);
}
