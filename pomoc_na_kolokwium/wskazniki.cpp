#include <iostream>

using namespace std;

int main(int argc, char** argv){
  int i=0;
  cout << argc << "\n";
  while (i<argc){
    while (**argv!='\0'){
      cout << **argv;
      ++(*argv);
    }
    cout << " ";
    ++(argv);
    i++;
  }
  return 0;
}