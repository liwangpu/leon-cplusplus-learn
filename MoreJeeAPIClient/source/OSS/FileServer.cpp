
#include <map>
#include <vector>
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

		void FileServer::Query(const FileQuery & query, FileQueryDTO & result)
		{
			wstring url = wstring(_URI) + L"?" + L"page";

			map<string, string> header;
			wstring respond;
			HttpGet(_URI, header, respond);
			result = decode_json<FileQueryDTO>(respond);
		}

	}
}

JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::OSS::FileListDTO, id, name);
JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::OSS::FileQueryDTO, total, data);