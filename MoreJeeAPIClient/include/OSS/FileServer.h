#pragma once
#include "../_APIServer.h"

namespace MoreJeeAPI
{
	namespace OSS
	{
		using namespace std;

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
			wstring url;
			wstring fileExt;
			long size;
			short int fileState;
		};

		struct FileQueryDTO
		{
			int total;
			vector<FileListDTO> data;
		};

		struct FileIdentityDTO
		{
			wstring id;
			wstring name;
			wstring url;
			wstring fileExt;
			long size;
			short int fileState;
		};

		class MOREJEEAPICLIENT_API FileServer :protected _APIServer
		{
		private:
			FileServer();
			FileServer(const FileServer& s);
		public:
			static FileServer& Instance();
			bool Query(const FileQuery& query, FileQueryDTO& result, HttpErrorMessage* error = nullptr);
			bool GetById(const wstring& id, FileIdentityDTO& result, HttpErrorMessage* error = nullptr);
		};
	}
}

