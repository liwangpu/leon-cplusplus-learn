#include "curl/curl.h"
#include "../thirdparty/jsoncons/json.hpp"
#include "../include/CurlHelper.h"
#include "../include/StringHelper.h"
#include "../include/APIStartup.h"

namespace MoreJeeAPI
{
	using namespace jsoncons;

	//回调函数  得到响应内容
	int write_data(char* buffer, size_t size, size_t nmemb, void* userp) {
		std::string * str = dynamic_cast<std::string *>((std::string *)userp);
		str->append((char *)buffer, size * nmemb);
		return nmemb;
	}

	bool HttpGet(const string& uri, const HttpHeader& header, wstring& response, HttpErrorMessage* error)
	{
		map<string, string> query;
		return	HttpGet(uri, query, header, response, error);
	}

	bool HttpGet(const string & uri, const map<string, string>& query, const HttpHeader & header, wstring & response, HttpErrorMessage* error)
	{
		//struct curl_slist *headers = NULL; /* init to NULL is important */
		CURL *curl;
		CURLcode res;

		curl = curl_easy_init();
		if (curl)
		{
			string _response;

			if (!query.empty())
			{
				auto nUri = uri + "?";
				for (const auto& kv : query)
				{
					auto val = curl_easy_escape(curl, kv.second.c_str(), kv.second.length());
					nUri += kv.first + "=" + val + "&";
				}

				curl_easy_setopt(curl, CURLOPT_URL, nUri.c_str());
			}
			else
				curl_easy_setopt(curl, CURLOPT_URL, uri.c_str());


			/* example.com is redirected, so we tell libcurl to follow redirection */
			//curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
			struct curl_slist *headers = NULL;
			headers = curl_slist_append(headers, "Accept:application/json");
			wstring _token = Startup::Instance().Token();
			if (!_token.empty())
				headers = curl_slist_append(headers, ws2s((L"Authorization:bearer " + _token)).c_str());


			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &_response);

			/* Check for errors */
			bool bSuccessful = false;
			long response_code = 0;



			/* Perform the request, res will get the return code */
			res = curl_easy_perform(curl);
			curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);//获取http 状态码 

			if (res == CURLE_OK)
			{
				bSuccessful = response_code >= 200 && response_code < 300;
				if (!bSuccessful && error && !_response.empty())
					*error = decode_json<HttpErrorMessage>(s2ws(_response));

				if (bSuccessful)
					response = s2ws(_response);
			}
			else
			{
				if (error)
					error->messages.push_back(s2ws(curl_easy_strerror(res)));
			}

			if (error)
				error->statusCode = response_code;

			/* always cleanup */
			curl_easy_cleanup(curl);
			return bSuccessful;
		}
		return false;
	}

	bool HttpPost(const string & uri, const HttpHeader & header, const string& body, wstring & response, HttpErrorMessage* error)
	{
		CURL *curl;
		CURLcode res;

		/* get a curl handle */
		curl = curl_easy_init();
		if (curl)
		{
			struct curl_slist *headers = NULL;
			headers = curl_slist_append(headers, "Accept:application/json");
			wstring _token = Startup::Instance().Token();
			if (!_token.empty())
				headers = curl_slist_append(headers, ws2s((L"Authorization:bearer " + _token)).c_str());
			if (!header.ContentType.empty())
				headers = curl_slist_append(headers, ("Content-Type:" + header.ContentType + ";charset=utf-8").c_str());

			string _response;


			curl_easy_setopt(curl, CURLOPT_URL, uri.c_str());

			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());

			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &_response);

			/* Perform the request, res will get the return code */
			res = curl_easy_perform(curl);

			/* Check for errors */
			bool bSuccessful = false;
			long response_code = 0;
			curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);//获取http 状态码 


			if (res == CURLE_OK)
			{
				bSuccessful = response_code >= 200 && response_code < 300;
				if (!bSuccessful && error && !_response.empty())
					*error = decode_json<HttpErrorMessage>(s2ws(_response));
				if (bSuccessful)
					response = s2ws(_response);
			}
			else
			{
				if (error)
					error->messages.push_back(s2ws(curl_easy_strerror(res)));
			}

			if (error)
				error->statusCode = response_code;

			curl_easy_cleanup(curl);
			return bSuccessful;
		}
		return false;
	}
}
JSONCONS_MEMBER_TRAITS_DECL(MoreJeeAPI::HttpErrorMessage, statusCode, messages);