#pragma once

#include <map>
#include <vector>
#include "../thirdparty/jsoncons/json.hpp"
#include "../APIServer.h"
#include "../APIStartup.h"
#include "../CurlHelper.h"
#include "../../include/StringHelper.h"
#include "../../include/JsonconsHelper.h"

#ifdef MOREJEEAPICLIENT_EXPORTS
#define MOREJEEAPICLIENT_API __declspec(dllexport)
#else
#define MOREJEEAPICLIENT_API __declspec(dllimport)
#endif

using namespace std;
using namespace jsoncons;

struct FileListDTO
{
	wstring id;
	wstring name;
};

JSONCONS_MEMBER_TRAITS_DECL(FileListDTO, id, name);

struct MOREJEEAPICLIENT_API FileQueryDTO
{
	int total;
	vector<FileListDTO> data;
};

JSONCONS_MEMBER_TRAITS_DECL(FileQueryDTO, total, data);

namespace MoreJeeAPI
{
	namespace OSS
	{
		/*using namespace std;*/
		/*using namespace jsoncons;*/

		struct FileQuery
		{
			short page;
			short pageSize;
		};





		class MOREJEEAPICLIENT_API FileServer :protected APIServer
		{
		private:
			FileServer();
		public:
			static FileServer& Instance();//获取启动器实例
			void Query(const FileQuery& query, FileQueryDTO & result);
		};
	}
}