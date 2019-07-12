#pragma once
#include "../APIServer.h"

namespace MoreJeeAPI
{
	namespace MoreJee
	{
		struct TextureQuery
		{
			short page;
			short pageSize;
			wstring search;
		};

		struct TextureListDTO
		{
			wstring id;
			wstring name;
		};

		struct TextureQueryDTO
		{
			int total;
			vector<TextureListDTO> data;
		};

		struct TextureIdentityQueryDTO
		{
			wstring id;
			wstring name;
			wstring icon;
			wstring dependencies;
		};


		class MOREJEEAPICLIENT_API TextureServer :protected APIServer
		{
		private:
			TextureServer();
			TextureServer(const TextureServer& s);
		public:
			static TextureServer& Instance();
			bool Query(const TextureQuery& query, TextureQueryDTO& result, HttpErrorMessage* error = nullptr);
			bool GetById(const wstring& id, TextureIdentityQueryDTO& result, HttpErrorMessage* error = nullptr);
		};
	}
}
