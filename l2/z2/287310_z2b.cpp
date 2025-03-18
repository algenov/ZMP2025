#include <iostream>

using namespace std;

int find_faster(int target_number, int row[], int len_of_row){
    int begin = 0;
    int end = len_of_row-1;
    while (begin<=end)
    {   
        int i = begin + (end-begin) / 2;
        if (target_number == row[i])
        {
            return i;
        }
        else if (target_number < row[i])
        {
            end = i-1;
        }
        else
        {
            begin = i+1;
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
    i = find_faster(target_number, row, len_of_row);
    if (i==-1)
    {
        cout << "nie";
    }
    else
    {
        cout << "tak " << i;
    }
}