#pragma once
#include "../APIServer.h"

#ifdef MOREJEEAPICLIENT_EXPORTS
#define MOREJEEAPICLIENT_API __declspec(dllexport)
#else
#define MOREJEEAPICLIENT_API __declspec(dllimport)
#endif

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

		class MOREJEEAPICLIENT_API ProductServer :protected APIServer
		{
		private:
			ProductServer();
		public:
			static ProductServer& Instance();
			bool Query(const ProductQuery& query, ProductQueryDTO& result, HttpErrorMessage* error = nullptr);
		};
	}
}

