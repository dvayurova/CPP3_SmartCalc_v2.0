#include "model.h"

namespace s21 {
RPN::RPN(std::string expression) {
  infix_ = expression;
  postfix_ = InfixToPostfix();
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
        postfix.push(stack.top());
        stack.pop();
      }
      stack.pop();
    } else if (operation_priority.find(infix_[i]) != operation_priority.end()) {
      char oper = infix_[i];
      // Унарный минус
      if (oper == '-' &&
          (i == 0 || (i > 1 && operation_priority.find(infix_[i - 1]) !=
                                   operation_priority.end())))
        // Пока  записываем его как тильду
        oper = '~';

      while (!stack.empty() && (operation_priority[stack.top().operation_] >=
                                operation_priority[oper])) {
        postfix.push(stack.top());
        stack.pop();
      }
      stack.push(Lexeme(oper));
    }
  }
  while (!stack.empty()) {
    postfix.push(stack.top());
    stack.pop();
  }
  return postfix;
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

double RPN::Calculation(char operation, double first, double second) {
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

double RPN::GetCalcResult() {
  std::stack<double> stack;
  while (!postfix_.empty()) {
    if (postfix_.front().is_number_) {
      stack.push(postfix_.front().number_);
    } else {
      double second = stack.top();
      stack.pop();
      double first = stack.top();
      stack.pop();
      stack.push(Calculation(postfix_.front().operation_, first, second));
    }
    postfix_.pop();
  }
  return stack.top();
}

} // namespace s21