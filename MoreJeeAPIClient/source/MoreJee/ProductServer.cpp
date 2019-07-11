#include "../../include/MoreJee/ProductServer.h"
#include "../thirdparty/jsoncons/json.hpp"
#include "../../include/APIStartup.h"
#include "../../include/CurlHelper.h"
#include "../../include/StringHelper.h"


namespace MoreJeeAPI
{
	namespace MoreJee
	{
		using namespace jsoncons;

		ProductServer::ProductServer()
		{
		}

		ProductServer& ProductServer::Instance()
		{
			static ProductServer _Instance;
			_Instance._ResetRUI(Startup::Instance().Server(), L"MoreJee/Textures");
			return _Instance;
		}
		bool ProductServer::Query(const ProductQuery & query, ProductQueryDTO & result, HttpErrorMessage * error)
		{
			map<string, string > q;
			q["page"] = to_string(query.page);
			q["pageSize"] = to_string(query.pageSize);
			q["search"] = ws2s(query.search);


			HttpHeader header;
			wstring respond;
			bool successful = HttpGet(_sURI(), q, header, respond, error);
			if (successful)
				result = decode_json<ProductQueryDTO>(respond);
			return successful;
		}
	}
}
JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::MoreJee::ProductQuery, page, pageSize, search);
JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::MoreJee::ProductListDTO, id, name, icon, description, categoryId, categoryName, brand, unit, price, partnerPrice, purchasePrice, maxPrice, minPrice, maxPartnerPrice, minPartnerPrice, maxPurchasePrice, minPurchasePrice);
JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::MoreJee::ProductQueryDTO, total, data);
