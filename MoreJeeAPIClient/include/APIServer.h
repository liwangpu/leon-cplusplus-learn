#pragma once
#include <string>
#include <vector>

namespace MoreJeeAPI
{
	using namespace std;

	struct HttpErrorMessage
	{
		short statusCode = 0;
		vector<wstring> messages;
	};

	class APIServer
	{
	protected:
		wchar_t* _URIwcptr = nullptr;
		void _ResetRUI(const wstring& server, const wstring &resource);
		string _sURI();
	};

}