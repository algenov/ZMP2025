#include <iostream>

using namespace std;

void make_bytes(int byte_1[], int byte_2[]){
    int i;
    int el;
    
    for (i = 0; i < 16; i++)
    {
        cin >> el;
        if (el!=0 and el!=1)
        {
            cout << "prosze zapisac jeszcze raz uzywajac 0 oraz 1" << "\n";
            make_bytes(byte_1, byte_2);
            break;
        }
        
        if (i<=7)
        {
            byte_1[i] = el;
        }
        else
        {
            byte_2[i-8] = el;
        }
        
    }
}

int main(){

    int result_byte[8];
    int i;
    int byte_1[8];
    int byte_2[8];
    make_bytes(byte_1, byte_2);
    for (i = 0; i < 8; i++)
    {
        if (byte_1[i] == byte_2[i])
        {
            result_byte[i] = 0;
        }
        else
        {
            result_byte[i] = 1;
        }
        
    }
    for ( i = 0; i < 8; i++)
    {
        cout << result_byte[i] << " ";
    }
    
    
}