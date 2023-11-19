#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* parent, * left, * right;
	Node(const T& data = T(), Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr) :
		data{ data }, left{ left }, right{ right }, parent{ parent }
	{}
};

template <typename T>
class BTree
{
public:
	BTree() = default;
	void add(const T& data);
	void print() const;
	bool isEmpty() const;
	T min() const;
	T max() const;
	void removeMax();
	void removeMin();
	void clear();
	void removeBranch(const T& data);
	void printRange(const T& left, const T& right);
	Node<T>* findNode(const T& data) const;

	~BTree() {
		clear();
	}

private:
	Node<T>* root = nullptr;
	size_t size = 0;
	void helperPrint(Node<T>* node) const;
	void clearHelper(Node<T>* node);
	void deleteHelp(Node<T>* node);
	void printRangeHelper(Node<T>* node, const T& left, const T& right) const;

};

template<typename T>
inline void BTree<T>::add(const T& data)
{
	Node<T>* newNode = new Node<T>(data);
	++size;
	if (isEmpty())
	{
		root = newNode;
		return;
	}
	Node<T>* tmp = root;
	while (true)
	{
		if (newNode->data < tmp->data) { // визнaчаємо гілку
			if (tmp->left == nullptr)
			{
				tmp->left = newNode;
				newNode->parent = tmp;
				break;
			}
			tmp = tmp->left;
		}
		else
		{
			if (tmp->right == nullptr)
			{
				tmp->right = newNode;
				newNode->parent = tmp;
				break;
			}
			tmp = tmp->right;
		}
	}
}

template<typename T>
inline void BTree<T>::print() const
{
	cout << "TREE : ";
	helperPrint(root);
	cout << endl;
}

template<typename T>
inline bool BTree<T>::isEmpty() const
{
	return root == nullptr;
}

template<typename T>
inline T BTree<T>::min() const
{
	auto tmp = root;
	while (tmp->left != nullptr)
	{
		tmp = tmp->left;
	}
	return tmp->data;
}

template<typename T>
inline T BTree<T>::max() const
{
	auto tmp = root;
	while (tmp->right != nullptr)
	{
		tmp = tmp->right;
	}
	return tmp->data;
}

template<typename T>
inline void BTree<T>::removeMax()
{
	if (root == nullptr) {
		return;
	}

	Node<T>* max = root;
	Node<T>* parent = nullptr;
	while (max->right != nullptr)
	{
		parent = max;
		max = max->right;
	}
	if (parent == nullptr) {
		root = max->left;
	}
	else {
		parent->right = max->left;
	}
	delete max;
}

template<typename T>
inline void BTree<T>::removeMin()
{
	if (root == nullptr) {
		return;
	}

	Node<T>* min = root;
	Node<T>* parent = nullptr;
	while (min->left != nullptr)
	{
		parent = min;
		min = min->left;
	}
	if (parent == nullptr)
	{
		root = min->right;
	}
	else {
		parent->left = min->right;
	}
	delete min;
}

template <typename T>
inline void BTree<T>::clear()
{
	clearHelper(root);
	root = nullptr;
	size = 0;
}

template<typename T>
inline Node<T>* BTree<T>::findNode(const T& data) const
{
	auto tmp = root;
	while (tmp != nullptr)
	{
		if (tmp->data == data) {
			return tmp;
		}
		if (data < tmp->data) {
			tmp = tmp->left;
		}
		else {
			tmp = tmp->right;
		}
	}
	return nullptr;
}

template <typename T>
void BTree<T>::removeBranch(const T& data)
{
	auto node = findNode(data);
	if (node == nullptr)
	{
		cout << "- node not found -" << endl;
		return;
	}
	deleteHelp(node);
}

template<typename T>
inline void BTree<T>::printRange(const T& left, const T& right)
{
	printRangeHelper(root, left, right);
}

template<typename T>
inline void BTree<T>::helperPrint(Node<T>* node) const
{
	if (node != nullptr)
	{
		helperPrint(node->left);
		cout << node->data << "\t";
		helperPrint(node->right);
	}
}

template<typename T>
inline void BTree<T>::clearHelper(Node<T>* node)
{
	if (node != nullptr)
	{
		clearHelper(node->left);
		clearHelper(node->right);
		cout << "> " << node->data << endl;
		delete node;
	}
}

template<typename T>
inline void BTree<T>::deleteHelp(Node<T>* node)
{
	if (node != nullptr)
	{
		clearHelper(node->left);
		clearHelper(node->right);
		if (node->parent->left == node) {
			node->parent->left = nullptr;
		}
		else {
			node->parent->right = nullptr;
		}
		delete node;
	}
}

template<typename T>
inline void BTree<T>::printRangeHelper(Node<T>* node, const T& left, const T& right) const
{
	if (node != nullptr)
	{
		printRangeHelper(node->left, left, right);
		if (node->data < right && node->data > left)
		{
			cout << node->data << "\t";
		}
		printRangeHelper(node->right, left, right);
	}
}
