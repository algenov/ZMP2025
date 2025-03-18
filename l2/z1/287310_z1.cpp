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




int main(){
int n;
cin >> n;
int tablica[n];
int i;
int k;
int tablica2[n];
for(i = 0; i<n; i=i+1){
cin >> k;
tablica[i] = k;
}
int l;
l = nwd(tablica[0], tablica[1]);
for (i=1;i<n-1;i++){
l = nwd(l, tablica[i+1]);
}
cout << l;

return 0;
}