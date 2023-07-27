#include "infix.h"

namespace s21 {
std::string &Infix::GetString() { return infix_; }

std::string &Infix::operator=(std::string &str) {
  infix_ = str;
  return infix_;
}

char &Infix::operator[](size_t i) { return infix_[i]; }

size_t Infix::GetLength() { return infix_.length(); }

double Infix::GetNumber(size_t &index) {
  std::regex double_regex("[-+]?\\d+([.]\\d+)?(e[-+]?\\d+)?");
  std::regex_token_iterator<std::string::iterator> next(
      infix_.begin() + index, infix_.end(), double_regex);
  index += next->length() - 1;
  return std::stod(*next);
}

std::string Infix::GetFunction(size_t &index) {
  std::regex function_regex("([a-z]+)");
  std::regex_token_iterator<std::string::iterator> next(
      infix_.begin() + index, infix_.end(), function_regex);
  index += next->length() - 1;
  return *next;
}

std::string Infix::GetOperation(size_t &index) {
  std::string operation{};
  if (std::isalpha(infix_[index])) {
    operation = GetFunction(index);
  } else {
    operation.push_back(infix_[index]);
  }
  return operation;
}

} // namespace s21