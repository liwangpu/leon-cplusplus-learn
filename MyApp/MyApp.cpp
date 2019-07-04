// MyApp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
//#include <curl/curl.h>
//#include "Startup.h"
#include <jsoncons/json.hpp>

using namespace std;
using namespace jsoncons; // for convenience
//using namespace MoreJeeAPI;

//class Animal
//{
//public:
//	string Name;
//	Animal()
//	{
//
//	}
//	Animal(string name) :Name(name)
//	{
//
//	}
//};



class Person
{
public:
	Person() {}
	Person(const string& Name) : _Name(Name) {}
	const string&  Name() const { return _Name; }
private:
	string _Name;
};
JSONCONS_GETTER_CTOR_TRAITS_DECL(Person, Name)


namespace ns {
	class reputon
	{
	public:
		reputon(const std::string& rater,
			const std::string& assertion,
			const std::string& rated,
			double rating)
			: rater_(rater), assertion_(assertion), rated_(rated), rating_(rating)
		{
		}

		const std::string& rater() const { return rater_; }
		const std::string& assertion() const { return assertion_; }
		const std::string& rated() const { return rated_; }
		double rating() const { return rating_; }

	private:
		std::string rater_;
		std::string assertion_;
		std::string rated_;
		double rating_;
	};

	class reputation_object
	{
	public:
		reputation_object() {}
		reputation_object(const std::string& application,
			const std::vector<reputon>& reputons)
			: application_(application),
			reputons_(reputons)
		{}

		const std::string& application() const { return application_; }
		const std::vector<reputon>& reputons() const { return reputons_; }
	private:
		std::string application_;
		std::vector<reputon> reputons_;
	};

} // namespace ns

JSONCONS_GETTER_CTOR_TRAITS_DECL(ns::reputon, rater, assertion, rated, rating)
JSONCONS_GETTER_CTOR_TRAITS_DECL(ns::reputation_object, application, reputons)

int main()
{

	// Decode the string of data into a c++ structure
	//string data = "[]";
	//Person p = decode_json<Person>(data);
	ifstream fs;
	fs.open("persons.json");
	string str;
	ostringstream ostr;
	char s;
	while (fs.get(s))
		ostr << s;
	str = ostr.str();

	//cout << str << endl;

	try
	{
		Person p = decode_json<Person>(str);
	}
	catch (...)
	{
		int a = 1;
		cout << "111" << endl;
	}




	//ns::reputation_object v = decode_json<ns::reputation_object>(str);






	//int sum = 9;

	//void(*fun)(string) = [](string name)
	//{

	//};

	//string url = "https://www.baidu.com";

	//CURL *curl;
	//CURLcode res;
	////curl_global_init(CURL_GLOBAL_ALL);
	//curl = curl_easy_init();
	//if (curl)
	//{


	//	string readBuffer;
	//	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	//	//curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	//	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
	//	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);


	//	res = curl_easy_perform(curl);
	//	/* Check for errors */
	//	if (res != CURLE_OK)
	//		fprintf(stderr, "curl_easy_perform() failed: %s\n",
	//			curl_easy_strerror(res));



	//	curl_easy_cleanup(curl);
	//}


	//int sum = 10;

	//auto fun = [](string name) { cout << "Someone tell me his name is " + name << endl; };

	//Person  *p = new Person("Leon");

	//string name = fun("Uim");

	//cout << name << endl;
	//p->Name

	//p->TellYourName([](string name) {cout << name << endl; });


	////p.TellYourName();

	////p->TellYourName();

	////typedef	int(*add)(int a, int);

	////add fp = MathAdd;
	//////add = MathAdd;

	//////int res = add(1, 3);
	//////int res = (*add)(1, 5);
	////int  res = fp(1, 5);
	////cout << res << endl;


	//string url = "https://www.baidu.com";


	//CURL *curl;
	//CURLcode res;
	////curl_global_init(CURL_GLOBAL_ALL);
	//curl = curl_easy_init();
	//if (curl)
	//{
	//	curl_easy_setopt(curl, CURLOPT_URL,url.c_str());
	//	//curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

	//	res = curl_easy_perform(curl);
	//	/* Check for errors */
	//	if (res != CURLE_OK)
	//		fprintf(stderr, "curl_easy_perform() failed: %s\n",
	//			curl_easy_strerror(res));

	//	curl_easy_cleanup(curl);
	//}


	//char c = 2112;

	//cout << c << endl;


	//wstring str = L"好";

	//for (long i = 0; i < 2000000000; i++)
	//{
	//	str.append(L"1");
	//}

	//cout << str.length() << endl;

	//if (strp)
	//{

	//}




	//auto ins = Startup::GetInstance();
	//ins.Init(url);

	//wcout << ins.GetServer() << endl;
	cout << "finished" << endl;
	int g = getchar();
}

