#ifndef SRC_MODEL_INFIX_H_
#define SRC_MODEL_INFIX_H_

#include <regex>
#include <string>

namespace s21 {

class Infix {
public:
  Infix() {}
  Infix(std::string str) : infix_(str) {}

  double GetNumber(size_t &index);
  std::string GetFunction(size_t &index);
  void PrepareInfix();
  size_t GetLength();
  char &operator[](size_t i);
  std::string &operator=(std::string &str);
  std::string &GetString();

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

void Infix::PrepareInfix() {
  std::transform(infix_.begin(), infix_.end(), infix_.begin(), ::tolower);
  infix_.erase(remove(infix_.begin(), infix_.end(), ' '), infix_.end());
  for (size_t i = 0; i < infix_.length(); i++) {
    if ((infix_[i] == '-' || infix_[i] == '+') &&
        (i == 0 || infix_[i - 1] == '(')) {
      infix_.insert(i, 1, '0'); // добавляю 0 перед унарным -+
    }
    if ((infix_[i] == '(' || (std::isalpha(infix_[i]) && infix_[i] != 'm')) &&
        std::isdigit(infix_[i - 1])) {
      infix_.insert(i, 1, '*'); // добавляю опущенный знак *
    }
  }
}

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

} // namespace s21

#endif //  SRC_MODEL_INFIX_H_