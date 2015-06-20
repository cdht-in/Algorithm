#ifndef HASH_H
#define HASH_H

/*
 2q cache implementation
*/

typedef struct Node Node;
typedef struct TwoQ TwoQ;
typedef struct HashNode HashNode;

struct Node {
  Node* n;
  Node* p;
  int addr;
};

//f == 0 indicate the node is in the single queue,
//f == 1 in the double queue otherwise
struct HashNode {
  Node* node;
  HashNode* n;
  int f;
};

struct TwoQ {
  unsigned int sqs;
  unsigned int sqc;
  unsigned int dqs;
  unsigned int dqc;
  Node* shead;
  Node* stail;
  Node* dhead;
  Node* dtail;
  HashNode* hash;
  unsigned int hashsize;
};

static TwoQ* q;

unsigned int hit;

static int Tag (int addr);

void init (int n);

static HashNode* Find (int addr);

static void AddHead(Node* head,Node* node);

static Node* RemoveTail(Node* tail);

static void AddHash(HashNode* hashnode,int addr);

static HashNode* FindHash(int addr);

static Node* FindNode(Node* head,int addr);

static int TagMask;

static void setTagMask();

void Insert (int addr);

#endif
