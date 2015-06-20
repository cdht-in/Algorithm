#include "Graph.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

Node::Node() : val() {}

Node::Node (char val) : val (val), color (white) {}

Graph::Graph (const char* file)
{
  CreateGraph (file);
  cout << graph << endl;
  //init DFS tree
  ComputeDFS();
  cout << "dfs is :";
  for (int i = 0; i < dfs.size(); i++) {
    cout << dfs[i]->val << " ";
  }
  cout << endl;
  //init Idom map
  ComputeIdom();
  //init dom map
  ComputeDom();
  for (auto i = idom.begin(); i != idom.end(); i++) {
    cout << i->first->val << "'s idom is " << i->second->val << endl;
  }
  for (auto i = dom.begin(); i != dom.end(); i++) {
    cout << i->first->val << "'s dom are ";
    for (int j = 0; j < i->second.size(); j++) {
      cout << ( (i->second) [j])->val << " ";
    }
    cout << endl;
  }
  ComputeDF();
}

Graph::~Graph(){}

vector<Node*> Graph::DF (Node* node)
{
  vector<Node*> s;
  vector<Node>* suc = getSuc (node);
  vector<Node*> w;
  //DFlocal(node)
  for (int j = 0; j < suc->size(); j++) {
    Node* n = FindInGraph ( (*suc) [j].val);
    if (idom[n]->val != node->val) {
      //S U node
      SetUnion (&s, n);
    }
  }
  //get all y that idom(y) == node
  for (int i = 0; i < graph.size(); i++) {
    if (idom[&graph[i]]->val == node->val ) {
      w.push_back (&graph[i]);
    }
  }
  //DFup(y)
  /*
  for (int i = 0; i < w.size(); i++) {
    //DFup(node)
    vector<Node*> df = getPred (w[i]);
    for (int j = 0; j < df.size(); j++) {
      //if node doesn't dominate j or x == j
      if (Dominate (node, df[j]) || node->val == df[j]->val)
        SetUnion (&s, df[j]);
    }
    }*/
  return s;
}

//NOTE the getPred needs to be worked on for the DFup(y) to work
vector<Node*> getPred (Node* node)
{
  vector<Node*> vec;
  return vec;
}


bool Graph::Dominate (Node* n, Node* m)
{
  vector<Node*> vec = dom[m];
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i]->val == n->val)
      return true;
  }
  return false;
}

void Graph::SetUnion (vector<Node*>* S, Node* node)
{
  for (int i = 0; i < S->size(); i++) {
    if ( (*S) [i]->val == node->val)
      return;
  }
  (*S).push_back (node);
}

void Graph::ComputeDom ()
{
  //init dom map
  for (int i = 0; i < graph.size(); i++) {
    Node* n = &graph[i];
    dom[n] = vector<Node*>();
    Node* m = idom[n];
    //walk up the idom chain
    if (m == n) {
      dom[n].push_back (n);
    }
    else {
      while (m != n) {
        dom[&graph[i]].push_back (m);
        n = m;
        m = idom[n];
      }
    }
  }
}

void Graph::ComputeDF()
{
  //init DF map
  for (int i = 0; i < graph.size(); i++) {
    df[&graph[i]] = vector<Node*>();
  }
  for (int i = 0; i < graph.size(); i++) {
    DF (&graph[i]);
  }
}

void Graph::CreateGraph (const char* file)
{
  string line;
  ifstream myfile (file);
  if (myfile.is_open() ) {
    while ( getline (myfile, line) ) {
      //linear search for now
      Node* n1 = FindInGraph (line[0]);
      Node* n2 = FindInGraph (line[2]);
      //if i an j are greater than 0, found
      if (!n1) {
        if (!n2) {
          Node node1 (line[0]);
          Node node2 (line[2]);
          node1.neighbor.push_back (node2);
          graph.push_back (node1);
          graph.push_back (node2);
        }
        else {
          Node node1 (line[0]);
          node1.neighbor.push_back (*n2);
          graph.push_back (node1);
        }
      }
      else {
        if (!n2) {
          Node node2 (line[2]);
          //note the the stl vector would reloacte its content automatically such that pointer address could be changed
          n1->neighbor.push_back (node2);
          graph.push_back (node2);
        }
        //both edges are presented
        else {
          if (!isChild (n2, n1) )
            n1->neighbor.push_back (*n2);
        }
      }
    }
    myfile.close();
  }
}

void Graph::PrintNeighbor (const Node* nodes)
{
  for (int i = 0; i < nodes->neighbor.size(); i++)
    cout << nodes->neighbor[i].val << " ";
  cout << endl;
}

Node* Graph::FindInGraph (char c)
{
  for (int i = 0; i < graph.size(); i++) {
    if (graph[i].val == c) {
      return &graph[i];
    }
  }
  return 0;
}

void Graph::ComputeDFSHelper (Node* node, CharMap* map)
{
  for (int i = node->neighbor.size() - 1; i >= 0; i--) {
    //NOTE that the pointer that is stored in the vector is now the same as in the graph
    Node* n = FindInGraph (node->neighbor[i].val);
    ComputeDFSHelper (n, map);
  }
  if (!map->Find (node->val) )
    dfs.push_back (node);
}

void Graph::ComputeDFS ()
{
  static CharMap map;
  ComputeDFSHelper (&graph[0], &map);
}

void Graph::ComputeIdom ()
{
  if (dfs.size() <= 1) {
    idom[dfs[0]] = 0;
  }
  else {
    //first one that dominate all of its predeccessor
    int p = 0;
    for (int i = 0; i < dfs.size(); i++) {
      for (int j = i + 1; j < dfs.size(); j++) {
        bool f = true;
        for (int k = i; k < j; k++) {
          if (!isChild (dfs[k], dfs[j]) ) {
            f = false;
            break;
          }
        }
        if (f) {
          //first one
          p = j;
        }
      }
      //store the idom
      idom[dfs[i]] = dfs[p];
    }
  }
}

vector<Node>* Graph::getSuc (const Node* node)
{
  //linear search
  for (int i = 0; i < graph.size(); i++) {
    if (graph[i].val == node->val) {
      return &graph[i].neighbor;
    }
  }
  return 0;
}

bool Graph::isChild (const Node* c, const Node* p)
{
  for (int i = 0; i < p->neighbor.size(); i++) {
    if (p->neighbor[i].val == c->val)
      return true;
  }
  return false;
}
ostream& operator << (ostream& os, const vector<Node>& graph)
{
  for (int i = 0; i < graph.size(); i++) {
    os << graph[i].val << " -> ";
    for (int j = 0; j < graph[i].neighbor.size(); j++) {
      os << graph[i].neighbor[j].val << " ";
    }
    os << endl;
  }
  return os;
}
