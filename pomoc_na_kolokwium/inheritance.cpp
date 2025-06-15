#include <iostream>

using namespace std;

class A {
  private:
    int priv_data;
    //A() {}
  protected:
    int prot_data;
    //A() {}
  public:
    int pub_data;
    //A() {
    //  cout << "wezwany konstruktor A!\n";
    //} // Jawnie napisany domyĹlny konstruktor, by nie zostaĹ wyeliminowany przeciÄĹźeniami
    A(int n, int k, int i){
      priv_data=n;
      prot_data=k;
      pub_data=i;
    }
    void show(){
      cout << priv_data << " " << prot_data << " " << pub_data << "\n";
    }
    void set_priv(int n){
      priv_data=n;
    }
    
};

class B: private A {
  public:
    B(int n, int k, int i) : A(n,k,i) { // istotne! W liĹcie inicjalizacyjnej to jedyne miejsce, gdzie moĹźna wywoĹaÄ explicite konstruktor klasy bazowej
      cout << "wezwany konstruktor B!\n";
      //priv_data=n; // error, brak dostÄpu
      set_priv(n); // poprawne, odwoĹuje siÄ do metody A, ktĂłra ma dostÄp do prywatnych pĂłl
      prot_data=k;
      pub_data=i;
    }
  void showB(){
    //cout << priv_data << " " << prot_data << " " << pub_data << "\n"; // error, brak dostÄpu
    cout << prot_data << " " << pub_data << "\n";
  }
};

int main(){
  B obj(1,2,3);
  //cout << obj.prot_data << "\n";
//   cout << obj.pub_data << "\n";
  obj.showB();
  return 0;
}