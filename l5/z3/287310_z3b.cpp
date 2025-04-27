#include <iostream>
using namespace std;

int max(int a, int b){
    if (a<b)
    {
        return(b);
    } else{
        return(a);
    }
    
}


int find_diff(int table[], int left_index, int right_index){
    if (left_index == right_index)
    {
        return 0;
    }

    int middle_index = (left_index+right_index)/2;

    int max_dif_for_left_side = find_diff(table, left_index, middle_index);
    int max_dif_for_right_side = find_diff(table, middle_index+1, right_index);
    
    int min_in_left = table[left_index];
    for (size_t i = left_index+1; i <= middle_index; i++)
    {
        if (table[i]<min_in_left)
        {
            min_in_left = table[i];
        }
    }

    int max_in_right = table[middle_index+1];
    for (size_t i = middle_index+2; i <= right_index; i++)
    {
        if (table[i] > max_in_right)
        {
            max_in_right = table[i];
        }   
    }
    
    int max_dif = max_in_right - min_in_left;
    
    return(max(max(max_dif, max_dif_for_left_side),max(max_dif, max_dif_for_right_side)));
}

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
    int max_dif;
    max_dif = find_diff(table, 0,n-1);
    cout << max_dif;
}