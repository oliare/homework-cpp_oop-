#include <iostream>
#include "BTree.h"
using namespace std;

int main()
{
	BTree<int> tree;
	tree.add(50);
	tree.add(45);
	tree.add(49);
	tree.add(32);
	tree.add(60);
	tree.add(65);
	tree.add(12);
	tree.add(70);
	tree.add(64);
	tree.print();
	cout << "Min: " << tree.min() << endl;
	cout << "Max: " << tree.max() << endl;

	tree.removeMin();
	cout << "\nMin after removal: " << tree.min() << endl;
	tree.removeMax();
	cout << "Max after removal: " << tree.max() << endl;

	cout << "\nNumbers in range: ";
	tree.printRange(32, 64);

	cout << endl << endl;
	tree.print();
	tree.removeBranch(60);
	tree.print();
	cout << "\nAll Nodes are cleared " << endl;
	tree.clear();

}