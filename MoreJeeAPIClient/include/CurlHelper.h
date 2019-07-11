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

		//static string PatchContentType;
	};

	//string	HttpHeader::PatchContentType = "application/json-patch+json";

	bool HttpGet(const string& uri, const HttpHeader& header, wstring& response, HttpErrorMessage* error = nullptr);
	bool HttpGet(const string& uri, const map<string, string>& query, const HttpHeader& header, wstring& response, HttpErrorMessage* error = nullptr);
	bool HttpPost(const string& uri, const HttpHeader& header, const string& body, wstring& response, HttpErrorMessage* error = nullptr);
	bool HttpPatch(const string& uri, const HttpHeader& header, const string& body, wstring& response, HttpErrorMessage* error = nullptr);
	bool HttpDelete(const string& uri, const HttpHeader& header, HttpErrorMessage* error = nullptr);

}