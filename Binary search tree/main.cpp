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
	TreeNode<std::string>* tree = new TreeNode< std::string >("5");
	tree->AddNode(tree, "6");
	tree->AddNode(tree, "7");
	tree->AddNode(tree, "4");
	tree->AddNode(tree, "2");
	tree->AddNode(tree, "3");
	tree->Max(tree);
	tree->Min(tree);
	tree->DelSubTree(tree);
	return 0;
}