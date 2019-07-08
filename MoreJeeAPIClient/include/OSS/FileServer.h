#pragma once

#include "../APIServer.h"
#include "../APIStartup.h"

#ifdef MOREJEEAPICLIENT_EXPORTS
#define MOREJEEAPICLIENT_API __declspec(dllexport)
#else
#define MOREJEEAPICLIENT_API __declspec(dllimport)
#endif

namespace MoreJeeAPI
{
	namespace OSS
	{
		struct FileListDTO
		{
			int age;
		};

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