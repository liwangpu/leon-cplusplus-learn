#pragma once

#include <map>
#include "../APIServer.h"
#include "../APIStartup.h"
#include "../CurlHelper.h"

#ifdef MOREJEEAPICLIENT_EXPORTS
#define MOREJEEAPICLIENT_API __declspec(dllexport)
#else
#define MOREJEEAPICLIENT_API __declspec(dllimport)
#endif

namespace MoreJeeAPI
{
	namespace OSS
	{
		using namespace std;

		struct FileListDTO
		{
			int age;
		};

		struct FileQueryDTO
		{
			int total = 0;
		};

		JSONCONS_MEMBER_TRAITS_DECL(FileQueryDTO, total)

		class MOREJEEAPICLIENT_API FileServer :protected APIServer
		{
		private:
			FileServer();
		public:
			static FileServer& Instance();//获取启动器实例
			void Query(const PagingQuery& query, PagingQueryDTO<FileListDTO> & result);
		};
	}
}