
#include <map>
#include "../thirdparty/jsoncons/json.hpp"
#include "../../include/OSS/FileServer.h"
#include "../../include/APIStartup.h"
#include "../../include/CurlHelper.h"
#include "../../include/StringHelper.h"


namespace MoreJeeAPI
{
	namespace OSS
	{
		using namespace jsoncons;

		FileServer::FileServer()
		{
		}

		FileServer & FileServer::Instance()
		{
			static FileServer _Instance;
			_Instance._ResetRUI(Startup::Instance().Server(), L"OSS/Files");
			return _Instance;
		}

		bool FileServer::Query(const FileQuery & query, FileQueryDTO & result, HttpErrorMessage* error)
		{
			map<string, string > q;
			q["page"] = to_string(query.page);
			q["pageSize"] = to_string(query.pageSize);
			q["search"] = ws2s(query.search);


			HttpHeader header;
			wstring respond;
			bool successful = HttpGet(_sURI(), q, header, respond);
			if (successful)
				result = decode_json<FileQueryDTO>(respond);
			return successful;
		}

		bool FileServer::GetById(const wstring & id, FileIdentityDTO & result, HttpErrorMessage* error)
		{
			HttpHeader header;
			wstring respond;
			bool successful = HttpGet(_sURI() + "/" + ws2s(id), header, respond);
			if (successful)
				result = decode_json<FileIdentityDTO>(respond);
			return successful;
		}

	}
}

JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::OSS::FileListDTO, id, name, url, fileExt, size, fileState);
JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::OSS::FileQueryDTO, total, data);
JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::OSS::FileIdentityDTO, id, name, url, fileExt, size, fileState);
