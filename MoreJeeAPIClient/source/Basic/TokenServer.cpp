#include "../../include/Basic/TokenServer.h"
#include "../thirdparty/jsoncons/json.hpp"
#include "../../include/APIStartup.h"
#include "../../include/CurlHelper.h"
#include "../../include/StringHelper.h"

namespace MoreJeeAPI
{
	namespace Basic
	{
		using namespace jsoncons;


		TokenServer::TokenServer()
		{
		}

		TokenServer & TokenServer::Instance()
		{
			static TokenServer _Instance;
			_Instance._ResetRUI(Startup::Instance().Server(), L"Basic/Tokens");
			return _Instance;
		}

		void TokenServer::RequestToken(const TokenRequestCommand & command, const TokenRequestDTO & result)
		{

			//string s;
			//encode_json(command, s, indenting::indent);

			/*		HttpHeader header;
					wstring respond;
					HttpPost(_sURI(), header, respond);*/
		}
	}
}

//JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::Basic::TokenRequestCommand, username, password);