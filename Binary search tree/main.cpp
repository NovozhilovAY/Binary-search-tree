#include<iostream>
#include"StringToVectorOfWordsConvertor.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	StringToVectorOfWordsConvertor conv;
	std::vector<std::string> v = conv.convert("   !+ �����, ����. �� �������=���������� � ��������� -��� :fsdf DGSG gfsag   df/ ffd fdfwf �,a");
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << "\"" << v[i] << "\"" << "\n";
	}
	
	return 0;
}