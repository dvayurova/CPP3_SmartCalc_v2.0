#include "model.h"

namespace s21 {
RPN::RPN(std::string expression) {
  infix_ = expression;
  ValidateInfix();
  postfix_ = InfixToPostfix();
}

void RPN::ValidateInfix() {
  std::transform(infix_.begin(), infix_.end(), infix_.begin(), ::tolower);
  infix_.erase(remove(infix_.begin(), infix_.end(), ' '), infix_.end());
  for (size_t i = 0; i < infix_.length(); i++) {
    if ((infix_[i] == '-' || infix_[i] == '+') &&
        (i == 0 || infix_[i - 1] == '(')) {
      infix_.insert(i, 1, '0'); // добавляю 0 перед унарным -+
    }
  }
  // std::cout << "\n infix_ string after validation: " << infix_ << " ";
}

double RPN::GetNumber(size_t &index) {
  std::regex double_regex("[-+]?\\d+([.]\\d+)?(e[-+]?\\d+)?");
  std::regex_token_iterator<std::string::iterator> next(
      infix_.begin() + index, infix_.end(), double_regex);
  index += next->length() - 1;
  return std::stod(*next);
}

std::queue<Lexeme> RPN::InfixToPostfix() {
  std::queue<Lexeme> postfix;
  std::stack<Lexeme> stack;

  for (size_t i = 0; i < infix_.length(); i++) {
    if (std::isdigit(infix_[i])) {
      postfix.push(Lexeme(GetNumber(i)));
    } else if (infix_[i] == '(') {
      stack.push(Lexeme(infix_[i]));
    } else if (infix_[i] == ')') {
      while (!stack.empty() && stack.top().operation_ != '(') {
        FromStackToPostfix(postfix, stack);
      }
      stack.pop();
    } else if (operation_priority.find(infix_[i]) != operation_priority.end()) {
      while (!stack.empty() && (operation_priority[stack.top().operation_] >=
                                operation_priority[infix_[i]])) {
        FromStackToPostfix(postfix, stack);
      }
      stack.push(Lexeme(infix_[i]));
    }
  }
  while (!stack.empty()) {
    FromStackToPostfix(postfix, stack);
  }
  return postfix;
}

void RPN::FromStackToPostfix(std::queue<Lexeme> &postfix,
                             std::stack<Lexeme> &stack) {
  postfix.push(stack.top());
  stack.pop();
}

void RPN::Print() {
  while (!postfix_.empty()) {
    if (postfix_.front().is_number_) {
      std::cout << postfix_.front().number_ << " ";
    } else
      std::cout << postfix_.front().operation_ << " ";
    postfix_.pop();
  }
}

double RPN::Calculate(char operation, double first, double second) {
  switch (operation) {
  case '+':
    return first + second;
  case '-':
    return first - second;
  case '*':
    return first * second;
  case '/':
    return first / second;
  case '^':
    return std::pow(first, second);
  }
  return 0;
}

double RPN::GetCalculationResult() {
  double result = 0;
  std::stack<double> stack;
  while (!postfix_.empty()) {
    if (postfix_.front().is_number_) {
      stack.push(postfix_.front().number_);
    } else {
      double second = stack.top();
      stack.pop();
      double first = stack.top();
      stack.pop();
      stack.push(Calculate(postfix_.front().operation_, first, second));
    }
    postfix_.pop();
  }
  result = stack.top();
  return result;
}

} // namespace s21