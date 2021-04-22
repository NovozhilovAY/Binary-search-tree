#include<iostream>
#include"StringToVectorOfWordsConvertor.h"
#include"BinarySearchTree.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	StringToVectorOfWordsConvertor conv;
	std::vector<std::string> v = conv.convert("   !+ Õ¿¡Œ–, —ÀŒ¬. —Œ «Õ¿ ¿Ã»=œ–≈œ»Õ¿Õ»ﬂ » œ–Œ¡≈À¿Ã» -—¿— :fsdf DGSG gfsag   df/ ffd fdfwf ‡,a");
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << "\"" << v[i] << "\"" << "\n";
	}
	
	BinarySearchTree<std::string> b;
	b.Add("3");
	b.Add("4");
	b.Add("1");
	b.Add("0");
	b.Add("2");
	b.Print();
	return 0;
}