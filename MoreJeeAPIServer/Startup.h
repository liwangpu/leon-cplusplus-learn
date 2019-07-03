#pragma once
#include <string>

using namespace std;

#ifdef MOREJEEAPISERVER_EXPORTS
#define MOREJEEAPISERVER_API __declspec(dllexport)
#else
#define MOREJEEAPISERVER_API __declspec(dllimport)
#endif

namespace MoreJeeAPI
{
	/*
	*	API服务启动器
	*/
	class MOREJEEAPISERVER_API Startup
	{
	private:
		wstring	_Server;//服务器API地址
	public:
		static Startup& GetInstance()
		{
			static Startup _Instance;
			return _Instance;
		}
		/*
		*初始化启动器
		*/
		void Init(wstring server) { _Server = server; }
		wstring GetServer() { return _Server; }

	};

}

