#pragma once
#include <map>
#include <string>

namespace MoreJeeAPI
{
	using namespace std;

	void HttpGet(const wstring& uri, const map<string, string>& header, wstring& respond);

}