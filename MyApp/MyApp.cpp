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
#include <jsoncons/json.hpp>

#include "APIStartup.h"
//#include "OSS/FileServer.h"

using namespace std;
using namespace MoreJeeAPI;
using namespace jsoncons;


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


class Person
{
public:
	Person() : age(0) {}
	Person(const std::string& name, const std::string& surname,
		const std::string& ssn, unsigned int age)
		: name(name), surname(surname), ssn(ssn), age(age) { }

private:
	// Make json_type_traits specializations friends to give accesses to private members
	JSONCONS_TYPE_TRAITS_FRIEND;
	std::string name;
	std::string surname;
	std::string ssn;
	unsigned int age;
};



// Declare the traits. Specify which data members need to be serialized.
JSONCONS_MEMBER_TRAITS_DECL(Person, name, surname, ssn, age)


class MyErrorHandler : public parse_error_handler
{
public:
	~MyErrorHandler() {}

protected:
	virtual bool do_error(std::error_code,
		const ser_context& context) noexcept
	{
		return true;
	}

	virtual void do_fatal_error(std::error_code,
		const ser_context&) noexcept
	{
	}
};

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


int main()
{
	wcout.imbue(locale("chs"));

	//wstring url = L"http://192.168.99.100:9503/";
	//Startup & startup = Startup::Instance();
	//startup.Init(url);


	ifstream fs;
	fs.open("persons.json");

	string str;
	char _c;
	while (fs.get(_c))
		str += _c;
	cout << str << endl;

	Person p;
	mydecode_json<Person>(str, p);



	//MyErrorHandler myhandler;
	//json_decoder<json> decoder;
	//basic_json_reader<char, string_source<char>> reader(str, myhandler);
	//reader.read();
	//auto decodedstr = decoder.get_result();

	//std::string input = R"({"field1":ru})";
	//std::istringstream is(input);

	//json_decoder<Person> decoder;
	//json_reader reader(is, decoder);


	//while (!reader.eof())
	//{
	//	reader.read_next();
	//	if (!reader.eof())
	//	{
	//		json val = decoder.get_result();
	//		std::cout << val << std::endl;
	//	}
	//}

	//std::error_code ec;
	//reader.read(ec);

	//if (!ec)
	//{
	//	json j = decoder.get_result();
	//}
	//else
	//{
	//	std::cerr << ec.message()
	//		<< " at line " << reader.line()
	//		<< " and column " << reader.column() << std::endl;
	//}

	auto person = jsoncons::decode_json<Person>(str);


	//json j = json::parse(str);
	//auto sv = j.as<Person>();



	////wchar_t c = 'a';
	//wchar_t str[3] = { 'a','b','c' };

	//wchar_t* cp = str;

	////for (int i = 0; i < 3; i++)
	////{
	////	cout << cp[i] << endl;
	////}

	//cout << str << endl;


	//wchar_t  arr[] = L"好國的";
	//wchar_t *str = arr;

	//
	//wcout << str << endl;


	//funa();




	//cout << "asdsf" << endl;


	wcout << "finished!" << endl;
	int g = getchar();
}

