#pragma once
#include <string>

using namespace std;

namespace MoreJeeAPI
{
	class Startup
	{
	private:
		static Startup* _Instance;
		string	_Server;
		Startup();
	public:
		static Startup* GetInstance();
		static	void Init(string server);
		string GetServer();

	};
	Startup* Startup::_Instance = new Startup;
}

