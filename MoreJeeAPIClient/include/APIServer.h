#pragma once
#include <string>

#ifdef MOREJEEAPICLIENT_EXPORTS
#define MOREJEEAPICLIENT_API __declspec(dllexport)
#else
#define MOREJEEAPICLIENT_API __declspec(dllimport)
#endif

namespace MoreJeeAPI
{
	using namespace std;

	class MOREJEEAPICLIENT_API APIServer
	{
	protected:
		wchar_t* _URI = nullptr;
		void _ResetRUI(const wstring& server, const wstring &resource);

	};

}