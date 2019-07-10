#include <vector>
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
		if (_Server != nullptr)
		{
			delete[] _Server;
			_Server = nullptr;
		}
		_Server = new wchar_t[server.size() + 1];
		wcscpy_s(_Server, server.size() + 1, server.c_str());
		setlocale(LC_ALL, "");
	}

	void Startup::_ResetToken(const wstring& token)
	{
		//_Token = token.c_str();
		if (_Token != nullptr)
		{
			delete[] _Token;
			_Token = nullptr;
		}
		_Token = new wchar_t[token.size() + 1];
		wcscpy_s(_Token, token.size() + 1, token.c_str());
	}


}

