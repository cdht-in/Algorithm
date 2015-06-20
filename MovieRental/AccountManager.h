#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "Account.h"

/*
  this file manage those accounts in a linkedin structure
*/

//linkedlist node
struct AccountNode {
  //head of the linkedlist
  struct Account* account;
  //next
  struct AccountNode* next;
};

struct AccountManager {
  //account numbers
  uint32 size;
  //head
  struct AccountNode* head;
};

//constructor
static struct AccountNode* InitAccountNode();

//destructor
void DestAccountNode (struct AccountNode* node);

struct AccountManager* InitAccountManager (int n);

void DestAccountManager (struct AccountManager* manager);

//mark nth account delinquent
int MarkNode (struct AccountManager* manager, int n);

#endif
