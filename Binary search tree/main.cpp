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

	TreeNode<std::string> tr("5");
	tr.AddNode(&tr, "3");
	tr.AddNode(&tr, "8");
	tr.AddNode(&tr, "2");
	tr.AddNode(&tr, "4");
	tr.AddNode(&tr, "7");
	tr.AddNode(&tr, "6");
	std::cout << tr.IsBinTree(&tr);
}