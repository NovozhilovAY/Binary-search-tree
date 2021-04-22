#include"StringToVectorOfWordsConvertor.h"
#include"BinarySearchTree.h"
#include <fstream>
int main()
{
	setlocale(LC_ALL, "Russian");

	BinarySearchTree<std::string> bt;
	StringToVectorOfWordsConvertor conv;

	std::string tmp;
	std::ifstream file("input.txt");
	
	while (getline(file, tmp))
	{
		std::vector<std::string> v = conv.convert(tmp);
		bt.Add(v);
	}
	std::cout << "aнна - " << bt.find("анна")<<std::endl;
	std::cout << "офицер - " << bt.find("офицер");
	return 0;
}