//#include <string>
#include "curl/curl.h"
#include "../JsonconsHelper.h"
#include "../../include/OSS/FileServer.h"



namespace MoreJeeAPI
{
	namespace OSS
	{
		using namespace std;


		FileServer::FileServer()
		{
		}

		FileServer & FileServer::Instance()
		{
			static FileServer _Instance;
			_Instance._ResetRUI(Startup::Instance().Server(), L"OSS/Files");
			return _Instance;
		}

		void FileServer::Query(const PagingQuery& query, PagingQueryDTO<FileListDTO> & result)
		{

			CURL *curl;
			CURLcode res;

			curl = curl_easy_init();
			if (curl) {
				auto s = ws2s(_URI);
				curl_easy_setopt(curl, CURLOPT_URL, ws2s(_URI).c_str());
				/* example.com is redirected, so we tell libcurl to follow redirection */
				//curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

				/* Perform the request, res will get the return code */
				res = curl_easy_perform(curl);
				/* Check for errors */
				if (res != CURLE_OK)
					fprintf(stderr, "curl_easy_perform() failed: %s\n",
						curl_easy_strerror(res));

				/* always cleanup */
				curl_easy_cleanup(curl);
			}





			FileListDTO d{ 100 };
			result.data.push_back(d);
		}



	}
}