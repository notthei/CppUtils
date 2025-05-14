#pragma once
#include <string>
#include <vector>

class Split
{
public:
	static Array<String> split(std::wstring str, std::wstring del);
	static Array<String> split(std::string str, std::string del);
	static std::vector<std::string> split_v(std::string str, std::string del);
};

