#pragma once
#include <string>
#include <vector>
namespace MoreJeeAPI
{
	using namespace std;

	wstring s2ws(const string& str);
	string ws2s(const wstring& wstr);
	string appendstr(const string& str1, const string& str2);
	string appendstr(const string& str1, const string& str2, const string& str3);
	string appendstr(const string& str1, const string& str2, const string& str3, const string& str4);
	string appendstr(const string& str1, const string& str2, const string& str3, const string& str4, const string& str5);
	string appendstr(const vector<string>& list);
}
