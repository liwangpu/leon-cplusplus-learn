// MyApp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
//#include <locale>
#include <vector>
#include <map>
//#include <cassert>
//#include <curl/curl.h>
//#include "Startup.h"
#include <jsoncons/json.hpp>

#include "APIStartup.h"
#include "OSS/FileServer.h"
#include "StringHelper.h"

using namespace std;
using namespace MoreJeeAPI;
using namespace MoreJeeAPI::OSS;
using namespace jsoncons;



template <class T, class CharT, class Json>
void myread_from(const Json& j, basic_staj_reader<CharT>& reader, T& val)
{
	std::error_code ec;
	read_from(j, reader, val, ec);
	if (ec)
	{
		//throw ser_error(ec, reader.context().line(), reader.context().column());
	}
}

template <class T, class CharT>
void mydecode_json(const std::basic_string<CharT>& s, T& objOut,
	const basic_json_decode_options<CharT>& options = basic_json_options<CharT>::default_options())
{
	basic_json_pull_reader<CharT> reader(s, options);
	myread_from(basic_json<CharT>(), reader, objOut);
}



struct User
{
	int total;
};

JSONCONS_MEMBER_TRAITS_DECL(User, total);


struct PagingQuery
{
	int page;
	int pageSize;
	wstring name;

	PagingQuery()
	{

	}

	PagingQuery(int p, int ps, const wstring& n)
	{
		page = p;
		pageSize = ps;
		name = n;

	}
};

JSONCONS_MEMBER_TRAITS_DECL(PagingQuery, page, pageSize, name)

//struct Account
//{
//	Account() {}
//	Account(const string& name, int age) :name(name), age(age)
//	{}
//	string name;
//	int age;
//};
//
//
//template <class T> struct PagingQueryDTO
//{
//	int total;
//	vector<T> data;
//};


//JSONCONS_MEMBER_TRAITS_DECL(PagingQueryDTO<Account>, total, data)

//struct PagingQuery
//{
//	int page;
//	int pageSize;
//	PagingQuery() 
//	{
//	
//	}
//};
//
//
//JSONCONS_MEMBER_TRAITS_DECL(PagingQuery, Page, PageSize)


//template <class T> struct PagingQueryDTO
//{
//	int _total;
//	vector<T> data;
//};







int main()
{
	//wcout.imbue(locale("chs"));

	//wstring wstr = L"你好";
	//string str;

	//ws2s(wstr,str);


	//wstring str = L"{\"total\":1,\"page\":1,\"pageSize\":100,\"name\":\"习总名\"}";

	//PagingQuery q = decode_json<PagingQuery,wchar_t>(str);



	//int g = getchar();




	wstring url = L"http://192.168.99.100:9503/";
	Startup & startup = Startup::Instance();
	startup.Init(url);


	OSS::FileServer & fileSrv = FileServer::Instance();

	FileQuery prm{ 1,100 };

	FileQueryDTO result;
	fileSrv.Query(prm, result);


	//result.data[0].test();


	int a = 1;

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

