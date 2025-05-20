#include <iostream>
#include <cmath>
using namespace std;

int max_value = 0;

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

int max_place(int max){
    
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

struct node_tree {
    int value;
    node_tree* left;
    node_tree* right;
    node_tree(int v) : value(v), left(nullptr), right(nullptr) {}
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

int how_many_el_in_tree(node_tree* start, int n=0){
    if (start==nullptr)
    {
        return 0;
    }
    n = n+1;
    if (start->left)
    {
        
        n = how_many_el_in_tree(start->left, n);
    }
    if (start->right)
    {
        
        n = how_many_el_in_tree(start->right, n);
    }
    return n;
    
    
}

int how_many_leaves_in_tree(node_tree* start, int n=0){
    if (start==nullptr)
    {
        return 0;
    }
    if (start->left==nullptr && start->right==nullptr)
    {
        n = n+1;
    }
    
    
    if (start->left)
    {
        
        n = how_many_leaves_in_tree(start->left, n);
    }
    if (start->right)
    {
        
        n = how_many_leaves_in_tree(start->right, n);
    }
    return n;
}

bool if_el_in_tree(node_tree* start, int el_to_find, bool n=0){
    if (start==nullptr)
    {
        return (0);
    }

    if (n)
    {
        return (n);
    }
    if (el_to_find==start->value)
    {

        n = 1;
        return n;
    }
    
    if (start->left)
    {
        
        n = if_el_in_tree(start->left, el_to_find, n);

    }
    if (start->right)
    {
        
        n = if_el_in_tree(start->right, el_to_find, n);

    }
    return n;
}

node_tree* combine_trees(int value, node_tree* start1, node_tree* start2){
    node_tree* new_start = new node_tree(value);
    if (how_many_el_in_tree(start2)>how_many_el_in_tree(start1))
    {
        (*new_start).left = start2;
        (*new_start).right = start1;
    }else
    {
        (*new_start).left = start1;
        (*new_start).right = start2;
    }
    return (new_start);
}



int height_tree(node_tree* start, int height=0){  //licze wysokosc drzewa, dlatego ze zawsze najwiecej elementow bedzie w lewej czesci to mozna zrobic w taki prosty sposob
    height = height+1;
    if ((*start).left!=nullptr)
    {
        height = height_tree((*start).left, height);
    }
    return height;
}



int prepare_for_showing(node_tree* start, node* table_levels[], int n){
    if (start->value>max_value)
    {
        max_value = start->value;
    }
    
    
    add_el(table_levels[n], (*start).value);  //tu robie z kazdego pozioma drzewa strukture, zeby potem ladnie wypisywac

    if ((*start).left!=nullptr)
    {
        n = n + 1;  //n odpowiada numeru pozioma
        prepare_for_showing((*start).left, table_levels, n);
        
    }
    if ((*start).right!=nullptr)
    {
        prepare_for_showing((*start).right, table_levels, n);
    }
    
    

    return max_value;
    
    
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

void show_tree(node_tree* start){
    
    
    int height = height_tree(start);
    node* table_levels[height];
    for (size_t i = 0; i < height; i++)
    {
        table_levels[i] = nullptr;
    }
    int n = 0;
    max_value = 0;
    max_value = prepare_for_showing(start, table_levels, n);
    int place = max_place(max_value);
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



int main() {
    int n1, n2, r, s;
    cout << "prosze podac liczbe elementow w pierwszej tablicy";
    cin >> n1;
    cout << "prosze podac liczbe elementow w drugiej tablicy";
    cin >> n2;
    cout << "prosze podac wartosc w korniu przy sklejeniu drzew";
    cin >> r;
    cout << "prosze podac poszukiwana wartosc";
    cin >> s;
    cout << "prosze podac liczby do uzupelnienia tablic";
    int tab1[n1]; 
    int tab2[n2];
    for (size_t i = 0; i < n1; i++)
    {
        cin >> tab1[i];
    }
    for (size_t i = 0; i < n2; i++)
    {
        cin >> tab2[i];
    }
    node_tree* start1 = build_tree(tab1, n1);
    node_tree* start2 = build_tree(tab2, n2);
    node_tree* start3 = combine_trees(r, start1, start2);
    show_tree(start3);
    cout << "liczba wezlow" << "\n" << how_many_el_in_tree(start3)-how_many_leaves_in_tree(start3) << "\n";
    cout << "lliczba lisci" << "\n" << how_many_leaves_in_tree(start3) << "\n";
    cout << "wysokosc drzewa" << "\n" << height_tree(start3) << "\n";
    
    
    cout << "czy " << s << " jest w drzewie?" << "\n";
    if (if_el_in_tree(start3, s))
    {
        cout << "tak" << "\n";
    }else{
        cout << "nie" << "\n";
    }
        
}