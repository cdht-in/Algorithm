/*
 * BinarySearchTree.cpp
 *
 *  Created on: Jun 22, 2015
 *      Author: conghui
 */

#include "BinarySearchTree.h"

void Test(TreeNode* node)
{
	if (node == 0)
	{
		cout << "exception" << endl;
	}
	else
	{
		cout << node->val << endl;
	}
}

int main()
{
	vector<int> vec(
	{ 1, 2, 3, 4, 5, 6, 8, 9 });
	BinarySearchTree tree(vec);

	tree.Insert(0);
	tree.PrintTreeInOrder();
	int k = 8;
	cout << "rank " << k << " at the tree:" << endl;
	Test(tree.Rank(k));

	cout << "min: " << endl;
	Test(tree.Min());

	cout << "delete min:" << endl;
	tree.DeleteMin();
	tree.PrintTreeInOrder();

	cout << "delete max:" << endl;
	tree.DeleteMax();
	tree.PrintTreeInOrder();

	int key = 5;
	cout << "delete key: " << key << endl;
	tree.Delete(key);
	tree.PrintTreeInOrder();

	int key1 = 3;
	int key2 = 8;
	cout << "keys between " << key1 << " and " << key2 << endl;
	vector<TreeNode*> nodes = tree.Keys(key1, key2);
	for (int i = 0; i < nodes.size(); i++)
	{
		cout << nodes[i]->val << " ";
	}
	cout << endl;

}
