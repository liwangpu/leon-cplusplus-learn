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
		wchar_t* _Server = nullptr;
		wchar_t* _Token = nullptr;
		Startup();

	public:
		static Startup& Instance();//��ȡ������ʵ��
		void Init(const wstring& server);//��ʼ��������
		const wchar_t* Token() { return _Token; }
		const wchar_t* Server() { return _Server; }
		void _ResetToken(const wstring& token);
	};


}

