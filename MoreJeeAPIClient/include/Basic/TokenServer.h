#pragma once
#include <string>
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
			wstring password;//注意密码是一个md5的值
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
			void RequestToken(const TokenRequestCommand& command, const TokenRequestDTO& result);
		};
	}
}
