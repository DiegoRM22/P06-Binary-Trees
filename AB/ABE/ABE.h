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
  NodeB<Key>* GetRoot() const { return this->GetRoot(); }
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
  std::queue<NodeB<Key>*> q;
  q.push(this->root_);
  while (!q.empty()) {
    NodeB<Key>* current = q.front();
    q.pop();
    if (current->GetLeft() == nullptr) {
      current->SetLeft(new NodeB<Key>(data));
      return true;
    } else {
      q.push(current->GetLeft());
    }
    if (current->GetRight() == nullptr) {
      current->SetRight(new NodeB<Key>(data));
      return true;
    } else {
      q.push(current->GetRight());
    }
  }
  return false; // Esto debería ser inalcanzable si el árbol está correctamente estructurado
}


/**
 * @brief Search a node in the tree.
*/
template<class Key>
bool ABE<Key>::Search(const Key& data) {
  if (this->root_ == nullptr) {
    return false;
  }
  std::queue<NodeB<Key>*> q;
  q.push(this->root_);
  while (!q.empty()) {
    NodeB<Key>* current = q.front();
    q.pop();
    if (current->GetData() == data) {
      return true;
    }
    if (current->GetLeft() != nullptr) {
      q.push(current->GetLeft());
    }
    if (current->GetRight() != nullptr) {
      q.push(current->GetRight());
    }
  }
  return false;
}


#endif