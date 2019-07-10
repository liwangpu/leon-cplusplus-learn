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
		public:
			static AccountServer& Instance();
			bool GetProfile(AccountProfileDTO& result, HttpErrorMessage* error = nullptr);
		};

	}
}

