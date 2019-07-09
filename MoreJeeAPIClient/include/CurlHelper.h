#pragma once
#include <string>
#include <map>
#include "curl/curl.h"
#include "./StringHelper.h"

namespace MoreJeeAPI
{
	using namespace std;

	void HttpGet(const wstring& uri, const map<string, string>& header, wstring& respond);

}