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

		};

		class MOREJEEAPICLIENT_API ProductServer :protected APIServer
		{
		private:
			ProductServer();
		public:
			static ProductServer& Instance();
			bool Query(const ProductQuery& query, ProductQueryDTO& result, HttpErrorMessage* error = nullptr);
			bool GetById(const wstring& id, ProductIdentityQueryDTO& result, HttpErrorMessage* error = nullptr);
		};
	}
}

