#pragma once
#include "../APIServer.h"


namespace MoreJeeAPI
{
	namespace Basic
	{

		struct AccountProfileDTO
		{
			wstring id;
			wstring name;
			wstring organizationId;
		};

		class MOREJEEAPICLIENT_API AccountServer :protected APIServer
		{
		private:
			AccountServer();
			AccountServer(const AccountServer& s);
		public:
			static AccountServer& Instance();
			bool GetProfile(AccountProfileDTO& result, HttpErrorMessage* error = nullptr);
		};

	}
}

