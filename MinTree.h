// Name: An Vo
// Date: 5/4/2020.
// Class: Intro To Computer Networking
// Assignment: Lab 3
//
// Comments:
// - Used https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/ to get a better
//   understanding of a MST.
#ifndef UNTITLED_MINTREE_H
#define UNTITLED_MINTREE_H
#include <iomanip>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <string>
using namespace std;

class Edge
{
public:
    int weight, src, dest;
};

class Graph
{
public:
    int V, E;
    Edge* edge;
};

class subset
{
public:
    int parent;
    int rank;
};

Graph* createGraph(int Vertices, int Edges);
int find(subset subsets[], int i);
void Union(subset subsets[], int x, int y);
int MyComp(const void* a, const void* b);
void KruskalMST(Graph* graph, clock_t _startTime);
int totalCost(Edge res[], int _i, int _e);
void printTree(Edge res[], int _i, int _e);
#endif
