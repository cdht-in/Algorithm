/*
  AVL tree implementation, the tree is not necessarily a binary search tree
*/
#include <cstdio>
#include <iostream>
#include <iomanip>

struct Node {
  int val;
  Node* left;
  Node* right;
  Node (int val) : val (val), left (0), right (0) {}
  Node() : val(), left (0), right (0) {};
};

struct BinaryTree {

  int getFactorI(){
    return getFactor(root);
  }
    
private:
  int size;
  Node* root;
  //take the mid one, and use it to be the new root
  Node* Construct (int* data, int begin, int end) {
    if (begin > end)
      return 0;
    //subroot
    int mid = (begin + end) / 2;
    Node* node = new Node (data[mid]);
    //construct the left tree
    node->left = Construct (data, begin, mid - 1);
    //construct the right tree
    node->right = Construct (data, mid + 1, end);
    return node;
  }

  void Balance (Node* n) {
    //n is the parent node that has +-2 factor
    int bfactor = getFactor (n);
    //left subtree outweights the right one
    if (bfactor == 2) {
      //the bfactor on its left child needs to be checked
      int lchildfactor = getFactor (n->left);
      //left right rotation is needed
      if (lchildfactor == -1) {
        printf ("left right rotation\n");
        n = left_right_rotation (n);
      }
      //a single right rotation is needed
      else if (lchildfactor == 1) {
        printf ("left left rotation\n");
        n = left_left_rotation (n);
      }
    }
    //right subtree outweights the left one
    else if (bfactor == -2) {
      //the bfactor on its right child needs to be checked
      int rchildfactor = getFactor (n->right);
      //single left rotation is needed
      if (rchildfactor == -1) {
        printf ("right right rotation\n");
        n = right_right_rotation (n);
      }
      //right left rotation is needed
      else if (rchildfactor = 1) {
        printf ("right left rotation\n");
        n = right_left_rotation (n);
      }
    }
  }

  Node* right_left_rotation (Node* parent) {
    Node* node = parent -> right;
    parent->right = left_left_rotation (node);
    return right_right_rotation (parent);
  }


  Node* left_left_rotation (Node* parent) {
    Node* node = parent -> left;
    parent -> left = node -> right;
    node -> right = parent;
    return node;
  }

  Node* right_right_rotation (Node* parent) {
    //pointer to -1 factor node
    Node* node = parent ->right;
    //move the node left child to be the parent right child
    parent->right = node -> left;
    //make the node the number parent
    node -> left = parent;
    return node;
  }

  Node* left_right_rotation (Node* parent) {
    Node* node = parent->left;
    parent -> left = right_right_rotation (node);
    return left_left_rotation (parent);
  }

  //traverse down the tree, and find the right spot
  void InsertHelper (Node* node, int val) {
    if (val < node->val) {
      //if the left child is null, stick it in there
      if (node->left == 0) {
        node->left = new Node (val);
        //check for the balanced factor, rebalanced if needed
        Balance (node);
      }
      else
        //otherwise recursivly search the left subtree
        InsertHelper (node->left, val);
    }
    else {
      if (node->right == 0) {
        node->right = new Node (val);
        //check for the balanced factor, rebalanced if needed
        Balance (node);
      }
      else
        InsertHelper (node->right, val);
    }
  }

  //pre-order traversal
  void PrintTreeInOrderHelper (Node* node) {
    if (node->left != 0)
      PrintTreeInOrderHelper (node->left);
    printf ("%d ", node->val);
    if (node->right != 0)
      PrintTreeInOrderHelper (node->right);
  }

  //from bottom up calculate the height, e.g the max depth from the root to a leaf
  int find_height (Node* node) {
    int height = 0;
    if (node != 0) {
      //calculate each AVL subtree
      int left_height = find_height (node->left);
      int right_height = find_height (node->right);
      //NOTE here the parenthese on the right is necessary
      height = 1 + ( (left_height > right_height) ? left_height : right_height);
    }
    return height;
  }

  int FindMinDepth (Node* node) {
    int height = 0;
    if (node != 0) {
      //calculate each AVL subtree
      int left_height = find_height (node->left);
      int right_height = find_height (node->right);
      //NOTE here the parenthese on the right is necessary
      height = 1 + ( (left_height > right_height) ? right_height : left_height);
    }
    return height;
  }

  //get the balanced factor
  int getFactor (Node* node) {
    int left_height = find_height (node -> left);
    int right_height = find_height (node -> right);
    int b_factor = left_height - right_height;
    return b_factor;
  }

  //pretty print the tree
  void PrintTreePostOrderHelper (Node* p, int indent = 0) {
    if (p != 0) {
      if (p->left)
        PrintTreePostOrderHelper (p->left, indent + 4);
      if (p->right)
        PrintTreePostOrderHelper (p->right, indent + 4);
      if (indent)
        std::cout << std::setw (indent) << ' ';
      std::cout << p->val << std::endl;
    }
  }

public:

  BinaryTree (int* data, int size) : size (size), root() {
    root = Construct (data, 0, size);
  }

  void Insert (int val) {
    InsertHelper (root, val);
  }

  inline const Node* getRoot() const {
    return root;
  }

  int getHeight() {
    return find_height (root);
  }

  void PrintTreeInOrder() {
    PrintTreeInOrderHelper (root);
  }

  void PrintTreePostOrder() {
    //pretty print the tree
    PrintTreePostOrderHelper (root);
  }
};


int main()
{
  int foo[] = {1, 2, 3, 4, 5, 6};
  int size = sizeof (foo) / sizeof (int);
  BinaryTree tree (foo, size - 1);
  for (int i = 7; i < 10; i++)
    tree.Insert (i);
  printf ("height is %d factor is %d\n", tree.getHeight(),tree.getFactorI() );
  
  tree.PrintTreePostOrder();
  printf ("\n");
}
