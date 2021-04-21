#include "StringToVectorOfWordsConvertor.h"

std::vector<std::string> StringToVectorOfWordsConvertor::convert(std::string str)
{
	std::vector<std::string> result;
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	for (int i = 0; i < str.size(); i++)
	{
		auto it = std::find(alphabet.begin(), alphabet.end(), str[i]);
		if (it == alphabet.end())
		{
			std::replace(str.begin(), str.end(), str[i], ' ');
		}
	}
	result = split(str, ' ');
	return result;
}

StringToVectorOfWordsConvertor::StringToVectorOfWordsConvertor()
{
	for (char i = 'a'; i <= 'z'; i++)
	{
		alphabet.push_back(i);
	}
	for (char i = 'à'; i <= 'ÿ'; i++)
	{
		alphabet.push_back(i);
	}
}


std::vector<std::string> StringToVectorOfWordsConvertor::split(const std::string& s, char delim)
{
	std::vector<std::string> elems;
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		if (item == "")
		{
			continue;
		}
		elems.push_back(item);
	}
	return elems;
}
