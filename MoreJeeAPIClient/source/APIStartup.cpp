#include <vector>
#include "curl/curl.h"
#include "../include/APIStartup.h"

namespace MoreJeeAPI
{
	Startup::Startup()
	{
	}

	Startup & Startup::Instance()
	{
		static Startup _Instance;
		return _Instance;
	}

	void Startup::Init(const wstring& server)
	{
		static bool CurlGlobalIsInit = false;
		if (!CurlGlobalIsInit)
		{
			curl_global_init(CURL_GLOBAL_ALL);
			CurlGlobalIsInit = true;
		}
		if (_Server != nullptr)
		{
			delete[] _Server;
			_Server = nullptr;
		}
		_Server = new wchar_t[server.size() + 1];
		wcscpy_s(_Server, server.size() + 1, server.c_str());
		setlocale(LC_ALL, "");

	}

	const wstring Startup::Version()
	{
		static wstring version = L"1.0.1 " __TIMESTAMP__;
		return version;
	}

	void Startup::_ResetToken(const wstring& token)
	{
		//_Token = token.c_str();
		if (_Token != nullptr)
		{
			delete[] _Token;
			_Token = nullptr;
		}
		size_t size = token.size();
		_Token = new wchar_t[size + 1];
		wcscpy_s(_Token, size + 1, token.c_str());
	}


}

