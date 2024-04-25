#ifndef ABB_H
#define ABB_H

#include <iostream>

#include "../AB.h"

template<class Key>
class ABB : public AB<Key> {
 public:
  ABB() : AB<Key>() {}
  ABB(const Key& data) : AB<Key>(data) {}
  bool Insert(const Key& data) override;
  bool Search(const Key& data) override;
};

/**
 * @brief Insert a new node in the tree checking in which side it should be inserted.
*/
template<class Key>
bool ABB<Key>::Insert(const Key& data) {
  std::cout << "Inserting: " << data << std::endl;
  if (this->root_ == nullptr) {
    std::cout << "Inserting root" << std::endl;
    this->root_ = new NodeB<Key>(data);
    return true;
  }
  NodeB<Key>* current = this->root_;
  while (true) {
    if (data < current->GetData()) {
      if (current->GetLeft() == nullptr) {
        std::cout << "Inserting left" << std::endl;
        current->SetLeft(new NodeB<Key>(data));
        return true;
      } else {
        current = current->GetLeft();
      }
    } else if (data > current->GetData()) {
      if (current->GetRight() == nullptr) {
        std::cout << "Inserting right" << std::endl;
        current->SetRight(new NodeB<Key>(data));
        return true;
      } else {
        current = current->GetRight();
      }
    } else {
      std::cout << "Data already in the tree" << std::endl;
      return false; // El dato ya está en el árbol
    }
  }
}

template<class Key>
bool ABB<Key>::Search(const Key& data) {
  NodeB<Key>* current = this->root_;
  while (current != nullptr) {
    if (data == current->GetData()) {
      return true;
    } else if (data < current->GetData()) {
      current = current->GetLeft();
    } else {
      current = current->GetRight();
    }
  }
  return false;
}

#endif
