#pragma once
#include <map>
#include <string>

namespace MoreJeeAPI
{
	using namespace std;

	struct HttpHeader
	{
		string ContentType = "application/json";
	};

	void HttpGet(const string& uri, const HttpHeader& header, wstring& response);
	void HttpGet(const string& uri, const map<string, string>& query, const HttpHeader& header, wstring& response);
	void HttpPost(const string& uri, const HttpHeader& header, const string& body, wstring& response);

}