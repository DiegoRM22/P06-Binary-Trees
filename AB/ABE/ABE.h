#ifndef ABE_H
#define ABE_H

#include <iostream>

#include "../AB.h"

template<class Key>
class ABE : public AB<Key> {
 public:
  ABE() : AB<Key>() {}
  ABE(const Key& data) : AB<Key>(data) {}
  bool Insert(const Key& data) override;
  bool Search(const Key& data) override;
};

/**
 * @brief Insert a new node in the tree without checking in which side it should be inserted.
*/
template<class Key>
bool ABE<Key>::Insert(const Key& data) {
  if (this->root_ == nullptr) {
    this->root_ = new NodeB<Key>(data);
    return true;
  }
  NodeB<Key>* current = this->root_;
  while (true) {
    if (current->GetLeft()->GetData() == NULL ) {
      std::cout << "Inserting left" << std::endl;
      std::cout << "Izquierda: " << current->GetLeft()<< std::endl;
      current->SetLeft(new NodeB<Key>(data));
      return true;
    } else if (current->GetRight() == nullptr) {
      current->SetRight(new NodeB<Key>(data));
      return true;
    } 
    // Check if the data is already in the tree
    if (current->GetData() == data || current->GetLeft()->GetData() == data || current->GetRight()->GetData() == data) {
      std::cout << "Data already in the tree" << std::endl;
      return false;
    } else {
      current = current->GetLeft();
    }
  }
}

/**
 * @brief Search a node in the tree.
*/
template<class Key>
bool ABE<Key>::Search(const Key& data) {
  if (this->root_ == nullptr) {
    return false;
  }
  NodeB<Key>* current = this->root_;
  while (current != nullptr) {
    if (current->GetData() == data) {
      return true;
    }
    if (current->GetLeft() != nullptr) {
      if (current->GetLeft()->GetData() == data) {
        return true;
      }
    }
    if (current->GetRight() != nullptr) {
      if (current->GetRight()->GetData() == data) {
        return true;
      }
    }
    current = current->GetLeft();
  }
  return false;
}

#endif