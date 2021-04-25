#pragma once
template <class T>
class BinarySearchTree;

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
	T GetVal()const;
	void PrintTree(TreeNode* root);
	void AddVal(TreeNode* root, const T& val);
	void DelSubTree(TreeNode* subtree);
	TreeNode* Min(TreeNode* root);
	TreeNode* Max(TreeNode* root);
	int find(TreeNode* root, const T& val);
	bool IsBinTree(TreeNode* root);
	void DelNode(TreeNode* root, const T& val);

	TreeNode<T>* findNode(TreeNode* root, const T& val);
	TreeNode<T>* findParent(TreeNode* root, const TreeNode* child);
	static void AddNode(TreeNode* root, TreeNode* node);

	friend class BinarySearchTree<T>;
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
	void Del(const T& val);
	void Add(const std::vector<T>& vect);
	void Print();
	int find(const T& val);

private:
	void DelRoot();
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
inline T TreeNode<T>::GetVal() const
{
	return value;
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
inline void TreeNode<T>::AddVal(TreeNode* root, const T& val)
{
	if (root->value < val)
	{
		if (root->right == nullptr)
		{
			root->right = new TreeNode(val);
			return;
		}
		AddVal(root->right, val);
	}
	else if (root->value > val)
	{
		if (root->left == nullptr)
		{
			root->left = new TreeNode(val);
			return;
		}
		AddVal(root->left, val);
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
inline int TreeNode<T>::find(TreeNode* root, const T& val)
{
	if (root == nullptr)
	{
		return 0;
	}
	if (root->value == val)
	{
		return root->count;
	}
	if (root->value < val)
	{
		return find(root->right, val);
	}
	else
	{
		return find(root->left, val);
	}

}

template<class T>
inline void TreeNode<T>::AddNode(TreeNode* root, TreeNode* node)
{
	if (root->value < node->value)
	{
		if (root->right == nullptr)
		{
			root->right = node;
			return;
		}
		AddNode(root->right, node);
	}
	else if (root->value > node->value)
	{
		if (root->left == nullptr)
		{
			root->left = node;
			return;
		}
		AddNode(root->left, node);
	}
	else
	{
		root->count++;
		return;
	}
}

template<class T>
inline bool TreeNode<T>::IsBinTree(TreeNode* root)
{
	if (!root)
	{
		return true;
	}
	if (root->left != nullptr && root->left->value > root->value)
	{
		return false;
	}
	if (root->right != nullptr && root->right->value < root->value)
	{
		return false;
	}
	return IsBinTree(root->left) && IsBinTree(root->right);
}

template<class T>
inline void TreeNode<T>::DelNode(TreeNode* root, const T& val)
{
	enum side{LEFT,RIGHT};
	if (!root)
	{
		return;
	}
	TreeNode* del_node = findNode(root, val);
	if (!del_node)
	{
		return;
	}
	TreeNode* parent = findParent(root,del_node);
	side del_side;
	if (parent->left == del_node)
	{
		del_side = LEFT;
	}
	if (parent->right == del_node)
	{
		del_side = RIGHT;
	}

	if (del_node->left == nullptr && del_node->right == nullptr)
	{
		delete del_node;
		switch (del_side)
		{
		case LEFT:
			parent->left = nullptr;
			break;
		case RIGHT:
			parent->right = nullptr;
			break;
		}
		return;
	}

	if (del_node->left != nullptr && del_node->right == nullptr)
	{
		switch (del_side)
		{
		case LEFT:
			parent->left = del_node->left;
			break;
		case RIGHT:
			parent->right = del_node->left;
			break;
		}
		delete del_node;
		return;
	}
	if (del_node->left == nullptr && del_node->right != nullptr)
	{
		switch (del_side)
		{
		case LEFT:
			parent->left = del_node->right;
			break;
		case RIGHT:
			parent->right = del_node->right;
			break;
		}
		delete del_node;
		return;
	}
	if (del_node->left != nullptr && del_node->right != nullptr)
	{
		AddNode(del_node->right,del_node->left);
		del_node->left = nullptr;
		switch (del_side)
		{
		case LEFT:
			parent->left = del_node->right;
			break;
		case RIGHT:
			parent->right = del_node->right;
			break;
		}
		delete del_node;
		return;
	}
}

template<class T>
inline TreeNode<T>* TreeNode<T>::findNode(TreeNode* root, const T& val)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (root->value == val)
	{
		return root;
	}
	if (root->value < val)
	{
		return findNode(root->right, val);
	}
	else
	{
		return findNode(root->left, val);
	}
}

template<class T>
inline TreeNode<T>* TreeNode<T>::findParent(TreeNode* root, const TreeNode* child)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (root->left == child || root->right == child)
	{
		return root;
	}
	if (root->value < child->value)
	{
		return findParent(root->right, child);
	}
	else
	{
		return findParent(root->left, child);
	}
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
	root->AddVal(root, val);
}

template<class T>
inline void BinarySearchTree<T>::Del(const T& val)
{
	if (!root)
		return;
	if (val == root->GetVal())
	{
		DelRoot();
		return;
	}
	root->DelNode(root, val);
}

template<class T>
inline void BinarySearchTree<T>::Add(const std::vector<T>& vect)
{
	for (auto i : vect)
	{
		Add(i);
	}
}

template<class T>
inline void BinarySearchTree<T>::Print()
{
	root->PrintTree(root);
}

template<class T>
inline int BinarySearchTree<T>::find(const T& val)
{
	return root->find(root,val);
}

template<class T>
inline void BinarySearchTree<T>::DelRoot()
{
	if (!root)
		return;

	if (root->left == nullptr && root->right == nullptr)
	{
		delete root;
		root = nullptr;
		return;
	}

	if (root->left != nullptr && root->right == nullptr)
	{
		TreeNode<T>* tmp = root->left;
		delete root;
		root = tmp;
		return;
	}
	if (root->left == nullptr && root->right != nullptr)
	{
		TreeNode<T>* tmp = root->right;
		delete root;
		root = tmp;
		return;
	}
	if (root->left != nullptr && root->right != nullptr)
	{
		TreeNode<T>::AddNode(root->right, root->left);
		TreeNode<T>* tmp = root->right;
		TreeNode<T>* tmp2 = root;
		root = tmp;
		tmp2->left = nullptr;
		tmp2->right = nullptr;
		delete tmp2;

		return;
	}
}
