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

	void InOrder(NodeB<Key>* current) const;
  

  NodeB<Key>* GetRoot() const { return root_; }

 protected:
  NodeB<Key>* root_;
};

#include <iostream>
#include <queue>

template <typename T>
std::ostream& operator<<(std::ostream& os, const AB<T>& ab) {
	if (ab.GetRoot() == nullptr) {
		os << "[.]";
		return os;
	}

	std::queue<NodeB<T>*> q;
	q.push(ab.GetRoot());

	while (!q.empty()) {
			size_t level_nodes = q.size();

			while (level_nodes > 0) {
				NodeB<T>* current = q.front();
				q.pop();
				if (current != nullptr) {
					os << "[" << current->GetData() << "] ";
					if (current->GetLeft() != nullptr) {
						q.push(current->GetLeft());
					} else {
						q.push(nullptr);
					}
					if (current->GetRight() != nullptr) {
						q.push(current->GetRight());
					} else {
						q.push(nullptr);
					}
				} else {
					os << "[.] ";
				}
				level_nodes--;
			}
		os << std::endl;
	}

	return os;
}

template<class Key>
void AB<Key>::InOrder(NodeB<Key>* current) const {
	if (current == nullptr) {
		return;
	}

	InOrder(current->GetLeft());
	std::cout << current->GetData() << " ";
	InOrder(current->GetRight());
}


#endif
