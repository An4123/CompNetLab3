#include <iostream>
#include <ifstream>
#include <string>
using namespace std;


void takeInput(string file){
  file.open(file);
  cout << "File is Open" << endl;
  file.close()

}

int int main(int argc, char const *argv[]) {
  cout << "Start Main \n" << endl;
  takeInput("text.txt")
  cout << "\nEnd Main" << endl;
  
  return 0;
}
