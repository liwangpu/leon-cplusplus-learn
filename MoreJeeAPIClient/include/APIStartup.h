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

	/*
	*	API服务启动器
	*/
	class MOREJEEAPICLIENT_API Startup
	{
	private:
		wchar_t* _Server = nullptr;
		wchar_t* _Token = nullptr;
		Startup();

	public:
		static Startup& Instance();//获取启动器实例
		void Init(const wstring& server);//初始化启动器
		const wstring Token() { return _Token != nullptr ? _Token : L""; }
		const wstring Server() { return _Server != nullptr ? _Server : L""; }
		const wstring Version();
		void _ResetToken(const wstring& token);
	};


}

