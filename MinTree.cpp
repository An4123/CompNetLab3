// Name: An Vo
// Date: 5/4/2020.
// Class: Intro To Computer Networking
// Assignment: Lab 3
//
// Comments:
// - Used https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/ to get a better
//   understanding of a MST.
#include <algorithm>
#include "MinTree.h"
void printEdges(Graph* graph){
    for(int i = 0; i < graph->E; i++){
        cout << graph->edge[i].src << " " << graph->edge[i].dest << " " << graph->edge[i].weight << endl;
    }
}

Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];

    return graph;
}

int find(subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}
void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void* a, const void* b)
{
    const Edge* a1 = (const Edge*)a;
    const Edge* b1 = (const Edge*)b;
    return (a1->weight > b1->weight);
}

int totalCost(Edge res[], int _i, int _e){
    int totalCost = 0 ;
    for (_i = 0; _i < _e; ++_i) {
        totalCost += res[_i].weight;
    }
    return totalCost;
}

void printTree(Edge res[], int _i, int _e){
    for (_i = 0; _i < _e; ++_i) {
        cout << res[_i].src << " -- " << res[_i].dest << " == " << res[_i].weight << endl;
    }
    cout << endl;
}

void KruskalMST(Graph* graph, clock_t _startTime)
{
    int V = graph->V;
    Edge result[V]; // Tnis will store the resultant MST
    int e = 0; // An index variable, used for result[]
    int i = 0; // An index variable, used for sorted edges

    cout << "Before Sort" << endl;
    printEdges(graph);
    qsort(graph->edge, graph->E , sizeof(graph->edge[0]), myComp);
    cout << "After Sort" << endl;
    printEdges(graph);
    subset *subsets = new subset[( V * sizeof(subset) )];

    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }


    while (e < V - 1  && i < graph->E)
    {
        Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    double totalTime = double(clock() - _startTime) / double(CLOCKS_PER_SEC);

    cout << "Total Execution Time: " << fixed << totalTime << setprecision(100) <<  endl;
    cout << "Minimum Cost: " << totalCost(result, i , e) << endl;
    cout << "Minimum Spanning Tree: \n";
    printTree(result, i, e);


    return;
}