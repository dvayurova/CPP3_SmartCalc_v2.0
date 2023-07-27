#ifndef SRC_MODEL_VALIDATION_H_
#define SRC_MODEL_VALIDATION_H_

#include "infix.h"
#include "lexeme.h"
#include <stack>

namespace s21 {

class Validation {
public:
  Validation() {}
  bool IsValid(std::string &expression);

private:
  Infix infix_;
};

bool Validation::IsValid(std::string &expression) {
  std::stack<Lexeme> stack;
  infix_ = expression;
  infix_.PrepareInfix();

  bool valid_expression_ = true;

  for (size_t i = 0; i < infix_.GetLength() && valid_expression_; i++) {
    std::string operation{};
    if (std::isdigit(infix_[i])) {
      infix_.GetNumber(i);
    } else if (infix_[i] == '(') {
      if (infix_[i + 1] == ')') {
        valid_expression_ = false;
      }
      operation.push_back(infix_[i]);
      stack.push(Lexeme(operation));
    } else if (infix_[i] == ')') {
      while (!stack.empty() && stack.top().operation_ != "(") {
        stack.pop();
      }
      if (!stack.empty() && stack.top().operation_ == "(") {
        stack.pop();
      } else {
        valid_expression_ = false;
      }
    } else {
      if (std::isalpha(infix_[i])) {
        operation = infix_.GetFunction(i);
      } else {
        operation.push_back(infix_[i]);
      }
      if (operation_priority.find(operation) == operation_priority.end()) {
        valid_expression_ = false;
      }
    }
  }
  while (!stack.empty()) {
    if (stack.top().operation_ == "(")
      valid_expression_ = false;
    stack.pop();
  }
  expression = infix_.GetString();
  // std::cout << "prepared infix = " << infix_.GetString() << "\n";
  return valid_expression_;
}

} // namespace s21

#endif //  SRC_MODEL_VALIDATION_H_