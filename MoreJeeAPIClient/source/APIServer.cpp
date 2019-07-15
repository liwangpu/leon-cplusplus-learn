#include "../include/_APIServer.h"
#include "../thirdparty/jsoncons/json.hpp"
#include "../self/StringHelper.h"

namespace MoreJeeAPI
{
	void APIServer::_ResetRUI(const wstring& server, const wstring& resource)
	{
		static wstring lastServer;
		bool bServerChange = lastServer != server;
		if (bServerChange || _URIwcptr == nullptr)
		{
			lastServer = server;
			wstring str = server + resource;
			if (_URIwcptr != nullptr)
			{
				delete[] _URIwcptr;
				_URIwcptr = nullptr;
			}
			_URIwcptr = new wchar_t[str.size() + 1];
			wcscpy_s(_URIwcptr, str.size() + 1, str.c_str());
		}

	}
	string APIServer::_sURI()
	{
		wstring wstr = _URIwcptr;
		return ws2s(wstr);
	}
}
