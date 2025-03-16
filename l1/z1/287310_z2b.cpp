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

int fi(int n){
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
    return counter;
}
int main() {
    int n; 
    cin >> n;
    int sum;
    sum = 0;
    int counter;
    counter = 1;
    while (counter <= n)
    {
        if (n%counter == 0)
        {
            sum = sum + fi(counter);
        }
        counter = counter + 1;
    }
    cout << sum;
    return 0;
}