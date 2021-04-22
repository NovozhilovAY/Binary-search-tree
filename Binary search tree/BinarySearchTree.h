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
	TreeNode<T>* root = nullptr;
public:
	BinarySearchTree(){}
	BinarySearchTree(const T& val);
	BinarySearchTree(const std::vector<T>& vect);
	~BinarySearchTree();

	void Add(const T& val);
	void Print();
	
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
	std::cout << root->value << " - " << root->count << "\n";
	PrintTree(root->right);
	
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
	if (!subtree)
	{
		return;
	}
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

template<class T>
inline TreeNode<T>* TreeNode<T>::Min(TreeNode* root)
{
	if (root->left != nullptr)
	{
		return Min(root->left);
	}
	return root;
}

template<class T>
inline TreeNode<T>* TreeNode<T>::Max(TreeNode* root)
{
	if (root->right != nullptr)
	{
		return Max(root->right);
	}
	return root;
}

template<class T>
inline BinarySearchTree<T>::BinarySearchTree(const T& val)
{
	Add(val);
}

template<class T>
inline BinarySearchTree<T>::BinarySearchTree(const std::vector<T>& vect)
{
	for (auto i : vect)
	{
		Add(i);
	}
}

template<class T>
inline BinarySearchTree<T>::~BinarySearchTree()
{
	root->DelSubTree(root);
}

template<class T>
inline void BinarySearchTree<T>::Add(const T& val)
{
	if (!root)
	{
		root = new TreeNode<T>(val);
		return;
	}
	root->AddNode(root, val);
}

template<class T>
inline void BinarySearchTree<T>::Print()
{
	root->PrintTree(root);
}
