#include "../../include/MoreJee/TextureServer.h"
#include "../thirdparty/jsoncons/json.hpp"
#include "../../include/APIStartup.h"
#include "../../include/CurlHelper.h"
#include "../../include/StringHelper.h"



namespace MoreJeeAPI
{
	namespace MoreJee
	{
		using namespace jsoncons;

		TextureServer::TextureServer()
		{
		}

		TextureServer & TextureServer::Instance()
		{
			static TextureServer _Instance;
			_Instance._ResetRUI(Startup::Instance().Server(), L"MoreJee/Textures");
			return _Instance;
		}

		bool TextureServer::Query(const TextureQuery & query, TextureQueryDTO & result, HttpErrorMessage * error)
		{
			map<string, string > q;
			q["page"] = to_string(query.page);
			q["pageSize"] = to_string(query.pageSize);
			q["search"] = ws2s(query.search);


			HttpHeader header;
			wstring respond;
			bool successful = HttpGet(_sURI(), q, header, respond, error);
			if (successful)
				result = decode_json<TextureQueryDTO>(respond);
			return successful;
		}
		bool TextureServer::GetById(const wstring & id, TextureIdentityQueryDTO & result, HttpErrorMessage * error)
		{   
			HttpHeader header;
			wstring respond;
			bool successful = HttpGet(_sURI() + "/" + ws2s(id), header, respond);
			if (successful)
				result = decode_json<TextureIdentityQueryDTO>(respond);
			return successful;
		}
	}
}
JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::MoreJee::TextureListDTO, id, name);
JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::MoreJee::TextureQueryDTO, total, data);
JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::MoreJee::TextureIdentityQueryDTO, id, name, icon, dependencies);
