#include <iostream>
using namespace std;




void binary(int n, int i, bool tab_true_false[]){

    
    int k=1;
    while (k <= n)
    {
        if (i%2==1)
        {
            tab_true_false[n-k] = true;
        }else{
            tab_true_false[n-k] = false;
        }
        
        i = i / 2;
        k = k+1;
    }
    
}

void subset(int n, bool tab_true_false[], int tab[]){
    int m=1;
    for (size_t i = 0; i < n; i++)
    {
        m = m * 2;

    }
    cout << "empty";
    for (size_t l=0; l < m; l++)
    {
        binary(n, l, tab_true_false);
        for (size_t j = 0; j < n; j++)
        {
            if (tab_true_false[j]==true)
            {
                cout << tab[j] << " ";
            }
            
            
        }
        cout << "\n";
    }
    
}

int make_unique_table(int unique_tab[], int tab[], int n){
    int m, l, i, j;
    bool unique;

    l = 0;
    m = n;
    for (i = 0; i < m; i++)
    {
        unique=true;
        for (j = i+1; j < m; j++)
        {
            if (tab[i] == tab[j])
            {
                unique = false;
                break;
            }
            
        }
        if (unique==true)
        {
            unique_tab[l] = tab[i];
            l++;
        }else{
            n = n -1;
        }
        
        
    }

    return n;

}


int main(){
    int n;
    cout << "napisz liczbe elementow zbioru" << "\n";
    cin >> n;
    int tab[n];
    int unique_tab[n];
    bool tab_true_false[n];
    
    
    cout << "napisz elementy zbiory przez enter" << "\n";
    for (size_t i = 0; i < n; i++)
    {
        cin >> tab[i];
    }
    
    n = make_unique_table(unique_tab, tab, n);
    
    subset(n, tab_true_false, unique_tab);

}