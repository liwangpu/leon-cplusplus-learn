#include "../../include/MoreJee/ProductServer.h"
#include "../thirdparty/jsoncons/json.hpp"
#include "../../include/APIStartup.h"
#include "../../self/CurlHelper.h"
#include "../../self/StringHelper.h"


namespace MoreJeeAPI
{
	namespace MoreJee
	{
		using namespace jsoncons;

		ProductServer::ProductServer()
		{
		}

		ProductServer::ProductServer(const ProductServer & s)
		{
		}

		ProductServer& ProductServer::Instance()
		{
			static ProductServer _Instance;
			_Instance._ResetRUI(Startup::Instance().Server(), L"MoreJee/Products");
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
		bool ProductServer::GetById(const wstring& id, ProductIdentityQueryDTO & result, HttpErrorMessage * error)
		{
			HttpHeader header;
			wstring respond;
			bool successful = HttpGet(_sURI() + "/" + ws2s(id), header, respond);
			if (successful)
				result = decode_json<ProductIdentityQueryDTO>(respond);
			return successful;
		}
		bool ProductServer::Create(const ProductCreateCommand & command, ProductIdentityQueryDTO & result, HttpErrorMessage * error)
		{
			wstring body;
			encode_json(command, body);

			HttpHeader header;
			wstring response;
			bool successful = HttpPost(_sURI(), header, ws2s(body), response, error);
			if (successful)
				result = decode_json<ProductIdentityQueryDTO>(response);
			return successful;
		}
		bool ProductServer::Update(const wstring & id, const vector<HttpPatchData>& command, HttpErrorMessage * error)
		{
			wstring body;
			encode_json(command, body);

			HttpHeader header;
			header.ContentType = "application/json-patch+json";
			wstring response;
			return HttpPatch(_sURI() + "/" + ws2s(id), header, ws2s(body), response, error);
		}

		bool ProductServer::Delete(const wstring & id, HttpErrorMessage * error)
		{
			HttpHeader header;
			wstring response;
			return HttpDelete(_sURI() + "/" + ws2s(id), header, error);
		}

	}
}
JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::MoreJee::ProductQuery, page, pageSize, search);
JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::MoreJee::ProductListDTO, id, name, icon, description, categoryId, categoryName, brand, unit, price, partnerPrice, purchasePrice, maxPrice, minPrice, maxPartnerPrice, minPartnerPrice, maxPurchasePrice, minPurchasePrice);
JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::MoreJee::ProductQueryDTO, total, data);
JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::MoreJee::ProductIdentityQueryDTO, id, name, icon, description, categoryId, categoryName, brand, unit, price, partnerPrice, purchasePrice, maxPrice, minPrice, maxPartnerPrice, minPartnerPrice, maxPurchasePrice, minPurchasePrice, specifications);
JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::MoreJee::ProductSpecListDTO, id, name, icon, description, price, partnerPrice, purchasePrice);
JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::MoreJee::ProductCreateCommand, name, icon, description, categoryId, brand, unit);

