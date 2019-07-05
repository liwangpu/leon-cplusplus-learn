#include "stdafx.h"
#include "include/APIStartup.h"

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
		if (_server != nullptr)
		{
			delete[] _server;
			_server = nullptr;
		}
		_server = new wchar_t[server.size() + 1];
		wcscpy_s(_server, server.size() + 1, server.c_str());
	}


}

