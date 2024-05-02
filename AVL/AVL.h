#ifndef AVL_H
#define AVL_H

#include <iostream>
#include "../AB/ABB/ABB.h"
#include "../AB/AB.h"
#include "../nodeB/nodeB.h"
#include "../nodeB/nodeAVL/nodeAVL.h"

template<class Key>
class AVL : public ABB<Key> {
public:
  AVL() : ABB<Key>() {}
  AVL(const Key& data) : ABB<Key>(data) {}

  bool Insert(const Key& data) override;
private:
  void UpdateBalances(NodeAVL<Key>* node);
  void RotateLL(NodeAVL<Key>* node);
  void RotateRR(NodeAVL<Key>* node);
  void RotateLR(NodeAVL<Key>* node);
  void RotateRL(NodeAVL<Key>* node);
};

template<class Key>
bool AVL<Key>::Insert(const Key& data) {
  if (this->root_ == nullptr) {
    this->root_ = new NodeB<Key>(data);
    return true;
  }

  NodeAVL<Key>* current = dynamic_cast<NodeAVL<Key>*>(this->GetRoot());
  NodeAVL<Key>* parent = nullptr;
  while (true) {
    if (data < current->GetData()) {
      if (current->GetLeft() == nullptr) {
        current->SetLeft(new NodeAVL<Key>(data));
        UpdateBalances(current);
        return true;
      } else {
        parent = current;
        current = dynamic_cast<NodeAVL<Key>*>(current->GetLeft());
      }
    } else if (data > current->GetData()) {
      if (current->GetRight() == nullptr) {
        current->SetRight(new NodeAVL<Key>(data));
        UpdateBalances(current);
        return true;
      } else {
        parent = current;
        current = dynamic_cast<NodeAVL<Key>*>(current->GetRight());
      }
    } else {
      return false; // El dato ya está en el árbol
    }
  }
}

template<class Key>
void AVL<Key>::UpdateBalances(NodeAVL<Key>* node) {
  if (node == nullptr) return;

  while (node != nullptr) {
    int left_height = (node->GetLeft() != nullptr) ? dynamic_cast<NodeAVL<Key>*>(node->GetLeft())->GetHeight() : -1;
    int right_height = (node->GetRight() != nullptr) ? dynamic_cast<NodeAVL<Key>*>(node->GetRight())->GetHeight() : -1;
    int balance = right_height - left_height;

    if (balance > 1) {
      if (node->GetRight() != nullptr && dynamic_cast<NodeAVL<Key>*>(node->GetRight())->GetBal() < 0) {
        RotateRL(node);
      } else {
        RotateRR(node);
      }
    } else if (balance < -1) {
      if (node->GetLeft() != nullptr && dynamic_cast<NodeAVL<Key>*>(node->GetLeft())->GetBal() > 0) {
        RotateLR(node);
      } else {
        RotateLL(node);
      }
    }

    left_height = (node->GetLeft() != nullptr) ? dynamic_cast<NodeAVL<Key>*>(node->GetLeft())->GetHeight() : -1;
    right_height = (node->GetRight() != nullptr) ? dynamic_cast<NodeAVL<Key>*>(node->GetRight())->GetHeight() : -1;
    balance = right_height - left_height;

    node->SetHeight(std::max(left_height, right_height) + 1);
    node->SetBal(balance);

    node = dynamic_cast<NodeAVL<Key>*>(node->GetParent());
  }
}

template<class Key>
void AVL<Key>::RotateLL(NodeAVL<Key>* node) {
  NodeAVL<Key>* pivot = dynamic_cast<NodeAVL<Key>*>(node->GetLeft());
  node->SetLeft(pivot->GetRight());
  if (pivot->GetRight() != nullptr) {
    dynamic_cast<NodeAVL<Key>*>(pivot->GetRight())->SetParent(node);
  }
  pivot->SetRight(node);
  pivot->SetParent(node->GetParent());
  node->SetParent(pivot);

  if (pivot->GetParent() == nullptr) {
    this->root_ = pivot;
  } else if (pivot->GetData() < pivot->GetParent()->GetData()) {
    pivot->GetParent()->SetLeft(pivot);
  } else {
    pivot->GetParent()->SetRight(pivot);
  }

  node->SetHeight(std::max((node->GetLeft() != nullptr) ? dynamic_cast<NodeAVL<Key>*>(node->GetLeft())->GetHeight() : -1,
                           (node->GetRight() != nullptr) ? dynamic_cast<NodeAVL<Key>*>(node->GetRight())->GetHeight() : -1) + 1);
  pivot->SetHeight(std::max((pivot->GetLeft() != nullptr) ? dynamic_cast<NodeAVL<Key>*>(pivot->GetLeft())->GetHeight() : -1,
                            (pivot->GetRight() != nullptr) ? dynamic_cast<NodeAVL<Key>*>(pivot->GetRight())->GetHeight() : -1) + 1);
}

template<class Key>
void AVL<Key>::RotateRR(NodeAVL<Key>* node) {
  NodeAVL<Key>* pivot = dynamic_cast<NodeAVL<Key>*>(node->GetRight());
  node->SetRight(pivot->GetLeft());
  if (pivot->GetLeft() != nullptr) {
    dynamic_cast<NodeAVL<Key>*>(pivot->GetLeft())->SetParent(node);
  }
  pivot->SetLeft(node);
  pivot->SetParent(node->GetParent());
  node->SetParent(pivot);

  if (pivot->GetParent() == nullptr) {
    this->root_ = pivot;
  } else if (pivot->GetData() < pivot->GetParent()->GetData()) {
    pivot->GetParent()->SetLeft(pivot);
  } else {
    pivot->GetParent()->SetRight(pivot);
  }

  node->SetHeight(std::max((node->GetLeft() != nullptr) ? dynamic_cast<NodeAVL<Key>*>(node->GetLeft())->GetHeight() : -1,
                           (node->GetRight() != nullptr) ? dynamic_cast<NodeAVL<Key>*>(node->GetRight())->GetHeight() : -1) + 1);
  pivot->SetHeight(std::max((pivot->GetLeft() != nullptr) ? dynamic_cast<NodeAVL<Key>*>(pivot->GetLeft())->GetHeight() : -1,
                            (pivot->GetRight() != nullptr) ? dynamic_cast<NodeAVL<Key>*>(pivot->GetRight())->GetHeight() : -1) + 1);
}

template<class Key>
void AVL<Key>::RotateLR(NodeAVL<Key>* node) {
  RotateRR(dynamic_cast<NodeAVL<Key>*>(node->GetLeft()));
  RotateLL(node);
}

template<class Key>
void AVL<Key>::RotateRL(NodeAVL<Key>* node) {
  RotateLL(dynamic_cast<NodeAVL<Key>*>(node->GetRight()));
  RotateRR(node);
}

#endif
