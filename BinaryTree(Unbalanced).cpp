/*
  construct a binary tree, NOTE that this tree isn't necessarly a binary search tree e.g sorted
*/
#include "BinaryTree(Unbalanced).h"
#include <cstdio>
#include <stack>
#include <unordered_set>

#define DEADBEEF 0xDEADBEAF

void BinaryTree::Construct (Node* cur, int& p , int* data, int len)
{
  if (p >= len)
    return;
  if (p < len) {
    cur->left = new Node (data[p]);
    p++;
  }
  if (p < len) {
    cur->right = new Node (data[p]);
    p++;
  }
  Construct (cur->left, p, data, len);
  Construct (cur->right, p, data, len);
}

//this take O(n) to build the linkedlist, if the size is unknown before hand, a linear scan to find the size first, bottom up approache to build the binary tree
Node* BinaryTree::LinkedlistToTree (std::list<int>::iterator& i, int start, int end)
{
  if (start > end)
    return 0;
  // same as (start+end)/2, avoids overflow
  int mid = (start + end) / 2;
  Node* leftChild  = LinkedlistToTree (i, start, mid - 1);
  printf ("%d\n", *i);
  Node* parent = new Node (*i);
  parent->left = leftChild;
  i++;
  parent->right = LinkedlistToTree (i, mid + 1, end);
  return parent;
}

Node* BinaryTree::ArrayToTree (const std::vector<int>& vec, int start, int end)
{
  if (start > end)
    return 0;
  int mid = (start + end) / 2;
  Node* parent = new Node (vec[mid]);
  parent->left = ArrayToTree (vec, start, mid - 1);
  parent->right = ArrayToTree (vec, mid + 1, end);
  return parent;
}

//construct from a sorted linked list
BinaryTree::BinaryTree (std::list<int>& list)
{
  size = list.size();
  std::list<int>::iterator i = list.begin();
  root = LinkedlistToTree (i, 0, list.size() - 1);
}

BinaryTree::BinaryTree (std::vector<int>& vec)
{
  size = vec.size();
  root = ArrayToTree (vec, 0, vec.size() - 1);
}

BinaryTree::BinaryTree (int* data, int size) : size (size)
{
  if (size >= 1) {
    int p = 0;
    root = new Node (data[p++]);
    Construct (root, p, data, size);
  }
}

//in-order traversal,visit the parent in the middle
void PrintTreeInOrder (Node* node)
{
  if (node->left != 0)
    PrintTreeInOrder (node->left);
  printf ("%d ", node->val);
  if (node->right != 0)
    PrintTreeInOrder (node->right);
}

//post order traversal, visit the parent the last
void PrintTreePostOrder (Node* node)
{
  if (node->left != 0)
    PrintTreePostOrder (node->left);
  if (node->right != 0)
    PrintTreePostOrder (node->right);
  printf ("%d ", node->val);
}

//pre order traversal, visit the parent the first
void PrintTreePreOrder (Node* node)
{
  printf ("%d ", node->val);
  if (node->left != 0)
    PrintTreePreOrder (node->left);
  if (node->right != 0)
    PrintTreePreOrder (node->right);
}

//level order traversal, visit all nodes top down
void PrintTreeLevelOrderI (Node* node)
{
  std::queue<Node*> q;
  int curlevelcount = 0;
  int nextlevelcount = 0;
  q.push (node);
  curlevelcount++;
  while (!q.empty() ) {
    Node* f = q.front();
    q.pop();
    curlevelcount--;
    //for(int i = 0; i < curlevelcount; i++)
    //printf(" ");
    printf (" %d ", f->val);
    if (f->left != 0) {
      q.push (f->left);
      nextlevelcount++;
    }
    if (f->right != 0) {
      q.push (f->right);
      nextlevelcount++;
    }
    if (curlevelcount == 0) {
      printf ("\n");
      curlevelcount = nextlevelcount;
      nextlevelcount = 0;
    }
  }
}

