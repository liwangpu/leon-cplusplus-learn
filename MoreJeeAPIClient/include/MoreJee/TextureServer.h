#pragma once
#include "../APIServer.h"

#ifdef MOREJEEAPICLIENT_EXPORTS
#define MOREJEEAPICLIENT_API __declspec(dllexport)
#else
#define MOREJEEAPICLIENT_API __declspec(dllimport)
#endif

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

		};


		class MOREJEEAPICLIENT_API TextureServer :protected APIServer
		{
		private:
			TextureServer();
		public:
			static TextureServer& Instance();
			bool Query(const TextureQuery& query, TextureQueryDTO& result, HttpErrorMessage* error = nullptr);
		};
	}
}
