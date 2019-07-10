#pragma once
#include <map>
#include <string>
#include "./APIServer.h"

namespace MoreJeeAPI
{
	using namespace std;

	struct HttpHeader
	{
		string ContentType = "application/json";
	};

	void HttpGet(const string& uri, const HttpHeader& header, wstring& response);
	void HttpGet(const string& uri, const map<string, string>& query, const HttpHeader& header, wstring& response);
	bool HttpPost(const string& uri, const HttpHeader& header, const string& body, wstring& response, HttpErrorMessage* error = nullptr);

}