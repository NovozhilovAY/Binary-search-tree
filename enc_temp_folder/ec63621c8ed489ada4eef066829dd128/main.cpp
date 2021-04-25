#include"StringToVectorOfWordsConvertor.h"
#include"BinarySearchTree.h"
#include <fstream>
int main()
{
	setlocale(LC_ALL, "Russian");

	BinarySearchTree<std::string> bt;
	StringToVectorOfWordsConvertor conv;

	/*std::string tmp;
	std::ifstream file("input.txt");
	
	while (getline(file, tmp))
	{
		std::vector<std::string> v = conv.convert(tmp);
		bt.Add(v);
	}
	std::cout << "aнна - " << bt.find("анна")<<std::endl;
	std::cout << "офицер - " << bt.find("офицер");
	std::cout << "я - "<< bt.find("я");
	return 0;*/

	BinarySearchTree<std::string> t;
	t.Add("5");
	t.Add("3");
	t.Add("8");
	t.Add("2");
	t.Add("4");
	t.Add("7");
	t.Add("6");
	t.Del("5");
	t.Del("2");
	t.Del("7");
	t.Print();
}