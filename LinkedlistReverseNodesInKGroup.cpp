/*
  Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

  If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

  You may not alter the values in the nodes, only nodes itself may be changed.

  Only constant memory is allowed.

  For example,
  Given this linked list: 1->2->3->4->5

  For k = 2, you should return: 2->1->4->3->5

  For k = 3, you should return: 3->2->1->4->5

*/

#include <stack>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode (int x) : val (x), next (0) {}
};

/*
first implementation

ListNode* reverseKGroup (ListNode* head, int k)
{
  ListNode* p = head;
  ListNode* q = p;
  stack<int> st;
  while(1){
    int i = 0;
    for(; p && i < k; i++, p = p->next){
      st.push(p->val);
    }
    //the remainder is not reversed
    if(!p && i != k)
      break;
    while(!st.empty()){
      q->val = st.top();
      st.pop();
      q = q->next;
    }
  }
  return head;
}

*/


//second implementation

ListNode *reverseKGroup(ListNode *head, int k) {
        
}

int main()
{
}
