#pragma once
#include "../APIServer.h"

#ifdef MOREJEEAPICLIENT_EXPORTS
#define MOREJEEAPICLIENT_API __declspec(dllexport)
#else
#define MOREJEEAPICLIENT_API __declspec(dllimport)
#endif


namespace MoreJeeAPI
{
	namespace Basic
	{
		using namespace std;


		struct TokenRequestCommand
		{
			wstring username;
			wstring password;//ע��������һ��md5��ֵ
		};

		struct TokenRequestDTO
		{
			wstring	token;
			wstring expires;
		};

		class MOREJEEAPICLIENT_API TokenServer :protected APIServer
		{
		private:
			TokenServer();
		public:
			static TokenServer& Instance();
			bool RequestToken(const TokenRequestCommand& command, TokenRequestDTO& result, HttpErrorMessage* error = nullptr);
		};
	}
}
