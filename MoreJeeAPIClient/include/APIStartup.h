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
	*	API����������
	*/
	class MOREJEEAPICLIENT_API Startup
	{
	private:
		wchar_t* _server = nullptr;
		wchar_t* _token = nullptr;

		Startup();

	public:
		static  Startup& Instance();//��ȡ������ʵ��
		void Init(const wstring& server);//��ʼ��������
		const wchar_t* Token() { return _token; }
		const wchar_t* Server() { return _server; }

	};

}