//from bottom up, use a stack to reverse the traversal order
void PrintTreeLevelOrderII (Node* node)
{
  std::queue<Node*> q;
  std::stack<Node*> s;
  q.push (node);
  while (!q.empty() ) {
    Node* f = q.front();
    s.push (f);
    if (f->left != 0)
      q.push (f->left);
    if (f->right != 0)
      q.push (f->right);
    q.pop();
  }
  while (!s.empty() ) {
    printf ("%d ", s.top()->val);
    s.pop();
  }
}


//find the closet ancestor of two nodes
int ClosestAncestor (int a, int b, Node* root)
{
  std::queue<Node*> qa;
  std::queue<Node*> qb;
  std::unordered_set<int> set;
  //find the path from root to a and b
  ClosestAncestorHelper (a, root, qa);
  ClosestAncestorHelper (b, root, qb);
  while (1) {
    if (!qa.empty() ) {
      if (set.find (qa.front()->val) != set.end() )
        return qa.front()->val;
      else {
        set.insert (qa.front()->val);
        qa.pop();
      }
    }
    if (!qb.empty() ) {
      if (set.find (qb.front()->val) != set.end() )
        return qb.front()->val;
      else {
        set.insert (qb.front()->val);
        qb.pop();
      }
    }
  }
}

//basically find the path to the node in the tree, O(h) for the search if the tree is not sorted, O(log(n)) otherwise
bool ClosestAncestorHelper (int val, Node* cur, std::queue<Node*>& q)
{
  //record the path if only the node is in the tree
  if (val == cur->val) {
    q.push (cur);
    return true;
  }
  if (cur->left != 0) {
    bool found = ClosestAncestorHelper (val, cur->left, q);
    if (found) {
      q.push (cur);
      return true;
    }
  }
  if (cur->right != 0) {
    bool found = ClosestAncestorHelper (val, cur->right, q);
    if (found) {
      q.push (cur);
      return true;
    }
  }
  //the node is not in the tree,exaustly search the entire tree
  return false;
}


//the log(n) approach
Node* ClosestAncestorI (Node* l, Node* r, Node* root)
{
  if ( root == 0 || l == 0 || r == 0 )
    return 0;
  return ClosestAncestorIHelper ( root, l->val, r->val);
}

Node* ClosestAncestorIHelper (Node* node, int a, int b)
{
  while ( node != 0 ) {
    int val = node->val;
    if ( val > a && val > b )
      node = node->left;
    else if ( val < a && val < b )
      node = node->right;
    else
      // a < val < b
      return node;
  }
  return 0; // only if empty tree
}

int SumOfNode (Node* node)
{
  if (node == 0)
    return 0;
  //get the left tree sum
  int leftsum = SumOfNode (node->left);
  //get the right tree sum
  int rightsum = SumOfNode (node->right);
  return node->val + leftsum + rightsum;
}

//If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal
//To flatten a binary tree, according to the given example, is to recursively insert the left subtree to the right subtree and append the original right subtree to the end of the left subtree, NOTE that this algorithm is in-place
Node* FlatenTree (Node* root)
{
  if (root == 0)
    return root;
  //record the current right tree for future appending to the new right tree
  Node* rtree = root->right;
  if (root->left != 0) {
    //insert the left tree before the right tree
    root->right = root->left;
    root->left = 0;
    //go the next node in the original left tree
    root = FlatenTree (root->right);
  }
  //now recursively deal with the right tree
  if (rtree != 0) {
    root->right = rtree;
    root = FlatenTree (root->right);
  }
  //the returned root is the last node of the flatened tree
  return root;
}



//recursively if the current nodes of each tree are same, so are the left tree and the right tree
bool isSameTree (const Node* t1, const Node* t2)
{
  // Same node check - also handles both NULL case
  if (t1 == t2)
    return true;
  // Gone past leaf on one side check, NOTE that if both are 0, it would have been caught at the previous step
  if ( (t1 == 0) || (t2 == 0) )
    return false;
  // Do data checks and recursion of tree
  return (t1->val == t2->val) && isSameTree (t1->left, t2->left)
         && isSameTree (t1->right, t2->right);
}

