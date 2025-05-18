#include <iostream>
using namespace std;

struct node {
    int value;
    node* next;
};

void add_el(node* &first, int val){
    node* newnode = new node{val, nullptr};
    if (first == nullptr)
    {
        first = newnode;
        return;
    }
    node* time_ptr = first;

    while ((*time_ptr).next)
    {
        time_ptr=(*time_ptr).next;
    }
    (*time_ptr).next = newnode;
}

void sort(node* first){
    int replaced = 1;
    while (replaced == 1)
    {
        replaced = 0;
        node* time_ptr = first;
        while ((*time_ptr).next != nullptr)
        {
            if ((*time_ptr).value > (*(*time_ptr).next).value)
            {
                swap((*time_ptr).value, (*(*time_ptr).next).value);
                replaced = 1;
            }
            time_ptr = (*time_ptr).next;
        }
         
    }
    
}

int main(){
    int n, a;
    cin >> n;
    node* first = nullptr;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a;
        add_el(first, a);
    }
    
    sort(first);
    while (first)
    {
        cout << (*first).value;
        first = (*first).next;
    }
    
}