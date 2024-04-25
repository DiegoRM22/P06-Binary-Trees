
#include <iostream>

#include "AB/AB.h"
#include "AB/ABE/ABE.h"
#include "AB/ABB/ABB.h"
#include "nodeB/nodeB.h"

int main(int argc, char* argv[]) {
  ABB<int> abe(30);
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
  // Search
  std::cout << "These searches should return true: " << std::endl;
  std::cout << "Searching 25: " << abe.Search(25) << std::endl;
  std::cout << "Searching 15: " << abe.Search(15) << std::endl;
  std::cout << "Searching 40: " << abe.Search(40) << std::endl;
  std::cout << "Searching 35: " << abe.Search(35) << std::endl;
  std::cout << "Searching 45: " << abe.Search(45) << std::endl;
  std::cout << "Searching 50: " << abe.Search(50) << std::endl;
  std::cout << "Searching 55: " << abe.Search(55) << std::endl;

  std::cout << "These searches should return false: " << std::endl;
  std::cout << "Searching 10: " << abe.Search(10) << std::endl;
  std::cout << "Searching 20: " << abe.Search(20) << std::endl;
  std::cout << "Searching 60: " << abe.Search(60) << std::endl;
  std::cout << "Searching 70: " << abe.Search(70) << std::endl;
  std::cout << "Searching 80: " << abe.Search(80) << std::endl;
  std::cout << "Searching 90: " << abe.Search(90) << std::endl;

  return 0;
}