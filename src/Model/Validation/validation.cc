#include "validation.h"
namespace s21 {

bool Validation::IsValid(std::string &expression) {
  expression_ = expression;
  PrepareExpression();
  infix_ = expression_;
  bool valid_expression_ = true;
  for (size_t i = 0; i < infix_.GetLength() && valid_expression_; i++) {
    if (std::isdigit(infix_[i])) {
      infix_.GetNumber(i);
    } else if (infix_[i] == '(' || infix_[i] == ')') {
      valid_expression_ = CheckBrackets(i);
    } else if (!IsOperation(i)) {
      valid_expression_ = false;
    }
  }
  if (CheckExtraBrackets())
    valid_expression_ = false;
  expression = infix_.GetString();
  return valid_expression_;
}

bool Validation::IsOperation(size_t &i) {
  Lexeme lexeme;
  if (lexeme.operation_priority.find(infix_.GetOperation(i)) ==
      lexeme.operation_priority.end())
    return false;
  return true;
}

bool Validation::CheckBrackets(size_t &i) {
  std::string operation{};
  if (infix_[i] == '(') {
    if (infix_[i + 1] == ')') {
      return false;
    }
    operation.push_back(infix_[i]);
    stack_.push(Lexeme(operation));
  } else if (infix_[i] == ')') {
    while (!stack_.empty() && stack_.top().operation_ != "(") {
      stack_.pop();
    }
    if (!stack_.empty() && stack_.top().operation_ == "(") {
      stack_.pop();
    } else {
      return false;
    }
  }
  return true;
}

bool Validation::CheckExtraBrackets() {
  while (!stack_.empty()) {
    if (stack_.top().operation_ == "(")
      return true;
    stack_.pop();
  }
  return false;
}

void Validation::PrepareExpression() {
  std::transform(expression_.begin(), expression_.end(), expression_.begin(),
                 ::tolower);
  expression_.erase(remove(expression_.begin(), expression_.end(), ' '),
                    expression_.end());
  for (size_t i = 0; i < expression_.length(); i++) {
    AddAsterisk(i);
    AddZeroToUnarySign(i);
  }
}

void Validation::AddAsterisk(size_t &i) {
  if ((expression_[i] == '(' ||
       (std::isalpha(expression_[i]) && expression_[i] != 'm')) &&
      std::isdigit(expression_[i - 1])) {
    expression_.insert(i, 1, '*');
  }
}

void Validation::AddZeroToUnarySign(size_t &i) {
  if ((expression_[i] == '-' || expression_[i] == '+') &&
      (i == 0 || expression_[i - 1] == '(')) {
    expression_.insert(i, 1, '0');
  }
}

} // namespace s21