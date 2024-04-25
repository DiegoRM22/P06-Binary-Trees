#ifndef AB_H
#define AB_H

#include <iostream>

#include "../nodeB/nodeB.h"

template<class Key>
class AB {
 public:
  AB() : root_(nullptr) {}
  AB(const Key& data) : root_(new NodeB<Key>(data)) {}
  virtual bool Insert(const Key& data) = 0;
  virtual bool Search(const Key& data) = 0;

  NodeB<Key>* GetRoot() const { return root_; }

 protected:
  NodeB<Key>* root_;
};

std::ostream& operator<<(std::ostream& os, const AB<int>& ab) {
  // Imprimir por niveles
  NodeB<int>* current = ab.GetRoot();
  os << "[" << current->GetData() << "] ";
  while (current != nullptr) {
    os << std::endl;
    if (current->GetLeft() != nullptr) {
      os << "[" << current->GetLeft()->GetData() << "] ";
    } else {
      os << "[.]" << " ";
    }
    if (current->GetRight() != nullptr) {
      os << "[" << current->GetRight()->GetData() << "] ";
    } else {
      os << "[.]" << " ";
    }
    current = current->GetLeft();
  }
  return os;
}

#endif
