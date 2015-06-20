#include "AccountManager.h"
#include <stdlib.h>
#include <stdio.h>

struct AccountNode* InitAccountNode() {
  struct AccountNode* node = (struct AccountNode*) malloc (sizeof (struct AccountNode) );
  node->account = NULL;
  node->next = NULL;
}

void DestAccountNode (struct AccountNode* node)
{
  if (node != NULL) {
    DestAccount (node->account);
    free (node);
  }
}

struct AccountManager* InitAccountManager (int n) {
  struct AccountManager* manager = (struct AccountManager*) malloc (sizeof (struct AccountManager) );
  manager->size = n;
  manager->head = InitAccountNode();
  //now store n accounts
  int i;
  for (i = 0; i < n; i++) {
    struct AccountNode* node = InitAccountNode();
    //init the account to be 10 instances of cong hui
    node->account = InitAccount ("hui", "cong", 2);
    node->next = manager->head->next;
    manager->head->next = node;
  }
  return manager;
}

void DestAccountManager (struct AccountManager* manager)
{
  if (manager != NULL) {
    if (manager->size > 0) {
      struct AccountNode* p1 = manager->head;
      struct AccountNode* p2 = p1->next;
      for (; p2 != NULL;) {
	printf("sadsad\n");
        DestAccountNode (p1);
        p1 = p2;
	p2 = p2->next;
        manager->size--;
      }
      //delete the last one
      DestAccountNode(p2);
    }
    free (manager);
  }
}

int MarkNode (struct AccountManager* manager, int n)
{
  //check if there are n instances
  if (n < 0 || n > manager->size) {
    printf ("invalid n\n");
    return -1;
  }
  struct AccountNode* node = manager->head;
  int i;
  for (i = 0; node != NULL && i < n; i++, node = node->next);
  //turn on the delinquent bit
  node->account->flag.delinquent = 1;
  return 1;
}

int main (void)
{
  //create 10 instance
  struct AccountManager* manager = InitAccountManager (10);
  //mark the third 3 delinquent
  MarkNode (manager, 3);
  DestAccountManager(manager);
  return 0;
}
