#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <cassert>
#include <unordered_map>
/*
  adjacency matrix of a graph, assumption is that the graph consist of only caps letter nodes
*/

#define nChar 26

using namespace std;

enum Color {white, gray, black};

struct Node {
  char val;
  Color color;
  vector<Node> neighbor;
  Node();
  Node (char val);
};

//node -> its DF
typedef unordered_map<Node*, vector<Node*> > DFmap;

//node -> dominator
typedef unordered_map<Node*, vector<Node*> > DomMap;;

//node -> immediate dominator
typedef unordered_map<Node*, Node*> IdomMap;

class CharMap {
  char map[nChar];
 public:
  CharMap(){
    for(int i = 0; i < nChar; i++)
      map[i] = 0;
  }
  inline bool Find (char n) {
    if(!map[n - 'A']){
      map[n - 'A'] = 1;
      return false;
    }
    return true;
  }
};

class Graph {
  //the graph
  vector<Node> graph;
  //dfs tree of the graph
  vector<Node*> dfs;
  //store the dominator
  DomMap dom;
  //store the each closest dominator for each node
  IdomMap idom;
  //store the dominance frontier
  DFmap df;
  Node* FindInGraph (char c);
  void PrintNeighbor (const Node* nodes) ;
  void ComputeDFSHelper (Node* node,CharMap* map);
  bool isChild (const Node* c, const Node* p);
  //compute the dom map
  void ComputeDom ();
  //compute the idom map
  void ComputeIdom ();
  //compute dominance frontier
  void ComputeDF();
  //compute DF for each node
  vector<Node*> DF (Node* node);
  //compute DFS tree
  void ComputeDFS ();
  //get neighbors
  vector<Node>* getSuc (const Node* node);
  //set union
  void SetUnion (vector<Node*>* S, Node* node);
  //if n dominates m
  bool Dominate(Node* n, Node* m);
  //get predecessor of node
  vector<Node*> getPred(Node* node);

public:
  Graph (const char* file);
  ~Graph();
  void CreateGraph (const char* file);
  inline const DFmap* getDF() {
    return &df;
  }
};

ostream& operator << (ostream& os, const vector<Node>& graph);

#endif
