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

#include "APIStartup.h"
#include "OSS/FileServer.h"
#include "StringHelper.h"

using namespace std;
using namespace MoreJeeAPI;
using namespace MoreJeeAPI::OSS;
//using namespace jsoncons;


struct MyQuery
{
	short page;
	short pageSize;
	wstring search;

	//stream& operator<< (stream& s)
	//{
	//	s << page << pageSize << search;
	//	return s;
	//}
};

//
//string format(const std::string& format, ...)
//{
//	va_list args;
//	va_start(args, format);
//	size_t len = vsnprintf(NULL, 0, format.c_str(), args);
//	va_end(args);
//	std::vector<char> vec(len + 1);
//	va_start(args, format.c_str());
//	std::vsnprintf(&vec[0], len + 1, format.c_str(), args);
//	va_end(args);
//	return &vec[0];
//}

int main()
{
	wcout.imbue(locale("chs"));
	//MyQuery q;
	//q.page = 1;

	//wstring body = encode_json<MyQuery>(q);
	//string bodystr = wstr2str(body);

	////char buff[512];
	////string key = "apple";
	////sprintf(buff, "search=%s&page=%d&pageSize=%d", key.c_str(), 2, 10);
	////string result = buff;

	//stream s;
	//s << q;
	//wchar_t wbuff[512];
	//wstring wkey = L"apple";
	//swprintf(wbuff, L"search=%s&page=%p&pageSize=%s", wkey.c_str(), 2, 10);

	//wstring url = L"http://192.168.99.100:9503/";
	//Startup & startup = Startup::Instance();
	//startup.Init(url);


	//OSS::FileServer & fileSrv = FileServer::Instance();

	//FileQuery prm{ 1,100 };

	//FileQueryDTO result;
	//fileSrv.Query(prm, result);


	//result.data[0].test();





	//char str[] = "%s => %d";
	//std::cout << format("search=%s", "apples") << endl;



	wstring search = L"小明";

	wostringstream out;

	out << "search=" << search;

	wcout << out.str() << endl;



	int a = 1;
	int g = getchar();

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
	//	std::cout << p.first << ' ' << p.second << '\n';
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

