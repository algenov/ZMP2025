#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
    
  Node(){
    data=0;
    left=nullptr;
    right=nullptr;
  }
  Node(int val){
    data=val;
    left=nullptr;
    right=nullptr;
  }
  ~Node(){
    cout << "deleting node with data: " << data << "\n";
    delete left;
    delete right;
  }
  void show_node(){
    cout << data << " ";
    if (left!=nullptr){
      (*left).show_node();
    }
    if (right!=nullptr){
      (*right).show_node();
    }
  }
};

struct Btree {
  
  Node* root;
  
  Btree(){
    root=nullptr;
  }
  ~Btree(){
    delete root;
  }
};

int main(){
  Btree tree;
  tree.root=new Node(1);
  (tree.root)->left=new Node(3);
  (tree.root)->right=new Node(4);
  (tree.root)->right->right=new Node(2);
  (tree.root)->show_node();
  return 0;
}