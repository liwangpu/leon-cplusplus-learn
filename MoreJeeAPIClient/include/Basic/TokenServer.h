#pragma once
#include "../_APIServer.h"


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
			TokenServer(const TokenServer& s);
		public:
			static TokenServer& Instance();
			bool RequestToken(const TokenRequestCommand& command, TokenRequestDTO& result, HttpErrorMessage* error = nullptr);
		};
	}
}
