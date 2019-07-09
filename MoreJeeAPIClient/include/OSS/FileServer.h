#pragma once
#include "../APIServer.h"

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

		//分页查询参数
		struct FileQuery
		{
			short page;
			short pageSize;
			wstring search;
		};

		struct FileListDTO
		{
			wstring id;
			wstring name;
		};

		struct FileQueryDTO
		{
			int total;
			vector<FileListDTO> data;
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

