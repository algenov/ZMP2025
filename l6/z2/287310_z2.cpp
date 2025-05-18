//niestety jeszcze nie skonczylem program do konca ale wysyłam w takiej postaci, bo juz sa funkcje 1,3 i 5 z listy. jeszcze nie robilem tego ladnego wprowadzenia danych przez cin, bo na razie wszystko testuje i o wiele wygodniej to robic bez tego wprowadzenia
#include <iostream>
#include <cmath>
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


struct node_tree {
    int value;
    node_tree* left;
    node_tree* right;
    node_tree(int v) : value(v), left(nullptr) {}
};

node_tree* build_tree(int table[], int size){  //robie drzewo
    node_tree* start = new node_tree(table[size-1]);  //najpierw pierwszy node
    node_tree* indexes[size];  //ta tablica zrobiona zeby potem szukac rodzica node'a i zmieniac go left lub right
    int parent_index;
    indexes[0] = start;
    for (size_t i = 1; i < size; i++)  //potem w zaleznosci od parzystosci value sie dodaje do left lub do right
    {
        parent_index = (i-1)/2;
        if (i%2==1)
        {
            indexes[i] = new node_tree(table[size-i-1]);
            (*indexes[parent_index]).left = indexes[i];
        } else
        {
            indexes[i] = new node_tree(table[size-i-1]);
            (*indexes[parent_index]).right = indexes[i];
        }
            
    }
    return start;
}

int height_tree(node_tree* start, int height){  //licze wysokosc drzewa, dlatego ze zawsze najwiecej elementow bedzie w lewej czesci to mozna zrobic w taki prosty sposob
    height = height+1;
    if ((*start).left!=nullptr)
    {
        height = height_tree((*start).left, height);
    }
    return height;
}



void prepare_for_showing(node_tree* start, node* table_levels[], int n, int place, int height){
    
    add_el(table_levels[n], (*start).value);  //tu robie z kazdego pozioma drzewa strukture, zeby potem ladnie wypisywac

    if ((*start).left!=nullptr)
    {
        n = n + 1;  //n odpowiada numeru pozioma
        prepare_for_showing((*start).left, table_levels, n, place, height);
        
    }
    if ((*start).right!=nullptr)
    {
        prepare_for_showing((*start).right, table_levels, n, place, height);
    }
    
    


    
    
}

int length_of_number(int number){  //szuka dlugosc liczby
    int i, n;
    i = 1;
    n = 0;
    while (number/i)
    {
        i = i*10;
        n = n + 1;
    }
    return n;
    
}

void show_table(node* table_levels[], int place, int height){
    node* time_ptr;
    int differ = (place-1)/2;
    int sum_place = pow(2, height-1)*place + pow(2, height-1)-1;
    int left_tabulation = (sum_place-place)/2;
    int mid_tabulation = 0;
    int underlining = 0;  //te wszystkie przemienne potrzebne zeby obliczac liczbe spacji na poczatku i pomiedzy elementami drzewa
    for (size_t i = 0; i < height; i++)
    {   
        time_ptr = table_levels[i];
        if (i!=0)
        {
            mid_tabulation = (sum_place-2*left_tabulation-pow(2,i)*place)/(pow(2,i)-1);
        }
        for (size_t i = 0; i < left_tabulation; i++)
            {
                cout << " ";
            }
        do
        {   
            underlining = place - length_of_number((*time_ptr).value);
            for (size_t i = 0; i < underlining; i++)
            {
                cout << "_";
            }
            
            cout<<(*time_ptr).value;
            for (size_t i = 0; i < mid_tabulation; i++)
            {
                cout << " ";
            }
            
            time_ptr = (*time_ptr).next;
        } while (time_ptr);
        left_tabulation = ((left_tabulation-place)+differ)/2;
        cout << "\n";
    }
    
}


int max_place(int tab1[],int size1, int tab2[], int size2){
    int max=0;
    for (size_t i = 0; i < size1; i++)
    {
        if (tab1[i]>max)
        {
            max = tab1[i];
        }
        
    }
    for (size_t i = 0; i < size2; i++)
    {
        if (tab2[i]>max)
        {
            max = tab2[i];
        }
        
    }  //tu szukam najwiekszy element
    int i=10;
    int place = 1;
    while (max/i!=0)
    {
        place = place + 1;
        i = i * 10;
    }  //a tu szukam go rozmiar
    if (place%2==0)
    {
        place = place + 1;
    }
    
    return place;
    
}

int main() {
    int n1, n2, n;
    n = 0;
    n1 = 3;
    n2 = 15;
    int tab1[n1] = {1,2,3}; 
    int tab2[n2] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    node_tree* start1 = build_tree(tab1, n1);
    node_tree* start2 = build_tree(tab2, n2);
    int height = height_tree(start2, 0);
    node* table_levels[height];
    for (size_t i = 0; i < height; i++)
    {
        table_levels[i] = nullptr;
    }
    int place = max_place(tab1, n1, tab2, n2);
    prepare_for_showing(start2, table_levels, n, place, height);
    show_table(table_levels, place, height);
    

    

    
    
}