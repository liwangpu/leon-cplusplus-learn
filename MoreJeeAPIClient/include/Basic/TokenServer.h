#pragma once
#include "../APIServer.h"


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
