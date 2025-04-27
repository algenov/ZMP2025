#include <iostream>
using namespace std;

int main(){
    int n, result;
    
    cout << "napisz liczbe elementow zbioru" << "\n";
    cin >> n;
    int tab[n];
    result = 0;
    cout << "napisz elementy zbiory przez enter" << "\n";
    for (size_t i = 0; i < n; i++)
    {
        cin >> tab[i];
    }
    for (size_t i = 0; i < n-1; i++)
    {
        for (size_t j = i+1; j < n; j++)
        {
            if (tab[i] > tab[j])
            {
                result++;
            }
            
        }
        
    }
    cout<<result;

}