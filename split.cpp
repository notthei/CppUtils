#include "split.h"



/// @brief stringを指定した文字で区切り、Array<String>で返す
/// @param str 
/// @param del 
/// @return 
Array<String> Split::split(std::string str, std::string del) {
	int first = 0;
	int last = str.find_first_of(del);
	Array<String> stArray;
	if (str.find(del) == std::wstring::npos) {
		stArray.push_back(Unicode::Widen(str));
		return stArray;
	}
	while (first < str.size()) {
		std::string subStr(str, first, last - first);

		stArray.push_back(Unicode::Widen(subStr));

		first = last + 1;
		last = str.find_first_of(del, first);

		if (last == std::string::npos) {
			last = str.size();
		}
	}
	return stArray;
}
/// @brief wstringを指定した文字で区切り、Array<String>で返す
/// @param str 
/// @param del 
/// @return 
Array<String> Split::split(std::wstring str, std::wstring del) {
	int first = 0;
	int last = str.find_first_of(del);
	Array<String> stArray;
	if (str.find(del) == std::wstring::npos) {
		stArray.push_back(Unicode::FromWstring(str));
		return stArray;
	}
	while (first < str.size()) {
		std::wstring subStr(str, first, last - first);

		stArray.push_back(Unicode::FromWstring(subStr));

		first = last + 1;
		last = str.find_first_of(del, first);

		if (last == std::wstring::npos) {
			last = str.size();
		}
	}
	return stArray;
}
/// @brief stringを指定した文字で区切り、vectorで返す
/// @param str 
/// @param del 
/// @return 
std::vector<std::string> Split::split_v(std::string str, std::string del) {
	std::vector<std::string> vec;
	size_t pos_start = 0, pos_end, delim_len = del.length();
	std::string st;

	while ((pos_end = str.find(del, pos_start)) != std::string::npos) {
		st = str.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		vec.push_back(st);
	}

	vec.push_back(str.substr(pos_start));
	return vec;
}
