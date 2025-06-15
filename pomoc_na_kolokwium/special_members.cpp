#include <iostream>

using namespace std;

class Tablica {
  int* arr;
  int size;
  
  public:
    Tablica(){
      cout << "Konstruktor zwykĹy wezwany!\n";
      size=0;
      arr = nullptr;
    }
    Tablica(int n) {
      cout << "Konstruktor zwykĹy wezwany!\n";
      size = n;
      arr = new int[n];
    }
    ~Tablica() {
      cout << "Zwalniam pamiÄÄ!\n";
      delete[] arr;
    }
    
    Tablica(const Tablica& other) {
      cout << "Copy constructor wezwany!\n";
      size = other.size;
      arr = new int[size];
      for (int i = 0; i < size; ++i) {
        arr[i] = other.arr[i];
      }
    }
    
    Tablica& operator= (const Tablica& other) {
      cout << "Copy assignment wezwane!\n";
      if (this != &other) {
        delete[] arr;
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
          arr[i] = other.arr[i];
        }
        
      }
      return *this;
    }
    
    Tablica(Tablica&& other) {
      cout << "Move constructor wezwany!\n";
      size = other.size;
      arr = other.arr;
      other.arr = nullptr;
      other.size = 0;  
    }

    Tablica& operator=(Tablica&& other) {
      cout << "Move assignment wezwane!\n";
      if (this != &other) {
        delete[] arr;
        arr = other.arr;
        size = other.size;
        other.arr = nullptr;
        other.size = 0;
        //other.~Tablica(); // Niezdefiniowane zachowanie, nie niszczymy przenoszonych obiektĂłw.
      }
      return *this;
    }
    
    int& operator [](int n) const {
      return arr[n];
    }
    friend ostream & operator << (ostream &output, const Tablica& tab) { 
      if (tab.size==0){
        output << "empty!\n";
      }
      else {
        output << "[";
        int n=0;
        while (n<tab.size-1){
          output << tab[n] << ", ";
          ++n;
        }
        output << tab[tab.size-1];
        output << "]\n";
      }
      return output;            
    }
    void print_addresses(){
      int i=0;
      while (i<size){
        cout << &(arr[i]) << " ";
        ++i;
      }
      cout << "\n";
    }
    bool is_it_me(Tablica& other){
      return (this==&other);
    }
};

Tablica clone_val(Tablica tab){
  return tab;
}

Tablica& clone_ref(Tablica& tab){
  return tab;
}

Tablica dummy_create(){
  Tablica tab;
  return tab;
}

int main(){
  cout << "tab1:\n";
  Tablica tab1(5);
  cout << "\n";
  int i=0;
  while (i<5){
    tab1[i]=i;
    i++;
  }
  
  cout << "tab2:\n";
  Tablica tab2(7);
  tab2=tab1;
  
  cout << "\n";
  cout << "tab3:\n";
  Tablica tab3(0);
  tab3=clone_ref(tab1);
  
  cout << "\n";
  cout << "tab4:\n";
  Tablica tab4(0);
  tab4=clone_val(tab1);
  
  cout << "\n";
  cout << "tab5:\n";
  Tablica tab5(tab1);
  
  cout << "\n";
  cout << "tab6:\n";
  Tablica tab6(clone_val(tab1));
  cout << "\n";
  
  cout << "\n";
  cout << "tab7:\n";
  Tablica tab7(dummy_create()); // MĂłgĹby zadziaĹaÄ move constructor, ale kompilator moĹźe zoptymalizowaÄ.
  cout << "\n";
  
  return 0;
}