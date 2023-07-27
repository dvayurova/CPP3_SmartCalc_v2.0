#ifndef SRC_MODEL_INFIX_H_
#define SRC_MODEL_INFIX_H_

#include <regex>
#include <string>

namespace s21 {

class Infix {
public:
  Infix() {}
  Infix(std::string str) : infix_(str) {}
  Infix(const Infix &other) { infix_ = other.infix_; }
  Infix(Infix &&other) { infix_ = other.infix_; }
  ~Infix() {}

  double GetNumber(size_t &index);
  std::string GetFunction(size_t &index);

  size_t GetLength();
  char &operator[](size_t i);
  std::string &operator=(std::string &str);
  std::string &operator=(std::string &&str) {
    infix_ = str;
    return infix_;
  }
  std::string &GetString();
  std::string GetOperation(size_t &index);

private:
  std::string infix_;
};

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

#endif //  SRC_MODEL_INFIX_H_