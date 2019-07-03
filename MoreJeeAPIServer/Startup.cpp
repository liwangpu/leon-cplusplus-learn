#include "stdafx.h"
#include "Startup.h"





namespace MoreJeeAPI
{

	Startup::Startup()
	{
	}
	Startup* Startup::GetInstance()
	{
		return _Instance;
	}

	void Startup::Init(string server)
	{
		GetInstance()->_Server = server;
	}

	string Startup::GetServer()
	{
		return string();
	}


}

