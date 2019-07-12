#pragma once
#include "../APIServer.h"

namespace MoreJeeAPI
{
	namespace MoreJee
	{
		//产品分页查询参数
		struct ProductQuery
		{
			short page;
			short pageSize;
			wstring search;
		};

		//产品分页返回的子参数
		struct ProductListDTO
		{
			wstring id;
			wstring name;
			wstring icon;
			wstring description;
			wstring categoryId;
			wstring categoryName;
			wstring brand;
			wstring unit;
			wstring price;
			wstring partnerPrice;
			wstring purchasePrice;
			float maxPrice;
			float minPrice;
			float maxPartnerPrice;
			float minPartnerPrice;
			float maxPurchasePrice;
			float minPurchasePrice;
		};

		//产品分页返回的总参数
		struct ProductQueryDTO
		{
			int total;
			vector<ProductListDTO> data;
		};

		//产品单个资源请求返回的规格子参数
		struct ProductSpecListDTO
		{
			wstring id;
			wstring name;
			wstring icon;
			wstring description;
			float price;
			float partnerPrice;
			float purchasePrice;
		};

		//产品单个资源请求返回的总参数
		struct ProductIdentityQueryDTO
		{
			wstring id;
			wstring name;
			wstring icon;
			wstring description;
			wstring categoryId;
			wstring categoryName;
			wstring brand;
			wstring unit;
			wstring price;
			wstring partnerPrice;
			wstring purchasePrice;
			float maxPrice;
			float minPrice;
			float maxPartnerPrice;
			float minPartnerPrice;
			float maxPurchasePrice;
			float minPurchasePrice;
			vector<ProductSpecListDTO> specifications;
		};

		//创建产品命令
		struct ProductCreateCommand
		{
			wstring name;
			wstring icon;
			wstring description;
			wstring categoryId;
			wstring brand;
			wstring unit;
		};

		//编辑产品基础信息命令
		struct ProductBasicInfoPatchCommand
		{
			wstring name;
			wstring icon;
			wstring description;
			wstring brand;
			wstring unit;

			vector<HttpPatchData> _GetPatchData()
			{
				vector<HttpPatchData> data;
				HttpPatchData n1{ L"add",L"name",name };
				//HttpPatchData n2{ L"add",L"icon",icon };
				HttpPatchData n3{ L"add",L"description",description };
				HttpPatchData n4{ L"add",L"brand",brand };
				HttpPatchData n5{ L"add",L"unit",unit };
				data.push_back(n1);
				//data.push_back(n2);
				data.push_back(n3);
				data.push_back(n4);
				data.push_back(n5);
				return data;
			}
		};

		class MOREJEEAPICLIENT_API ProductServer :protected APIServer
		{
		private:
			ProductServer();
			ProductServer(const ProductServer& s);
		public:
			static ProductServer& Instance();//获取单实例服务
			bool Query(const ProductQuery& query, ProductQueryDTO& result, HttpErrorMessage* error = nullptr);//分页查询请求
			bool GetById(const wstring& id, ProductIdentityQueryDTO& result, HttpErrorMessage* error = nullptr);//单个资源查询请求
			bool Create(const ProductCreateCommand& command, ProductIdentityQueryDTO& result, HttpErrorMessage* error = nullptr);//创建资源请求
			bool Update(const wstring& id, const vector<HttpPatchData>& command, HttpErrorMessage* error = nullptr);//修改资源请求
			bool Delete(const wstring& id, HttpErrorMessage* error = nullptr);//删除资源请求
		};
	}
}

