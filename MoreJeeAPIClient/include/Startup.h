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
	*	API����������
	*/
	class MOREJEEAPISERVER_API Startup
	{
	private:
		wstring	_Server;//������API��ַ
	public:
		static Startup& GetInstance()
		{
			static Startup _Instance;
			return _Instance;
		}
		/*
		*��ʼ��������
		*/
		void Init(wstring server) { _Server = server; }
		wstring GetServer() { return _Server; }

	};

}

