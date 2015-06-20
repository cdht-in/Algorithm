#include "Hash.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define Hash(addr) (addr & (q->hashsize - 1))

#define Tag(addr) ((TagMask & addr))

void setTagMask()
{
  int c = 0;
  int tmp = q->hashsize;
  while (tmp >>= 1) {
    c++;
  }
  int i;
  int tag = 0x0;
  for (i = c; i < sizeof (int) * 8; i++) {
    tag |= (0x01 << i);
  }
  TagMask = tag;
}

void Init (int n)
{
  //n has to be a power of 2
  assert (! ( (n) & (n - 1) ) );
  //init q
  q = (TwoQ*) malloc (sizeof (TwoQ) );
  q->sqc = n >> 1;
  q->sqs = 0;
  q->dqc = n >> 1;
  q->dqs = 0;
  //init single queue
  q->shead = (Node*) malloc (sizeof (Node) );
  q->stail = (Node*) malloc (sizeof (Node) );
  q->shead->n = q->stail;
  q->stail->p = q->shead;
  q->stail->n = NULL;
  //init double queue
  q->dhead = (Node*) malloc (sizeof (Node) );
  q->dtail = (Node*) malloc (sizeof (Node) );
  q->dhead->n = q->dtail;
  q->dtail->p = q->dhead;
  q->dtail->n = NULL;
  //init hash
  q->hashsize = n;
  q->hash = (HashNode*) malloc (n * sizeof (HashNode) );
  int i = 0;
  for (i = 0; i < n; i++) {
    q->hash[i].n = NULL;
  }
}

//find the block
HashNode* Find (int addr)
{
  int index = Hash (addr);
  HashNode* p = q->hash[index].n;
  while (p) {
    if (p->node->addr == addr)
      return p;
    p = p->n;
  }
  return NULL;
}

void Insert (int addr)
{
  HashNode* hashnode = Find (addr);
  if (hashnode) {
    hit++;
    //if it is in the multiple queue
    if (hashnode->f) {
      //put it to the head of the queue
      Node* p = FindNode (q->dhead, hashnode->node->addr);
      //remove the node
      Node* target = p->n;
      p->n = target->n;
      if (target->n)
        target->n->p = p;
      AddHead (q->dhead, target);
    }
    //in the single queue
    else {
      //remove the node from the single queue
      Node* p = FindNode (q->shead, hashnode->node->addr);
      Node* target = p->n;
      p->n = target->n;
      if (target->n)
        target->n->p = p;
      q->sqs--;
      //remove the mulitple queue tail if necessary
      if (q->dqs >= q->dqc) {
        Node* tail = RemoveTail (q->dtail);
        q->dqs--;
        //update the hashtable
        HashNode* p = FindHash (tail->addr);
        HashNode* hash = p->n;
        assert (p->n);
        p->n = hash->n;
        free (tail);
        free (hash);
      }
      //bump into the head the multiple queue
      AddHead (q->dhead, target);
      q->dqs++;
      hashnode->f = 1;
    }
  }
  else {
    //remove the single queue tail
    if (q->sqs >= q->sqc) {
      Node* tail = RemoveTail (q->stail);
      q->sqs--;
      //update the hashtable
      HashNode* p = FindHash (tail->addr);
      HashNode* hash = p->n;
      p->n = hash->n;
      free (tail);
      free (hash);
    }
    //add to the single queue
    Node* node = (Node*) malloc (sizeof (Node) );
    node->addr = addr;
    q->sqs++;
    AddHead (q->shead, node);
    //update the hashtable
    HashNode* hashnode = (HashNode*) malloc (sizeof (HashNode) );
    hashnode->f = 0;
    hashnode->node = node;
    AddHash (hashnode, addr);
  }
}

void AddHead (Node* head, Node* node)
{
  //insert in the head
  Node* tmp = head->n;
  head->n = node;
  node->p = head;
  node->n = tmp;
  tmp->p = node;
}

void AddHash (HashNode* hashnode, int addr)
{
  int index = Hash (addr);
  HashNode* p = q->hash + index;
  while (p->n) {
    p = p->n;
  }
  p->n = hashnode;
  hashnode->n = NULL;
}

Node* RemoveTail (Node* tail)
{
  Node* tmp = tail->p->p;
  Node* target = tail->p;
  if(tmp)
    tmp->n = tail;
  tail->p = tmp;
  return target;
}

HashNode* FindHash (int addr)
{
  int index = Hash (addr);
  HashNode* p = q->hash + index;
  while (p->n && p->n->node->addr != addr ) {
    p = p->n;
  }
  return p;
}

Node* FindNode (Node* head, int addr)
{
  Node* p = head;
  while (p->n && p->n->addr != addr ) {
    p = p->n;
  }
  return p;
}







