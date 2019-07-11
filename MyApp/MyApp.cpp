﻿// MyApp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

//#include "../thirdparty/jsoncons/json.hpp"
#include "APIStartup.h"
#include "OSS/FileServer.h"
#include "Basic/TokenServer.h"
#include "Basic/AccountServer.h"
#include "MoreJee/TextureServer.h"
#include "MoreJee/ProductServer.h"

using namespace std;
using namespace MoreJeeAPI;
using namespace MoreJeeAPI::OSS;
using namespace MoreJeeAPI::Basic;
using namespace MoreJeeAPI::MoreJee;

//using namespace jsoncons;



//struct MyCommand
//{
//	wstring username;
//	wstring password;
//};
//
//JSONCONS_MEMBER_TRAITS_DECL(MyCommand, username, password);

int main()
{
	//wcout.imbue(locale("chs"));

	//wstm.imbue(locale("en_US.UTF-8"));

	//wstring url = L"http://192.168.99.100:95031/";
	wstring url = L"http://192.168.99.100:9503/";
	Startup & startup = Startup::Instance();
	startup.Init(url);


	TokenServer tokenSrv = TokenServer::Instance();
	FileServer fileSrv = FileServer::Instance();
	AccountServer accountSrv = AccountServer::Instance();
	TextureServer textureSrv = TextureServer::Instance();
	ProductServer productSrv = ProductServer::Instance();

	{
		////请求Token
		TokenRequestCommand cmd;
		cmd.username = L"taobao1@tao.com";
		cmd.password = L"e10adc3949ba59abbe56e057f20f883e";
		TokenRequestDTO dto;
		HttpErrorMessage err;
		tokenSrv.RequestToken(cmd, dto, &err);
	}


	{
		////获取用户个人信息
		AccountProfileDTO dto;
		HttpErrorMessage err;
		accountSrv.GetProfile(dto, &err);
	}

	//{
	//	////获取文件列表
	//	FileQuery q{ 1,300 };
	//	FileQueryDTO dto;
	//	HttpErrorMessage err;
	//	fileSrv.Query(q, dto, &err);
	//}

	//{
	//	////获取单个文件
	//	FileIdentityDTO dto;
	//	HttpErrorMessage err;
	//	fileSrv.GetById(L"9911d914f43a682f1aa16c2efc1ad0b4", dto, &err);
	//}


	//{
	//	////获取贴图列表
	//	TextureQuery q{ 1,300 };
	//	TextureQueryDTO dto;
	//	HttpErrorMessage err;
	//	textureSrv.Query(q, dto, &err);
	//}

	//{
	//	////获取单个贴图信息
	//	TextureIdentityQueryDTO dto;
	//	HttpErrorMessage err;
	//	textureSrv.GetById(L"PNfmzjo3pgA8czB", dto, &err);
	//}


	{
		////获取产品列表
		ProductQuery q{ 1,300 };
		ProductQueryDTO dto;
		HttpErrorMessage err;
		productSrv.Query(q, dto, &err);
	}











	int a = 1;
	int g = getchar();

}

