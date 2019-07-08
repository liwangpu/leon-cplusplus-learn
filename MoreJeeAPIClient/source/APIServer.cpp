#include "../include/APIServer.h"

namespace MoreJeeAPI
{

	void APIServer::_ResetRUI(const wstring& server, const wstring& resource)
	{
		static wstring lastServer;
		bool bServerChange = lastServer != server;
		if (bServerChange)
		{
			lastServer = server;
			wstring str = server + resource;
			if (_URI != nullptr)
			{
				delete[] _URI;
				_URI = nullptr;
			}
			_URI = new wchar_t[str.size() + 1];
			wcscpy_s(_URI, str.size() + 1, str.c_str());
		}

	}
}