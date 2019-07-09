#pragma once
#include <vector>
#include <string>
//#include <jsoncons/json.hpp>

#ifdef MOREJEEAPICLIENT_EXPORTS
#define MOREJEEAPICLIENT_API __declspec(dllexport)
#else
#define MOREJEEAPICLIENT_API __declspec(dllimport)
#endif

namespace MoreJeeAPI
{
	using namespace std;
	//using namespace jsoncons;

	//struct PagingQuery
	//{
	//	int page = 1;
	//	int pageSize = 20;
	//};

	//template <class T> struct PagingQueryDTO
	//{
	//	int total = 0;
	//	//vector<T> data;
	//};


	class MOREJEEAPICLIENT_API APIServer
	{
	protected:
		//wchar_t* _Server = nullptr;
		wchar_t* _URI = nullptr;
		void _ResetRUI(const wstring& server, const wstring &resource);

	};

}