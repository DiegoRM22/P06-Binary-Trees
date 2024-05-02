#ifndef NODEAVL_H
#define NODEAVL_H

#include <iostream>
#include <string>

#include "../nodeB.h"


template <class Key>
class NodeAVL : public NodeB {
 public:
  NodeAVL(const Key& data, int balance) : NodeB<Key>(data) {
    this->balance = balance;
  }
  NodeAVL(const Key& data) : NodeB<Key>(data) {
    this->balance = 0;
  }
  ~NodeAVL() {}
  int getBalance() const { return balance; }
  void setBalance(int balance) { this->balance = balance; }
  
  NodeB<Key>* GetLeft() const { return dynamic_cast<NodeB<Key>*>(this->left_); }
  NodeB<Key>* GetRight() const { return dynamic_cast<NodeB<Key>*>(this->right_); }
  void SetLeft(NodeAVL<Key>* left) { this->left_ = left; }
  void SetRight(NodeAVL<Key>* right) { this->right_ = right; }

  Key GetData() const { return this->data_; }


 private:
  int balance;
};

#endif