#include <iostream>
using namespace std;

void merge_tables(int table[], int left_index, int middle_index, int right_index){
    int i, j, result_list_index;

    int left_table_size = middle_index - left_index + 1;
    int right_table_size = right_index - middle_index;

    int left_table[left_table_size], right_table[right_table_size];

    for (i=0; i < left_table_size; i++)
    {
        left_table[i] = table[left_index+i];
    }
    for (j=0; j < right_table_size; j++)
    {
        right_table[j] = table[middle_index+1+j];
    }

    i = 0;
    j = 0;
    result_list_index = left_index;

    while (i<left_table_size and j<right_table_size)
    {
        if (left_table[i]<right_table[j])
        {
            table[result_list_index] = left_table[i];
            i++;

        } else{
            table[result_list_index] = right_table[j];
            j++;


        }
        result_list_index++;
    }
    while (i<left_table_size)
    {
        table[result_list_index] = left_table[i];
        i++;
        result_list_index++;
    }
    while (j<right_table_size)
    {
        table[result_list_index] = right_table[j];
        j++;
        result_list_index++;
    }
    

    
}

void merge_sort_from_the_bottom(int table[], int n){
    int middle_index, right_index;
    for (size_t size_of_table = 1; size_of_table < n; size_of_table = size_of_table * 2)
    {
        for (size_t left_index = 0; left_index < n-size_of_table; left_index = left_index + 2*size_of_table)
        {   
            if (left_index + size_of_table - 1 < n-1)
            {
                middle_index = left_index + size_of_table - 1;
            } else{
                middle_index = n-1;
            }
            if (left_index + 2*size_of_table - 1 < n-1)
            {
                right_index = left_index + 2*size_of_table - 1;
            } else{
                right_index = n-1;
            }
            
            merge_tables(table, left_index, middle_index, right_index);

        }
        
    }
    
    
    
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
    merge_sort_from_the_bottom(table, n);
    for (int i = 0; i < n; i++) {
        cout << table[i];
        if (i != n-1) cout << " ";
    }
}