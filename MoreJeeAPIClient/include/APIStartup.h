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
		const wchar_t* Token() { return _Token; }
		const wchar_t* Server() { return _Server; }
		void _ResetToken(const wstring& token);
	};


}

