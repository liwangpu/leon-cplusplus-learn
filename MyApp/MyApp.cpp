// MyApp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
//#include <locale>
#include <vector>
#include <map>
#include <vector>
#include <cstdarg>
#include <cstring>


#include <sstream>

//#include <cassert>
//#include <curl/curl.h>
//#include "Startup.h"
//#include <jsoncons/json.hpp>

#include "../thirdparty/jsoncons/json.hpp"
#include "APIStartup.h"
#include "OSS/FileServer.h"
#include "Basic/TokenServer.h"
#include "Basic/AccountServer.h"

using namespace std;
using namespace MoreJeeAPI;
using namespace MoreJeeAPI::OSS;
using namespace MoreJeeAPI::Basic;

using namespace jsoncons;



struct MyCommand
{
	wstring username;
	wstring password;
};

JSONCONS_MEMBER_TRAITS_DECL(MyCommand, username, password);

int main()
{
	//wcout.imbue(locale("chs"));

	//wstm.imbue(locale("en_US.UTF-8"));

	//wstring url = L"http://192.168.99.100:95031/";
	wstring url = L"http://192.168.99.100:9503/";
	Startup & startup = Startup::Instance();
	startup.Init(url);

	
	TokenServer& tokenSrv = TokenServer::Instance();
	AccountServer& accountSrv = AccountServer::Instance();

	TokenRequestCommand cmd;
	cmd.username = L"taobao1@tao.com";
	cmd.password = L"e10adc3949ba59abbe56e057f20f883e";

	TokenRequestDTO tokenDto;
	HttpErrorMessage requestTokenErr;
	tokenSrv.RequestToken(cmd, tokenDto, &requestTokenErr);

	AccountProfileDTO profileDto;
	HttpErrorMessage profileErr;
	accountSrv.GetProfile(profileDto,&profileErr);
	




	int a = 1;
	int g = getchar();


	//OSS::FileServer & fileSrv = FileServer::Instance();

	//FileQuery prm{ 1,3,L"测试" };

	//FileQueryDTO result;
	//fileSrv.Query(prm, result);


	//FileIdentityDTO file;
	//fileSrv.GetById(L"9911d914f43a682f1aa16c2efc1ad0b4", file);


	//int a = 1;
	//int g = getchar();


	//char str[] = "%s => %d";
	//cout << format("search=%s", "apples") << endl;



	//wstring search = L"小明";

	//wostringstream out;

	//out << "search=" << search;

	//wcout << out.str() << endl;



	//int a = 1;
	//int g = getchar();

	//map<string, int> myMsg;

	//myMsg["age"] = 18;
	//myMsg["sum"] = 100;

	//auto a = myMsg.find("age");

	//for (auto it = myMsg.begin(); it != myMsg.end(); it++)
	//{
	//	wcout << it. << endl;
	//}



	//for (auto const& p : myMsg)
	//{
	//	cout << p.first << ' ' << p.second << '\n';
	//}

	//wcout << myMsg.find(1) << endl;






	//wstring server = L"http://192.168.99.100:9503/";

	//wchar_t * _Server1 = nullptr;
	//wchar_t * _Server2 = nullptr;

	//_Server1 = new wchar_t[server.size() + 1];
	//wcscpy_s(_Server1, server.size() + 1, server.c_str());

	//_Server2 = new wchar_t[server.size() + 1];
	//wcscpy_s(_Server2, server.size() + 1, server.c_str());


	//bool aa = *_Server1 == *_Server2;






	//wcout << _Server1== _Server2 << endl;


	//Book book;

	//book.name = "水浒传";
	//book.price = 18;



	//PagingQueryDTO<PagingQuery> res;

	//vector<PagingQuery> list;

	//PagingQuery p1;
	//p1.page = 12;
	//p1.pageSize = 100;

	//list.push_back(p1);


	//wcout << startup.Server() << endl;



	//ifstream fs;
	//fs.open("persons.json");

	//string str;
	//char _c;
	//while (fs.get(_c))
	//	str += _c;
	//cout << str << endl;

	//Person p;
	//mydecode_json<Person>(str, p);





	//wcout << "finished!" << endl;
	/*int g = getchar();*/
}

