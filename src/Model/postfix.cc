#include "postfix.h"
namespace s21 {

std::queue<Lexeme>
PostfixExpression::ConvertToPostfix(std::string &expression) {
  std::stack<Lexeme> stack;
  infix_ = expression;

  for (size_t i = 0; i < infix_.GetLength(); i++) {
    std::string operation{};
    if (std::isdigit(infix_[i])) {
      postfix_.push(Lexeme(infix_.GetNumber(i)));
    } else if (infix_[i] == '(' || infix_[i] == ')') {
      ParseBrackets(stack, i);
    } else {
      operation = infix_.GetOperation(i);
      while (!stack.empty() &&
             (lexeme_.operation_priority[stack.top().operation_] >=
              lexeme_.operation_priority[operation])) {
        FromStackToPostfix(stack);
      }
      stack.push(Lexeme(operation));
    }
  }
  while (!stack.empty()) {
    FromStackToPostfix(stack);
  }
  return postfix_;
}

void PostfixExpression::FromStackToPostfix(std::stack<Lexeme> &stack) {
  postfix_.push(stack.top());
  stack.pop();
}

void PostfixExpression::ParseBrackets(std::stack<Lexeme> &stack, size_t &i) {
  std::string operation{};
  if (infix_[i] == '(') {
    operation.push_back(infix_[i]);
    stack.push(Lexeme(operation));
  } else if (infix_[i] == ')') {
    while (!stack.empty() && stack.top().operation_ != "(") {
      FromStackToPostfix(stack);
    }
    stack.pop();
  }
}

void PostfixExpression::Print() {
  while (!postfix_.empty()) {
    if (postfix_.front().is_number_) {
      std::cout << postfix_.front().number_ << " ";
    } else
      std::cout << postfix_.front().operation_ << " ";
    postfix_.pop();
  }
}

} // namespace s21