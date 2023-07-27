#include "postfix.h"
namespace s21 {

std::queue<Lexeme>
PostfixExpression::ConvertToPostfix(std::string &expression) {
  infix_ = expression;
  for (size_t i = 0; i < infix_.GetLength(); i++) {
    if (std::isdigit(infix_[i])) {
      postfix_.push(Lexeme(infix_.GetNumber(i)));
    } else if (infix_[i] == '(' || infix_[i] == ')') {
      ParseBrackets(i);
    } else {
      ParseOperation(i);
    }
  }
  while (!stack_.empty()) {
    FromStackToPostfix();
  }
  return postfix_;
}

void PostfixExpression::FromStackToPostfix() {
  postfix_.push(stack_.top());
  stack_.pop();
}

void PostfixExpression::ParseOperation(size_t &i) {
  Lexeme lexeme;
  std::string operation{};
  operation = infix_.GetOperation(i);
  while (!stack_.empty() &&
         (lexeme.operation_priority[stack_.top().operation_] >=
          lexeme.operation_priority[operation])) {
    FromStackToPostfix();
  }
  stack_.push(Lexeme(operation));
}

void PostfixExpression::ParseBrackets(size_t &i) {
  std::string operation{};
  if (infix_[i] == '(') {
    operation.push_back(infix_[i]);
    stack_.push(Lexeme(operation));
  } else if (infix_[i] == ')') {
    while (!stack_.empty() && stack_.top().operation_ != "(") {
      FromStackToPostfix();
    }
    stack_.pop();
  }
}

} // namespace s21