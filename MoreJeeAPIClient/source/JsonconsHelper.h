#pragma once
#include <string>
#include <locale>
#include <codecvt>
#include <jsoncons/json.hpp>


namespace MoreJeeAPI
{
	using namespace jsoncons;
	using namespace std;

	template <class T, class CharT, class Json>
	void cusread_from(const Json& j, basic_staj_reader<CharT>& reader, T& val)
	{
		error_code ec;
		read_from(j, reader, val, ec);
		if (ec)
		{
			//throw ser_error(ec, reader.context().line(), reader.context().column());
		}
	}

	template <class T, class CharT>
	void cusdecode_json(const basic_string<CharT>& s, T& objOut,
		const basic_json_decode_options<CharT>& options = basic_json_options<CharT>::default_options())
	{
		basic_json_pull_reader<CharT> reader(s, options);
		cusread_from(basic_json<CharT>(), reader, objOut);
	}

	wstring s2ws(const string& str);

	string ws2s(const wstring& wstr);

}