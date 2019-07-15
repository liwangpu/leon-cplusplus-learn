#include "../../include/Basic/TokenServer.h"
#include "../thirdparty/jsoncons/json.hpp"
#include "../../include/APIStartup.h"
#include "../../self/CurlHelper.h"
#include "../../self/StringHelper.h"

namespace MoreJeeAPI
{
	namespace Basic
	{
		using namespace jsoncons;


		TokenServer::TokenServer()
		{
		}

		TokenServer::TokenServer(const TokenServer & s)
		{
		}

		TokenServer & TokenServer::Instance()
		{
			static TokenServer _Instance;
			_Instance._ResetRUI(Startup::Instance().Server(), L"Basic/Tokens");
			return _Instance;
		}

		bool TokenServer::RequestToken(const TokenRequestCommand & command, TokenRequestDTO& result, HttpErrorMessage* error)
		{
			wstring body;
			encode_json(command, body);

			HttpHeader header;
			wstring response;
			bool successful = HttpPost(_sURI(), header, ws2s(body), response, error);
			if (successful)
			{
				result = decode_json<TokenRequestDTO>(response);
				Startup::Instance()._ResetToken(result.token);
			}
			return successful;
		}
	}
}

JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::Basic::TokenRequestCommand, username, password);
JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::Basic::TokenRequestDTO, token, expires);