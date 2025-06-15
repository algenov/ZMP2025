#include <iostream>
#include <string>

using namespace std;

template <typename T, typename U>
class my_pair {
private:
  T fst;
  U snd;
public:
  my_pair(T x, U y) : fst(x), snd(y) {}
  void show() {
    cout << "(" << fst << ", " << snd << ")\n";
  }
};

template <template <typename, typename> class PairType, typename A, typename B>
class PairWrapper {
  private:
    PairType<A, B> pair;
  public:
    PairWrapper(A a, B b) : pair(a, b) {}
    void display() {
      pair.show();
    }
  };

int main() {
  PairWrapper<my_pair, int, float> p(42, 3.14);
  p.display();
  return 0;
}