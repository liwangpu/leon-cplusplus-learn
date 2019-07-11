#pragma once
#include "../APIServer.h"

namespace MoreJeeAPI
{
	namespace MoreJee
	{
		struct ProductQuery
		{
			short page;
			short pageSize;
			wstring search;
		};

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

		struct ProductQueryDTO
		{
			int total;
			vector<ProductListDTO> data;
		};

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

		struct ProductCreateCommand
		{
			wstring name;
			wstring icon;
			wstring description;
			wstring categoryId;
			wstring brand;
			wstring unit;
		};

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
				HttpPatchData n2{ L"add",L"icon",icon };
				HttpPatchData n3{ L"add",L"description",description };
				HttpPatchData n4{ L"add",L"brand",brand };
				HttpPatchData n5{ L"add",L"unit",unit };
				data.push_back(n1);
				data.push_back(n2);
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
		public:
			static ProductServer& Instance();
			bool Query(const ProductQuery& query, ProductQueryDTO& result, HttpErrorMessage* error = nullptr);
			bool GetById(const wstring& id, ProductIdentityQueryDTO& result, HttpErrorMessage* error = nullptr);
			bool Create(const ProductCreateCommand& command, ProductIdentityQueryDTO& result, HttpErrorMessage* error = nullptr);
			bool Update(const wstring& id, const vector<HttpPatchData>& command, HttpErrorMessage* error = nullptr);
		};
	}
}

