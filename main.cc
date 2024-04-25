
#include <iostream>

#include "AB/AB.h"
#include "AB/ABE/ABE.h"
#include "AB/ABB/ABB.h"
#include "nodeB/nodeB.h"

int main(int argc, char* argv[]) {
  ABE<int> abe(30);
  std::cout << abe << std::endl;
  abe.Insert(25);
  std::cout << abe << std::endl;
  abe.Insert(15);
  std::cout << abe << std::endl;
  abe.Insert(40);
  std::cout << abe << std::endl;
  abe.Insert(35);
  std::cout << abe << std::endl;
  abe.Insert(45);
  std::cout << abe << std::endl;
  abe.Insert(50);
  std::cout << abe << std::endl;
  abe.Insert(55);
  std::cout << abe << std::endl;

  return 0;
}