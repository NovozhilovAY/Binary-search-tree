#pragma once

template <class T>
class TreeNode
{
private:
	T value;
	int count;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
public:
	TreeNode(T val = T(), TreeNode* l = nullptr, TreeNode* r = nullptr);
	void PrintTree(TreeNode* root);
	void AddNode(TreeNode* root, T val);
	void DelSubTree(TreeNode* subtree);
	TreeNode* Min(TreeNode* root);
	TreeNode* Max(TreeNode* root);

};

template <class T>
class BinarySearchTree
{
	TreeNode<T>* root;

};

template<class T>
inline TreeNode<T>::TreeNode(T val, TreeNode* l, TreeNode* r)
{
	value = val;
	count = 1;
	left = l;
	right = r;
}

template<class T>
inline void TreeNode<T>::PrintTree(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	PrintTree(root->left);
	PrintTree(root->right);
	std::cout << root->value << " - " << root->count << "\n";
}

template<class T>
inline void TreeNode<T>::AddNode(TreeNode* root, T val)
{
	if (root->value < val)
	{
		if (root->right == nullptr)
		{
			root->right = new TreeNode(val);
			return;
		}
		AddNode(root->right, val);
	}
	else if (root->value > val)
	{
		if (root->left == nullptr)
		{
			root->left = new TreeNode(val);
			return;
		}
		AddNode(root->left, val);
	}
	else
	{
		root->count++;
		return;
	}
}

template<class T>
inline void TreeNode<T>::DelSubTree(TreeNode* subtree)
{
	if (subtree->left != nullptr)
	{
		DelSubTree(subtree->left);
	}
	if (subtree->right != nullptr)
	{
		DelSubTree(subtree->right);
	}
	delete subtree;
}
