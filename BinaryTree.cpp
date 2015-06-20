/*
 implementation of the self-balanced binary tree
*/

#include <cstdio>
#include <cmath>

void PrintData (int* data, int size)
{
  for (int i = 0; i < size; i++) {
    printf ("%d ", data[i]);
  }
  printf ("\n");
}

//O(n^2)
void SelectionSort (int* data, int size)
{
  int tmp = 0;
  for (int i = 0; i < size - 1; i++) {
    int k = i;
    for (int j = i + 1; j < size; j++) {
      if (data[j] < data[k])
        k = j;
    }
    tmp = data[i];
    data[i] = data[k];
    data[k] = tmp;
  }
}

struct Node {
  int value;
  Node* parent;
  Node* leftchild;
  Node* rightchild;
  Node (int value) : parent(), value (value) {
    leftchild = 0;
    rightchild = 0;
  }
  Node() : value(), parent() {
    leftchild = 0;
    rightchild = 0;
  }
};

//take a sorted and unique array, take the middle to be the root then construct left and right hand seperatedly, take log(N), where N is the size of the list
class BinaryTree {

  int Size;
  int LH;
  int RH;
  Node* Root;

  //pick the middle value from the array to construct the binary tree
  Node* ConstructMid (int* data, int left, int right) {
    int root = (left + right) / 2;
    //new node in the tree
    Node* node = new Node (data[root]);
    printf ("%d\n", data[root]);
    Size++;
    if (left < root) {
      LH++;
      node->leftchild = ConstructMid (data, left, root - 1);
      printf ("%d  ", node->leftchild->value);
    }
    if (right > root) {
      RH++;
      node->rightchild = ConstructMid (data, root + 1, right);
      printf ("%d\n", node->rightchild->value);
    }
    return node;
  }

  //pick the left most value to construct the binary tree
  void ConstructLeft (int* data, Node* parent, int left, int right) {
    if (left >= right)
      return;
    x    //skewed to the left
    if (LH - RH == 2)
      Node* node = new Node (data[left]);
    //maintain a pointer to its parent
    node->parent = parent;
    //should be called the very first time
    if (node->value < parent->value && ) {
      parent->leftchild = new Node (node->value);
      LH++;
      ConstructLeft (data, parent->leftchild, left + 1, right);
    }
    else {
      parent->rightchild = new Node (node->value);
      RH++;
      ConstructLeft (data, parent->rightchild, left + 1, right);
    }
  }

public:
  BinaryTree (int* data, int size) : Root (0), Size(), LH(), RH() {
    //sort the data first
    SelectionSort (data, size);
    //Root = ConstructMid(data,0,size - 1);
    Root = new Node (data[0]);
    ConstructLeft (data, data[0], 1, size - 1);
    printf ("LH:%d  RH:%d\n", LH, RH);
  }

  //test if the tree has x
  bool HasValue (Node* node, int x) {
    static int height = 0;
    if (node->value == x) {
      printf ("height is %d\n", height);
      return true;
    }
    if (node->leftchild != 0 && x < node->value) {
      height++;
      return HasValue (node->leftchild, x);
    }
    if (node->rightchild != 0 && x > node->value) {
      height++;
      return HasValue (node->rightchild, x);
    }
    printf ("height is 0\n");
    return false;
  }

  //insert x into its appropriate position, either its a leaf or it = is a node in between
  void Insert (Node* node, int x) {
    if (node->value == x)
      return;
    if (x < node->value) {
      //	printf("node is %d x is %d\n",node->value,x);
      if (node->leftchild == 0) {
        node->leftchild = new Node (x);
        //rebalance if needed
        return;
      }
      Insert (node->leftchild, x);
    }
    else {
      if (node->rightchild == 0) {
        node->rightchild = new Node (x);
        return;
      }
      Insert (node->rightchild, x);
    }
  }

  //remove the value from the binary if presented
  bool Remove (Node* node, int x) {
    if (node->value == x) {
      delete node;
      return true;
    }
    if (x < node->value) {
      if (node->leftchild == 0)
        return false;
      if (node->leftchild->value == x) {
        Node* tmp = node->leftchild;
        node->leftchild = 0;
        return Remove (tmp, x);
      }
      return Remove (node->leftchild, x);
    }
    else {
      if (node->rightchild == 0)
        return false;
      if (node->rightchild->value == x) {
        Node* tmp = node->rightchild;
        node->rightchild = 0;
        return Remove (tmp, x);
      }
      return Remove (node->rightchild, x);
    }
  }

  //print the left hand side
  void PrintLeft() {
    PrintTreeHelper (Root->leftchild);
  }

  //print the right hand side
  void PrintRight() {
    PrintTreeHelper (Root->rightchild);
  }

  //print the binary tree in a sorted order
  void PrintTree() {
    PrintTreeHelper (Root);
    printf ("\n");
  }

  void PrintTreeHelper (Node* node) {
    if (node->leftchild != 0)
      PrintTreeHelper (node->leftchild);
    printf ("%d ", node->value);
    if (node->rightchild != 0)
      PrintTreeHelper (node->rightchild);
  }

  //check if the node is within the correct range
  bool CheckTree (Node* root) {
    return isValidHelper (root, 0, 10);
  }

  bool isValidHelper (Node* curr, int min, int max) {
    if (curr->leftchild != 0) {
      if (curr->leftchild->value < min || !isValidHelper (curr->leftchild, min, curr->value) )
        return false;
    }
    if (curr->rightchild != 0) {
      if (curr->rightchild->value > max || !isValidHelper (curr->rightchild, curr->value, max) )
        return false;
    }
    return true;
  }
};

int main()
{
  int foo[] = {1, 4, 6, 8, 10, 9, 7};
  int size = (int) (sizeof (foo) / sizeof (int) );
  BinaryTree tree (foo, size);
  tree.PrintTree();
  return 0;
}
