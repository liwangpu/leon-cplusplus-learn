// MyApp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <vector>
//#include <cassert>
//#include <curl/curl.h>
//#include "Startup.h"
//#include <jsoncons/json.hpp>

#include "APIStartup.h"
#include "./OSS/FileServer.h"
//#include "OSS/FileServer.h"

using namespace std;
using namespace MoreJeeAPI;
using namespace MoreJeeAPI::OSS;
//using namespace jsoncons;


//class Person
//{
//private:
//	string _Name;
//	JSONCONS_TYPE_TRAITS_FRIEND;
//public:
//	Person() {}
//	Person(const string &name) :_Name(name) {}
//	const string & Name() { return _Name; }
//	// Make json_type_traits specializations friends to give accesses to private members
//
//};
//
//
//JSONCONS_MEMBER_TRAITS_DECL(Person, Name)
//
//
//struct User
//{
//
//};

//
//class Person
//{
//public:
//	Person() : age(0) {}
//	Person(const std::string& name, const std::string& surname,
//		const std::string& ssn, unsigned int age)
//		: name(name), surname(surname), ssn(ssn), age(age) { }
//
//private:
//	// Make json_type_traits specializations friends to give accesses to private members
//	JSONCONS_TYPE_TRAITS_FRIEND;
//	std::string name;
//	std::string surname;
//	std::string ssn;
//	unsigned int age;
//};
//
//
//
//// Declare the traits. Specify which data members need to be serialized.
//JSONCONS_MEMBER_TRAITS_DECL(Person, name, surname, ssn, age)
//
//
//class MyErrorHandler : public parse_error_handler
//{
//public:
//	~MyErrorHandler() {}
//
//protected:
//	virtual bool do_error(std::error_code,
//		const ser_context& context) noexcept
//	{
//		return true;
//	}
//
//	virtual void do_fatal_error(std::error_code,
//		const ser_context&) noexcept
//	{
//	}
//};
//
//template <class T, class CharT, class Json>
//void myread_from(const Json& j, basic_staj_reader<CharT>& reader, T& val)
//{
//	std::error_code ec;
//	read_from(j, reader, val, ec);
//	if (ec)
//	{
//		//throw ser_error(ec, reader.context().line(), reader.context().column());
//	}
//}
//
//template <class T, class CharT>
//void mydecode_json(const std::basic_string<CharT>& s, T& objOut,
//	const basic_json_decode_options<CharT>& options = basic_json_options<CharT>::default_options())
//{
//	basic_json_pull_reader<CharT> reader(s, options);
//	myread_from(basic_json<CharT>(), reader, objOut);
//}
//
//






//
//
//struct PagingQuery
//{
//	int page;
//	int pageSize;
//};
//
//template <class T> struct PagingQueryDTO
//{
//	int _total;
//	int& total = _total;
//	vector<T> data;
//};
//




class Person
{
public:
	int Age;
};



int main()
{
	wcout.imbue(locale("chs"));


	//Person p;
	//Person *pt = &p;


	wstring url = L"http://192.168.99.100:9503/";
	Startup & startup = Startup::Instance();
	startup.Init(url);


	OSS::FileServer & fileSrv = FileServer::Instance();


	PagingQuery prm{ 1,100 };

	PagingQueryDTO<FileListDTO> result;
	fileSrv.Query(prm, result);









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





	wcout << "finished!" << endl;
	int g = getchar();
}

