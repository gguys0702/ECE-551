#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "map.h"

template<typename K, typename V>
class BstMap : public Map<K, V> {
  class Node {
   public:
    K key;
    V value;
    Node * left;
    Node * right;
    Node() : key(0), value(0), left(NULL), right(NULL) {}
    Node(K k, V v) : key(k), value(v), left(NULL), right(NULL) {}
  };
  Node * root;

 public:
  BstMap() : root(NULL) {}
   virtual void add(const K & key, const V & value) {
    Node ** ptr = &root;
    while((*ptr)!=NULL){
       if((*ptr)->key>key){
        ptr = &(*ptr)->left;
      }else if((*ptr)->key<key){
        ptr = &(*ptr)->right;
      }else if((*ptr)->key == key){
        (*ptr)->value = value;
        return;
      }
    }
    *ptr = new Node(key,value);
  }
  virtual const V & lookup(const K& key) const throw (std::invalid_argument) {
     Node * ptr = root;
    while(ptr!=NULL){
      if(ptr->key>key){
        ptr = ptr->left;
      }else if(ptr->key<key){
        ptr = ptr->right;
      } else{
        return ptr->value;
      }
      }
       throw std::invalid_argument("The key is not found!\n");
  
  }
 virtual void remove(const K & key) {
    Node ** curr = &root;
    while (key != (*curr)->key) {
      if (*curr == NULL) {
        return;
      }
      if (key < (*curr)->key) {
        curr = &(*curr)->left;
      }
      else {
        curr = &(*curr)->right;
      }
    }
    Node * temp;
    if ((*curr)->left == NULL) {
      temp = (*curr)->right;
      delete *curr;
      *curr = temp;
    }
    else if ((*curr)->right == NULL) {
      temp = (*curr)->left;
      delete *curr;
      *curr = temp;
    }
    else {
      Node ** temp2 = &(*curr)->left;
      while ((*temp2)->right != NULL) {
        temp2 = &(*temp2)->right;
      }
      (*curr)->key = (*temp2)->key;
      (*curr)->value = (*temp2)->value;
      temp = (*temp2)->left;
      delete *temp2;
      *temp2 = temp;
    }
  }
  virtual ~BstMap<K, V>() { destroy(root); }

  void destroy(Node * current) {
    if (current != NULL) {
      destroy(current->left);
      destroy(current->right);
      delete current;
    }
  }
  void printPreorder(Node * curr) {
    if (curr != NULL) {
      std::cout << curr->key << " ";
      printPreorder(curr->left);
      printPreorder(curr->right);
    }
  }

  void printBstmap() {
    printPreorder(root);
    std::cout << "\n";
  }


};