#include "MinTree.h"


int* VerAndEdg(string fileName){
    // return the value of the vertices, and count how many edges there are
    ifstream File;
    string line;

    File.open(fileName);
    int ed = 0, ver = 0;
    File >> ver;                         // Get the vertices
    while(!File.eof()){                 // while not end of file
        File.ignore();                  // Ignore first line.
        getline(File,line);
        ed++;                        // get count for how many edges
    }
    File.close();                       // Close file
    static int _arr[2] = {ver, ed};
    return _arr;
}