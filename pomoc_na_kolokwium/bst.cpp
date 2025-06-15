#include <iostream>

using namespace std;

struct Node {
  int key;
  Node* left;
  Node* right;
    
  Node(){
    key=0;
    left=nullptr;
    right=nullptr;
  }
  Node(int val){
    key=val;
    left=nullptr;
    right=nullptr;
  }
  ~Node(){
    cout << "deleting node: " << key << "\n";
    delete left;
    delete right;
  }
  void show_node(){
    cout << key << " ";
    if (left!=nullptr){
      (*left).show_node();
    }
    //cout << key << " "; // Tak bÄdzie in-order i wyĹwietli posortowane
    if (right!=nullptr){
      (*right).show_node();
    }
  }
};

class BStree {
  private:
    Node* root;
  public:
    BStree(){
      root=nullptr;
    }
    ~BStree(){
      delete root;
    }
    void insert(int new_key){
      insert_node_aux(root,new_key);
    }
    void insert_node_aux(Node*& node, int new_key){
      if (node == nullptr){
        node=new Node(new_key);
      }
      else if (node->key == new_key){
        cout << "JuĹź taki jest!\n";
      }
      else if (new_key < node->key){
        insert_node_aux(node->left,new_key);
      }
      else {
        insert_node_aux(node->right,new_key);
      }
    }
    void remove(int item){
      remove(root,item);
    }
    void remove(Node*& node, int item){
      if (node==nullptr){
        cout << "Nie ma takiego klucza\n";
      }
      else {
        if (item < node->key){
          remove(node->left, item);
        }
        else if (item > node->key){
          remove(node->right, item);
        }
        else {
          if (node->left == nullptr){
            Node* tmp=node;
            node=node->right;
            tmp->right=nullptr;
            delete tmp;
          }
          else if (node->right == nullptr){
            Node* tmp=node;
            node=node->left;
            tmp->left=nullptr;
            delete tmp;
          }
          else {
            Node* leftmost=find_leftmost(node->right);
            node->key=leftmost->key;
            remove(node->right, leftmost->key);
          }
        }
      }
    }
    /* W poniĹźszej funkcji, poniewaĹź dziaĹamy na wskaĹşnikach na Node,
       koniec dziaĹania funkcji oznacza usuniÄcie lokalnego wskaĹşnika,
       ale bez wzywania destruktora, dziÄki czemu nie zostaje usuniÄta Ĺźadna czÄĹÄ drzewa. DziaĹanie na prawdziwych obiektach trochÄ by to popsuĹo bez
       zdefiniowania odpowiednio move i copy konstruktorĂłw/przypisaĹ.
    */
    Node* find_leftmost(Node* node){
      if (node->left==nullptr){
        return node;
      }
      else {
        return find_leftmost(node->left);
      }
    }
    
    void show_tree(){
      root->show_node();
      cout << "\n";
    }
};

int main(){
  BStree tree;
  tree.insert(11);
  tree.insert(8);
  tree.insert(15);
  tree.insert(7);
  tree.insert(10);
  tree.insert(12);
  tree.insert(19);
  tree.insert(23);
  tree.show_tree();
  tree.remove(17);
  tree.show_tree();
  tree.remove(15);
  tree.show_tree();
  tree.remove(11);
  tree.remove(38);
  tree.show_tree();
  return 0;
}