//Serialize
bool SerializeTree (const Node* node)
{
  std::queue<int> sq;
  std::queue<const Node*> q;
  if (node == 0)
    return true;
  q.push (node);
  while (!q.empty() ) {
    const Node* n = q.front();
    q.pop();
    if (n == 0)
      sq.push (DEADBEEF);
    else {
      sq.push (n->val);
      q.push (n->left);
      q.push (n->right);
    }
  }
  while (!sq.empty() ) {
    printf ("%d ", sq.front() );
    sq.pop();
  }
  printf ("\n");
}

bool isSymmetric (const Node* l, const Node* r)
{
  if (l == 0 && r == 0)
    return true;
  if ( (l == 0 && r != 0) || (l != 0 && r == 0) )
    return false;
  return (l->val == r->val) && isSymmetric (l->left, r->right) && isSymmetric (l->right, r->left);
}

//swap the values of the tree
void SwapTree (Node* node)
{
  if (node != 0) {
    //swap left and right child from top down
    Node* tmp = node->left;
    node->left = node->right;
    node->right = tmp;
    //swap each subtree
    CreateMirror (node->left);
    CreateMirror (node->right);
  }
}

//create a mirror of the tree
Node* CreateMirror (const Node* node)
{
  if (node != 0) {
    Node* root = new Node;
    CreateMirrorHelper ( (const Node*) node, root);
    return root;
  }
  return 0;
}

void CreateMirrorHelper (const Node* oldNode, Node* newNode)
{
  newNode->val = oldNode->val;
  if (oldNode->left) {
    newNode->left = new Node;
    CreateMirrorHelper (oldNode->left, newNode->left);
  }
  if (oldNode->right) {
    newNode->right = new Node;
    CreateMirrorHelper (oldNode->right, newNode->right);
  }
}

int maxPathSum (Node* root)
{
  int csum = 0;
  int maxsum = -1;
  maxPathSumHelper (root, csum, maxsum);
  return maxsum;
}
void maxPathSumHelper (Node* node, int& csum, int& maxsum)
{
  if (!node) {
    csum = 0;
    return;
  }
  int lsum = 0, rsum = 0;
  //get the left tree max
  maxPathSumHelper (node->left, lsum, maxsum);
  //get the right tree max
  maxPathSumHelper (node->right, rsum, maxsum);
  //get the bigger one of left or right tree, Note that the first comparison is needed if there are negative nodes in the tree
  csum = std::max (node->val, std::max (node->val + lsum, node->val + rsum) );
  //if the tree go throuh a root, there is a potential max sum too
  maxsum = std::max (maxsum, std::max (csum, node->val + lsum + rsum) );
}

void SumRootToLeafHelper (Node* node, int& TotalSum, std::stack<int>& SubSum)
{
  //keep track of the current sum
  SubSum.push (SubSum.top() + node->val);
  //sum the left first
  if (node->left != 0)
    SumRootToLeaf (node->left);
  if (node->right != 0)
    SumRootToLeaf (node->right);
  //if it is a leaf, sum it up
  if (node->left == 0 && node->right == 0)
    TotalSum += SubSum.top();
  SubSum.pop();
}

void SumRootToLeaf (Node* node)
{
  int TotalSum = 0;
  std::stack<int> SubSum;
  SumRootToLeafHelper (node, TotalSum, SubSum);
}

//check if the node is within the correct range
bool isValidTree (Node* node)
{
  int min = -9999;
  int max = 9999;
  return isValidHelper (node, min, max);
}

bool isValidHelper (Node* curr, int min, int max)
{
  if (curr->left != 0) {
    //if the left tree is smaller than the min
    if (curr->left->val < min)
      return false;
    //recursively check the left tree
    if (!isValidHelper (curr->left, min, curr->val) )
      return false;
  }
  if (curr->right != 0) {
    //if the right tree is bigger than the max
    if (curr->right->val > max)
      return false;
    //recursively check the right tree
    if (!isValidHelper (curr->right, curr->val, max) )
      return false;
  }
  return true;
}

int main()
{
  int foo[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int size = sizeof (foo) / sizeof (int);
  std::vector<int> vec (foo, foo + size);
  BinaryTree bar (vec);
  Node* root = (Node*) bar.GetRoot();
  PrintTreeLevelOrderI (root);
  printf ("\n");
  printf ("is valid tree %d\n", isValidTree (root) );
}

