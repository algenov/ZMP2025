#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x, y, z;
    x = 1;
    y = 1;
    z = 0;
    for (size_t i = 0; i < n; i++)
    {
        cout << x << " ";
        x = y + z;
        z = y;
        y = x;
    }
    
}