#include "model.h"
#include <iostream> // delete

// namespace s21 {

void Model::Parser() { GetNumber(); }

void Model::GetNumber() {
  std::regex double_regex("\\d+([.]\\d+)?(e[-+]?\\d+)?");
  std::regex_token_iterator<std::string::iterator> next(
      expression_.begin(), expression_.end(), double_regex);
  std::regex_token_iterator<std::string::iterator> end;
  while (next != end) {
    std::cout << *next << "\n";
    next++;
  }
}

// } // namespace s21