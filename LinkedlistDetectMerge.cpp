/*
  detect if two list merge somewhere and the merge portion length
*/

#include <cstdio>
#include <unordered_set>

struct Node {
  int val;
  Node* next;
  Node() : val(), next (0) {}
  Node (int val) : val (val), next() {}
};

struct SinglyLinkedlist {
  int size;
  Node* head;
  Node* insertPtr;

  SinglyLinkedlist() : size(), head (new Node() ), insertPtr (head) {}

  void Push (int val) {
    insertPtr->next = new Node (val);
    insertPtr = insertPtr->next;
    size++;
  }

  void PrintList() {
    //get the first element
    Node* node = head->next;
    while (node != 0) {
      printf ("%d ", node->val);
      node = node->next;
    }
    printf ("\n");
  }

  inline Node* getHead() {
    if (size > 0)
      return head->next;
  }
};

static void PrintList (Node* n)
{
  while (n != 0) {
    printf ("%d ", n->val);
    n = n->next;
  }
  printf ("\n");
}

//if two linked merge somewhere, they would end up in a same place in the end
static bool DetectMergeI (Node* n1, Node* n2)
{
  Node* n1p = n1;
  Node* n2p = n2;
  //NOTE to test the last elements instead of the 0 passing the last one
  while (n1p->next != 0) {
    n1p = n1p->next;
  }
  while (n2p->next != 0) {
    n2p = n2p->next;
  }
  //they point to the same position in the end
  if (n1p == n2p)
    return true;
  return false;
}

//detect the merged node of two lists, Reason why it works, two pointers move at the same speed, if they have the same distance to the merge point, they would meet at it. if the distance to the merged point are different, the shorter distance pointer is going to going to arrive the end first then is swapped to the longer distance head, e.g it reduces its speeds to reach to the merged point in the next round. On the other hands, the longer distance pointer would gain speed by swapping to the shorter distance list. Eventually, they would have the same speed and meet at the merged point at some point in the future
static Node* DetectMergeII (Node* n1, Node* n2)
{
  //this function only needs to be called after it assured that there are merged list, otherwise it would loop forever.
  Node* n1p = n1;
  Node* n2p = n2;
  while(1){
    //if hiting the end, point to the head of the other list
    if(n1p->next != 0)
      n1p = n1p->next;
    else
      n1p = n2;
    //if they meet, they meet at the merged point
    if(n1p == n2p)
      break;
    if(n2p->next != 0)
      n2p = n2p->next;
    else
      n2p = n1;
    if(n1p == n2p)
      break;
  }
  return n1p;
}

//detect the merge portion length without modifying the list, O(n) time, O(n) space
static int MergeLengthI (Node* n1, Node* n2)
{
  std::unordered_set<Node*> set;
  Node* n1p = n1;
  Node* n2p = n2;
  //first populate the hashtable with the first list
  while (n1p!= 0) {
    set.insert(n1p);
    n1p = n1p->next;
  }
  int len = 0;
  while (n2p!= 0) {
    //the first node in the hashtable is the starting point of the merged portion
    if(set.find(n2p) != set.end())
      len++;
    n2p = n2p->next;
  }
  return len;
}

//idea is that starting from one node, traverse to the end and reverse the pointer along the way, this requires O(n) time and O(1) space

int main()
{
  Node l1 (1);
  Node l2 (2);
  Node l3 (3);
  Node l4 (4);
  Node l5 (5);
  l1.next = &l2;
  l2.next = &l3;
  l3.next = &l4;
  l4.next = &l5;
  Node s1 (6);
  // s1.next = &l2;
  PrintList (&l1);
  PrintList (&s1);
  //printf ("%d\n", DetectMerge (&l1, &s1) );
  Node* p = DetectMergeII(&l1,&s1);
  printf("merged at %d\n",p->val);
  //printf("merged leng is %d\n",MergeLengthII(&l1,&s1));
}
