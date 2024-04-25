#ifndef NODEB_H
#define NODEB_H

#include <iostream>

template<class Key>
class NodeB {
 public:
  NodeB() : left_(nullptr), right_(nullptr), data_(NULL) {}
  NodeB(const Key& data) : data_(data), left_(nullptr), right_(nullptr) {}

  NodeB<Key>* GetLeft() const { return left_; }
  NodeB<Key>* GetRight() const { return right_; }
  void SetLeft(NodeB<Key>* left) { left_ = left; }
  void SetRight(NodeB<Key>* right) { right_ = right; }



  Key GetData() const { return data_; }

 protected:
  Key data_;
  NodeB<Key>* left_;
  NodeB<Key>* right_;
};

template<class Key>
std::ostream& operator<<(std::ostream& os, const NodeB<Key>& node) {
  if (node.GetLeft() != nullptr) {
    os << "[" << node.GetData() << "] ";
  } else {
    os << "[.]" << " ";
  }
  return os;
}

#endif
