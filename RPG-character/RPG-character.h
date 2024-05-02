#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H

#include <iostream>

class RPGCharacter {
 public: 
  RPGCharacter() : strength_(0), mind_(0), stamina_(0), skill_(0), intelligence_(0), faith_(0), arcane_(0) {}
  RPGCharacter(int strength, int mind, int stamina, int skill, int intelligence, int faith, int arcane) : strength_(strength), mind_(mind), stamina_(stamina), skill_(skill), intelligence_(intelligence), faith_(faith), arcane_(arcane) {
    value_ = (strength_ + mind_ + stamina_ + skill_ + intelligence_ + faith_ + arcane_) / 7;
  }
  int getValue() const { return value_; }
  bool operator==(const RPGCharacter& character) const { return value_ == character.value_; }
  bool operator!=(const RPGCharacter& character) const { return value_ != character.value_; }
  bool operator<(const RPGCharacter& character) const { return value_ < character.value_; }
  bool operator>(const RPGCharacter& character) const { return value_ > character.value_; }
  bool operator/(const int value) const { return value_ / value; }
  bool operator+(const int value) const { return value_ + value; }
  bool operator-(const int value) const { return value_ - value; }
  void operator=(const int value) { value_ = value; }
 private:
  int strength_;
  int mind_;
  int stamina_;
  int skill_;
  int intelligence_;
  int faith_;
  int arcane_;
  int value_;
};

std::ostream& operator<<(std::ostream& os, const RPGCharacter& character) {
  os << character.getValue();
  return os;
}

#endif