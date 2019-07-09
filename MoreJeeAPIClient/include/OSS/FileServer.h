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

		//��ҳ��ѯ����
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
			static FileServer& Instance();//��ȡ������ʵ��
			void Query(const FileQuery& query, FileQueryDTO & result);
		};
	}
}

