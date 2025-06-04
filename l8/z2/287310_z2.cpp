#include <iostream>
using namespace std;


struct node_tree {
    int value;
    node_tree* left;
    node_tree* right;
    node_tree(int v) : value(v), left(nullptr), right(nullptr) {}
};

class bin_search_tree
{
private:
    node_tree* root;
    
    node_tree* insert(node_tree* node, int val) {
        if (node == nullptr){
            return new node_tree(val);
        } 
        if (val < node->value){
            node->left = insert(node->left, val);
        }    
        else{
            node->right = insert(node->right, val);
        }
        return node;
    }

    void print(node_tree* node){
        if (node == nullptr) {
            return;
        }
        print(node->left);
        cout << node->value << " ";
        print(node->right);
    }

    bool is_isomorphic(node_tree* a, node_tree* b) {
        if (a == nullptr and b == nullptr) {
            return true;
        }
        if (a == nullptr or b == nullptr) {
            return false;
        }
        return is_isomorphic(a->left, b->left) and is_isomorphic(a->right, b->right);
    }

    node_tree* addition(node_tree* a, node_tree* b) {
        if (a == nullptr or b == nullptr) {
            return nullptr;
        }
        node_tree* tree3 = new node_tree(a->value + b->value);
        tree3->left = addition(a->left, b->left);
        tree3->right = addition(a->right, b->right);
        return tree3;
    }

    node_tree* subtraction(node_tree* a, node_tree* b) {
        if (a == nullptr or b == nullptr) {
            return nullptr;
        }
        node_tree* tree3 = new node_tree(a->value - b->value);
        tree3->left = subtraction(a->left, b->left);
        tree3->right = subtraction(a->right, b->right);
        return tree3;
    }
    
     


public:
    bin_search_tree(){
        root = nullptr;        
    }
    bin_search_tree(node_tree* n){
        root = n;
    }
    void insert_node(int val) {
        root = insert(root, val);
    }

    void print_tree(){
        print(root);
    }
    friend ostream& operator<<(ostream& os, bin_search_tree& bst);

    bool is_isomorphic(bin_search_tree& other) {
        return is_isomorphic(this->root, other.root);
    }

    bin_search_tree operator + (bin_search_tree& other){
        if (is_isomorphic(other))
        {
            return bin_search_tree(addition(this->root, other.root));
        }
        throw invalid_argument("dzewa nie izomorficzne");
    }
   
    bin_search_tree operator - (bin_search_tree& other){
        if (is_isomorphic(other))
        {
            return bin_search_tree(subtraction(this->root, other.root));
        }
        throw invalid_argument("dzewa nie izomorficzne");
    }
};

    ostream& operator<<(ostream& os, bin_search_tree& bst){
        bst.print_tree();
        return os;
    }
    


int main() {
    bin_search_tree tree1;
    bin_search_tree tree2;
    cout << "ustal, ile elementow bedzie w pierwszym drzewie" << "\n";
    int n1;
    cin >> n1;
    cout << "podaj elementy pierwszego drzewa" << "\n";
    int el;
    for (size_t i = 0; i < n1; i++)
    {
        cin >> el;
        tree1.insert_node(el);
    }
    cout << "ustal, ile elementow bedzie w drugim drzewie" << "\n";
    int n2;
    cin >> n2;
    cout << "podaj elementy drugiego drzewa" << "\n";
    for (size_t i = 0; i < n2; i++)
    {
        cin >> el;
        tree2.insert_node(el);
    }
    
    if (tree1.is_isomorphic(tree2)) {
        cout << "Drzewa sa izomorficzne\n";
    } else {
        cout << "Drzewa nie sa izomorficzne\n";
    }
    
    
    bin_search_tree tree3 = tree1 + tree2;
    bin_search_tree tree4 = tree1 - tree2;
    cout << tree3 << "\n";
    cout   << tree4;



    return 0;
}
