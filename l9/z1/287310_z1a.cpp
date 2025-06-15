#include <iostream>
#include <map>
using namespace std;

class multiset
{
private:
    map<int, int> set;

    bool check(int value){
        bool el_in_set = false;
        for (auto [i,j] : (*this).set)
        {
            if (i == value)
            {
                el_in_set = true;
            }
            
        }
        return el_in_set;
    }
    void del_one(int value){
        bool is_el_in_set = this->check(value);
        if (is_el_in_set and set[value] > 1)
        {
             set[value] = set[value] - 1;
        }else if (is_el_in_set and set[value] == 1)
        {
            set.erase(value);
        }else{
            cout << "tego elementa juz nie ma w multizbiorze\n";
        }
        
        
        
    }
    void add_el(int value){
        bool is_el_in_set;
        is_el_in_set = this->check(value);
        if (is_el_in_set)
            {
                set[value] = set[value] + 1;
            }else{
                set[value] = 1;
            }
    }


public:
    multiset (){
        set;
    };

    

    multiset operator -(int value){
        this->del_one(value);
        return *this;
    }
    multiset operator +(int value){
        this->add_el(value);
        return *this;
    }
    
    void print(){
        for (auto [i,j] : set)
        {
            cout << i << " : " << j << "\n";
        }
        
    }

    

    void del_all(int value){
        bool is_el_in_set = this->check(value);
        if (is_el_in_set)
        {
            set.erase(value);
        }
        else
        {
            cout << "tego elementa juz nie ma w multizbiorze\n";
        }
        
    }
};

ostream& operator<<(ostream& os, multiset& object){
        object.print();
        return os;
    }





int main(){
    multiset object;
    object = object + 3;
    object = object + 3;
    object = object - 3;
    object.del_all(2);
    cout << object;
    
    
}