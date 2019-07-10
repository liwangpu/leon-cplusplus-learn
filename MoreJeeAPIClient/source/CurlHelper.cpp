#include "curl/curl.h"
#include "../include/CurlHelper.h"
#include "../include/StringHelper.h"


namespace MoreJeeAPI
{
	//回调函数  得到响应内容
	int write_data(char* buffer, size_t size, size_t nmemb, void* userp) {
		std::string * str = dynamic_cast<std::string *>((std::string *)userp);
		str->append((char *)buffer, size * nmemb);
		return nmemb;
	}

	void HttpGet(const string& uri, const HttpHeader& header, wstring& response)
	{
		map<string, string> query;
		HttpGet(uri, query, header, response);
	}

	void HttpGet(const string & uri, const map<string, string>& query, const HttpHeader & header, wstring & response)
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
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &_response);

			struct curl_slist *headers = NULL; /* init to NULL is important */

			/* Perform the request, res will get the return code */
			res = curl_easy_perform(curl);
			/* Check for errors */
			if (res != CURLE_OK)
				fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));

			s2ws(_response, response);
			/* always cleanup */
			curl_easy_cleanup(curl);
		}
	}

	void HttpPost(const string & uri, const HttpHeader & header, const string& body, wstring & response)
	{
		CURL *curl;
		CURLcode res;

		/* get a curl handle */
		curl = curl_easy_init();
		if (curl)
		{
			string _response;
			curl_easy_setopt(curl, CURLOPT_URL, uri.c_str());
			/* Now specify the POST data */
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body);

		/*	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &_response);*/

			/* Perform the request, res will get the return code */
			res = curl_easy_perform(curl);
			/* Check for errors */
			if (res != CURLE_OK)
			{
				fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
			}


			/* always cleanup */
			curl_easy_cleanup(curl);
		}
	}
}
