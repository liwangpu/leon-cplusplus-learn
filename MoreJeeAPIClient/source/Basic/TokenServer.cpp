#include "../../include/Basic/TokenServer.h"
#include "../../include/APIStartup.h"
#include "../../include/CurlHelper.h"
#include "../../include/StringHelper.h"

namespace MoreJeeAPI
{
	namespace Basic
	{



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
		}
	}
}