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
	TreeNode<std::string>* tree = new TreeNode< std::string >("ses");
	tree->AddNode(tree, "sas");
	tree->AddNode(tree, "sas");
	tree->PrintTree(tree);
	return 0;
}