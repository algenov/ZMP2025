#include <iostream>
using namespace std;


int nwd(int num1, int num2){
    int counter;
    counter = 1;
    int nwd;
    nwd = 1;
    while (counter <= num1)
    {
        counter = counter + 1;
        if (num1 % counter == 0)
        {
            if (num2 % counter == 0)
            {
                nwd = counter;
            }
            
        }
        
    }
    return nwd;
    
}
int main() {
    int n; //liczba do funkcji
    cin >> n;
    int k; 
    int j;
    k = 1;
    int counter;
    counter = 0;
    while (k <= n) 
    {

        if (nwd(k, n) == 1)
        {
            counter = counter + 1;
        }
        
        
        k = k + 1;
    }
    cout << counter;
    return 0;
}