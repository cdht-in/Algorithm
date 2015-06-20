#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <queue>
#include <list>
#include <vector>
#include <stack>

struct Node {
  int val;
  Node* left;
  Node* right;
  Node (int val) : val (val), left (0), right (0) {};
  Node() : val(), left (0), right (0) {};
};

struct BinaryTree {
private:
  int size;
  Node* root;

  //construct a skewed binary tree
  void Construct (Node* cur, int& p , int* data, int len);

  //this take O(n) to build the linkedlist, if the size is unknown before hand, a linear scan to find the size first, bottom up approache to build the binary tree
  Node* LinkedlistToTree (std::list<int>::iterator& i, int start, int end);

  Node* ArrayToTree (const std::vector<int>& vec, int start, int end);

public:
  //construct from a sorted linked list
  BinaryTree (std::list<int>& list);

  //construct from a sorted array
  BinaryTree (std::vector<int>& vec);

  //construct a binary tree from a random array
  BinaryTree (int* data, int size);

  inline const Node* GetRoot() const {
    return root;
  }
};


//If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal To flatten a binary tree, according to the given example, is to recursively insert the left subtree to the right subtree and append the original right subtree to the end of the left subtree, NOTE that this algorithm is in-place
Node* FlatenTree (Node* root);

bool ClosestAncestorHelper (int val, Node* cur, std::queue<Node*>& q);

//this method works for any generic tree
int ClosestAncestor (int a, int b);

Node* ClosestAncestorI (Node* l, Node* r);

Node* ClosestAncestorIHelper (Node* node, int a, int b);

//calculate the sum of all nodes in the tree
int SumOfNode (Node* node);

//in-order traversal,visit the parent in the middle
void PrintTreeInOrder (Node* node);

//post order traversal, visit the parent the last
void PrintTreePostOrder (Node* node);

//pre order traversal, visit the parent the first
void PrintTreePreOrder (Node* node);

//level order traversal, visit all nodes top down
void PrintTreeLevelOrderI (Node* node);

//from bottom up, use a stack to reverse the traversal order
void PrintTreeLevelOrderII (Node* node);

//swap the tree
void SwapTree (Node* node);

void CreateMirrorHelper (const Node* oldNode, Node* newNode);
//create a mirror of the tree
Node* CreateMirror (const Node* node);

//Serialize tree
bool SerializeTree (Node* node);

//recursive
bool isSymmetricI (const Node* l, const Node* r);

void isSymmetricHelper (const Node* node, std::vector<int>& vec);

//recursively if the current nodes of each tree are same, so are the left tree and the right tree
bool isSameTree (const Node* t1, const Node* t2);


/*
  Given a binary tree, find the maximum path sum.
  The path may start and end at any node in the tree.
  For example:
  Given the below binary tree,
  1
  / \
  2   3
  Return 6.
*/

int maxPathSum (Node* root);

void maxPathSumHelper (Node* node, int& csum, int& maxsum);

/*
  Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

  An example is the root-to-leaf path 1->2->3 which represents the number 123.

  Find the total sum of all root-to-leaf numbers.

  For example,

  1
  / \
  2   3
  The root-to-leaf path 1->2 represents the number 12.
  The root-to-leaf path 1->3 represents the number 13.

  Return the sum = 12 + 13 = 25.
*/

void SumRootToLeafHelper (Node* node, int& TotalSum, std::stack<int>& SubSum);

void SumRootToLeaf (Node* node);

bool isValidHelper (Node* curr, int min, int max);

bool isValidTree(Node* node);

#endif
