#include "validation.h"

namespace s21 {

bool Validation::IsValid(std::string &expression, std::string &x_value) {
  PrepareExpression(expression);
  infix_ = expression;
  bool valid_expression = true;
  if (expression.find("x") != std::string::npos) {
    valid_expression = CheckXValue(x_value);
  }
  for (size_t i = 0; i < infix_.GetLength() && valid_expression; i++) {
    if (std::isdigit(infix_[i])) {
      infix_.GetNumber(i);
    } else if (infix_[i] == 'x') {
      infix_.GetX(x_value, valid_expression);
    } else if (infix_[i] == '(' || infix_[i] == ')') {
      valid_expression = CheckBrackets(i);
    } else if (!IsOperation(i)) {
      valid_expression = false;
    }
  }
  if (CheckExtraBrackets()) valid_expression = false;
  expression = infix_.GetString();
  return valid_expression;
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
    if (stack_.top().operation_ == "(") return true;
    stack_.pop();
  }
  return false;
}

void Validation::PrepareExpression(std::string &expression) {
  for (size_t i = 0; i < expression.length(); i++) {
    AddAsterisk(expression, i);
    AddZeroToUnarySign(expression, i);
  }
}

bool Validation::CheckXValue(std::string &x_value) {
  if (x_value.empty()) return false;
  for (char c : x_value) {
    if (!(isdigit(c) || c == '.' || c == '+' || c == '-')) return false;
  }
  Infix tmp = x_value;
  size_t i = 0;
  tmp.GetNumber(i);
  if (i != (x_value.length() - 1)) return false;
  return true;
}

void Validation::ReplaceXToValue(std::string &expression,
                                 std::string &x_value) {
  size_t pos;
  while ((pos = expression.find("x")) != std::string::npos) {
    expression.replace(pos, 1, x_value);
  }
}

void Validation::AddAsterisk(std::string &expression, size_t &i) {
  if ((expression[i] == '(' ||
       (std::isalpha(expression[i]) && expression[i] != 'm')) &&
      (i != 0 &&
       (std::isdigit(expression[i - 1]) || expression[i - 1] == 'x'))) {
    expression.insert(i, 1, '*');
  }
}

void Validation::AddZeroToUnarySign(std::string &expression, size_t &i) {
  if ((expression[i] == '-' || expression[i] == '+') &&
      (i == 0 || expression[i - 1] == '(')) {
    expression.insert(i, 1, '0');
  }
}

}  // namespace s21
