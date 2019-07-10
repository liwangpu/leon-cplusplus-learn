#include "../../include/Basic/AccountServer.h"
#include "../../include/APIStartup.h"
#include "../thirdparty/jsoncons/json.hpp"
#include "../../include/CurlHelper.h"
#include "../../include/StringHelper.h"

namespace MoreJeeAPI
{
	namespace Basic
	{
		using namespace jsoncons;

		AccountServer::AccountServer()
		{
		}
		AccountServer & AccountServer::Instance()
		{
			static AccountServer _Instance;
			_Instance._ResetRUI(Startup::Instance().Server(), L"Basic/Accounts");
			return _Instance;
		}
		bool AccountServer::GetProfile(AccountProfileDTO & result, HttpErrorMessage * error)
		{
			HttpHeader header;
			wstring response;
			bool successful = HttpGet(_sURI()+"/Profile", header, response, error);
			if (successful)
			{
				result = decode_json<AccountProfileDTO>(response);
			}
			return successful;
		}
	}
}
JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::Basic::AccountProfileDTO, id, name, organizationId);