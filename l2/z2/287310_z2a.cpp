#include <iostream>

using namespace std;

int find(int target_number, int row[], int len_of_row){
    int i;
    for(i=0; i<len_of_row; i=i+1){
        if (row[i]==target_number)
        {
            return i;
        }
        
    }
    return -1;
}

int main(){
    int target_number;
    int len_of_row;
    cin >> target_number;
    cin >> len_of_row;
    int row[len_of_row];
    int i;
    for(i = 0; i<len_of_row; i=i+1){
        cin >> row[i];
        }
    i = find(target_number, row, len_of_row);
    if (i==-1)
    {
        cout << "nie";
    }
    else
    {
        cout << "tak " << i;
    }
    
}