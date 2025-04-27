#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "napisz liczbe elementow zbioru" << "\n";
    cin >> n;
    int table[n];
    cout << "napisz elementy zbiory przez enter" << "\n";
    for (size_t i = 0; i < n; i++)
    {
        cin >> table[i];
    }
    int max_dif = 0;
    for (size_t i = 0; i < n-1; i++)
    {
        for (size_t j = i; j < n; j++)
        {
            if (table[j]-table[i]>max_dif)
            {
                max_dif = table[j]-table[i];
            }
            
        }
        
    }
    cout << max_dif;
}