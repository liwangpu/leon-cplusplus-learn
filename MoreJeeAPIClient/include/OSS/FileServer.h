#pragma once

#ifdef MOREJEEAPISERVER_EXPORTS
#define MOREJEEAPISERVER_API __declspec(dllexport)
#else
#define MOREJEEAPISERVER_API __declspec(dllimport)
#endif

namespace MoreJeeAPI
{
	namespace OSS
	{
		class MOREJEEAPISERVER_API FileServer
		{
		private:
			FileServer();
		public:
			static 	FileServer & Instance()
			{
				static FileServer _Instance;
				return _Instance;
			}
		};
	}
}