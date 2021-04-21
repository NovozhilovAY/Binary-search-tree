#pragma once
#include<string>
#include<vector>
#include <algorithm>
#include <locale>
#include <sstream>
#include <iostream>

class StringToVectorOfWordsConvertor
{
	std::vector<char> alphabet;
public:
	StringToVectorOfWordsConvertor();
	std::vector<std::string> convert(std::string str);
private:
	std::vector<std::string> split(const std::string& s, char delim);
};