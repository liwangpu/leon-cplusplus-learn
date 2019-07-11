#pragma once
#include <string>
#include <vector>

#ifdef MOREJEEAPICLIENT_EXPORTS
#define MOREJEEAPICLIENT_API __declspec(dllexport)
#else
#define MOREJEEAPICLIENT_API __declspec(dllimport)
#endif

namespace MoreJeeAPI
{
	using namespace std;

	struct HttpErrorMessage
	{
		long statusCode = 0;
		vector<wstring> messages;
	};


	struct HttpPatchData
	{
		wstring op;
		wstring path;
		wstring value;
	};

	class MOREJEEAPICLIENT_API APIServer
	{
	protected:
		wchar_t* _URIwcptr = nullptr;
		void _ResetRUI(const wstring& server, const wstring &resource);
		string _sURI();
	};

}