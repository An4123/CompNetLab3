// Name: An Vo
// Date: 5/4/2020.
// Class: Intro To Computer Networking
// Assignment: Lab 3
//
// Comments:
// - Used https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/ to get a better
//   understanding of a MST.
#include "MinTree.h"
#include "Functions.h"

int main(/*string file*/){
    clock_t startTime = clock();                                    // Start clock
    string dummy, fileName = "test.txt";                                   // File Name
    int * arr = VerAndEdg(fileName);                               // go get Vertice and Edges
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    Graph* graph = createGraph(arr[0],arr[1]);     // Create Graph with V and E


    ifstream file;
    file.open(fileName);                                            // Open File
    getline(file, dummy);
    int i = 0;                                                            // Extract Numbers
    while(!file.eof()) {

        int s = 0, d = 0, c = 0;      // Source , Destination , Cost
        file >> s;              // Get Source
        file >> d;              // Get Destination
        file >> c;              // Get Cost

        if (d != 1073741824) {    //If there is a cost, add the edge
            graph->edge[i].src = s;             // Populate Edges
            graph->edge[i].dest = d;
            graph->edge[i].weight = c;
            i++;                                // Go to next edge
        }
    }
    file.close();                                           // Close File
    KruskalMST(graph, startTime);                           // Run MST algorithm

    return 0;
}