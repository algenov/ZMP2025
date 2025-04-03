#include <iostream>
using namespace std;

void func(int x, int y, int z, int n, int i){
    
    if (i<n)
    {
        cout << x << " ";
        x = y + z;
        z = y;
        y = x;
        i++;
        func(x,y,z,n,i);
    }
    
}
int main() {
    int n, x, y, z, i;
    i = 0;
    z = 0;
    x = 1;
    y = 1;
    cin >> n;
    func(x,y, z,n, i);
}