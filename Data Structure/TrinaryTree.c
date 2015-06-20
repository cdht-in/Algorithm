#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
  to compile and run => gcc TrinaryTree.c => ./a.out
*/

struct TriNode {
  int val;
  struct TriNode* left;
  struct TriNode* mid;
  struct TriNode* right;;
};

static struct TriNode* root = NULL;

static void InsertHelper (struct TriNode* node, int val)
{
  if (node->val == val) {
    if (!node->mid) {
      node->mid = (struct TriNode*) calloc (1, sizeof (struct TriNode) );
      node->mid->val = val;
    }
    else
      InsertHelper (node->mid, val);
  }
  else if (node->val > val) {
    if (!node->left) {
      node->left = (struct TriNode*) calloc (1, sizeof (struct TriNode) );
      node->left->val = val;
    }
    else
      InsertHelper (node->left, val);
  }
  else {
    if (!node->right) {
      node->right = (struct TriNode*) calloc (1, sizeof (struct TriNode) );
      node->right->val = val;
    }
    else
      InsertHelper (node->right, val);
  }
}

void Insert (int val)
{
  if (!root) {
    root = (struct TriNode*) calloc (1, sizeof (struct TriNode) );
    root->mid = (struct TriNode*) calloc (1, sizeof (struct TriNode) );
    root->mid->val = val;
  }
  else
    InsertHelper (root->mid, val);
}

static struct TriNode* FindBiggestChild (struct TriNode* node, struct TriNode** paren) {
  while (node->right) {
    *paren = node;
    node = node->right;
  }
  return node;
}

static void DeleteHelper (struct TriNode* node, struct TriNode* parent, int val)
{
  if (node->val == val) {
    /*
    here are four cases:
    1.if the node has mid node, then go down the mid one until finding the one without the mid child
    2.if the node has only two children, it could only the left and right, then swap the val with the in-order hightest child, and delete that child. NOTE that the could lead to unbalanced tree in the future, a simple remedy would be swaping with left and right tree's child alternatively
    3.if the node has one child, either left or right or mid, just delete the current node by pointing its parent directly at its child
    4.if the node has no child, just delete the current node by pointing its parent directly at NULL
    */
    //case 1
    if (node->mid)
      DeleteHelper (node->mid, node, val);
    //case 2
    else if (node->left && node->right) {
      //find the biggest child and its parent
      struct TriNode* p = node;
      struct TriNode* lchild = FindBiggestChild (node->left, &p);
      //swap the node and its child
      node->val = lchild->val;
      //now lchild has to have only 1 child
      DeleteHelper (lchild, p, lchild->val);
    }
    else {
      //3 ways it can be here through its parent
      struct TriNode** p;
      if (parent->left == node)
        p = &parent->left;
      else if (parent->right == node)
        p = &parent->right;
      else
        p = &parent->mid;
      //case 3
      if (node->left)
        *p = node->left;
      else if (node->right)
        *p = node->right;
      //case 4
      else
        *p = NULL;
      free (node);
    }
  }
  //search the right tree
  else if (node->val < val) {
    //if it is in the tree
    if (node->right)
      DeleteHelper (node->right, node, val);
  }
  //search the left tree
  else
    //if it is in the tree
    if (node->left)
      DeleteHelper (node->left, node, val);
}

void Delete (int val)
{
  if (root)
    DeleteHelper (root->mid, root, val);
}

void Print (struct TriNode* node)
{
  if (node->left)
    Print (node->left);
  if (node->mid)
    Print (node->mid);
  printf ("%d ", node->val);
  if (node->right)
    Print (node->right);
}

int main()
{
  int array[] = {5, 4, 9, 5, 7, 2, 2};
  int size = sizeof (array) / sizeof (int);
  if (size > 1) {
    int i;
    for (i = 0; i < size; i++)
      Insert (array[i]);
    Print (root);
    printf ("\n");
    for (i = 0; i < size; i++)
      Delete (array[i]);
    free (root);
  }
}
