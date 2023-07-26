#include "model.h"

namespace s21 {
RPN::RPN(std::string expression) {
  infix_ = expression;
  valid_expression_ = true;
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
  // std::cout << "num: " << *next << "\n";
  return std::stod(*next);
}

std::string RPN::GetFunction(size_t &index) {
  std::regex function_regex("([a-z]+)");
  std::regex_token_iterator<std::string::iterator> next(
      infix_.begin() + index, infix_.end(), function_regex);
  index += next->length() - 1;
  return *next;
}

std::queue<Lexeme> RPN::InfixToPostfix() {
  std::queue<Lexeme> postfix;
  std::stack<Lexeme> stack;

  for (size_t i = 0; i < infix_.length() && valid_expression_; i++) {
    std::string operation{};
    if (std::isdigit(infix_[i])) {
      postfix.push(Lexeme(GetNumber(i)));
    } else if (infix_[i] == '(') {
      operation.push_back(infix_[i]);
      stack.push(Lexeme(operation));
    } else if (infix_[i] == ')') {
      while (!stack.empty() && stack.top().operation_ != "(") {
        FromStackToPostfix(postfix, stack);
      }
      if (!stack.empty() && stack.top().operation_ == "(") {
        stack.pop();
      } else {
        valid_expression_ = false;
      }
    } else {
      if (std::isalpha(infix_[i])) {
        operation = GetFunction(i);
      } else {
        operation.push_back(infix_[i]);
      }
      // std::cout << "operation = " << operation << "\n";
      if (operation_priority.find(operation) != operation_priority.end()) {
        while (!stack.empty() && (operation_priority[stack.top().operation_] >=
                                  operation_priority[operation])) {
          FromStackToPostfix(postfix, stack);
        }
        stack.push(Lexeme(operation));
      } else {
        // std::cout << "incorrect oper = " << operation << "\n ";
        valid_expression_ = false;
      }
    }
  }
  while (!stack.empty()) {
    if (stack.top().operation_ == "(")
      valid_expression_ = false;
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

double RPN::CalculateArithmetic(std::string operation, double first,
                                double second) {
  if (operation == "+")
    return first + second;
  else if (operation == "-")
    return first - second;
  else if (operation == "*")
    return first * second;
  else if (operation == "/")
    return first / second;
  else if (operation == "^")
    return std::pow(first, second);
  else if (operation == "mod")
    return std::fmod(first, second);
  return 0;
}

bool RPN::NeedTwoArguments(std::string &operation) {
  if (operation_priority[operation] == FUNCTION) {
    return false;
  }
  return true;
}

double RPN::GetArithmeticResult(std::stack<double> &stack) {
  double result, second, first = 0;
  if (!stack.empty()) {
    second = stack.top();
    stack.pop();
  } else
    valid_expression_ = false;
  if (!stack.empty()) {
    first = stack.top();
    stack.pop();
  } else
    valid_expression_ = false;
  result = CalculateArithmetic(postfix_.front().operation_, first, second);
  return result;
}

double RPN::GetFunctionResult(std::stack<double> &stack) {
  double result = 0;
  double number = stack.top();
  stack.pop();
  if (postfix_.front().operation_ == "cos") {
    result = std::cos(number);
  } else if (postfix_.front().operation_ == "sin") {
    result = std::sin(number);
  } else if (postfix_.front().operation_ == "tan") {
    result = std::tan(number);
  } else if (postfix_.front().operation_ == "acos") {
    result = std::acos(number);
  } else if (postfix_.front().operation_ == "asin") {
    result = std::asin(number);
  } else if (postfix_.front().operation_ == "atan") {
    result = std::atan(number);
  } else if (postfix_.front().operation_ == "sqrt") {
    result = std::sqrt(number);
  } else if (postfix_.front().operation_ == "ln") {
    result = std::log(number);
  } else if (postfix_.front().operation_ == "log") {
    result = std::log10(number);
  }
  return result;
}

std::pair<bool, double> RPN::GetCalculationResult() {
  double result = 0;
  if (!valid_expression_)
    return std::pair<bool, double>(valid_expression_, result);
  std::stack<double> stack;
  while (!postfix_.empty()) {
    if (postfix_.front().is_number_) {
      stack.push(postfix_.front().number_);
    } else if (NeedTwoArguments(postfix_.front().operation_)) {
      stack.push(GetArithmeticResult(stack));
    } else {
      stack.push(GetFunctionResult(stack));
    }
    postfix_.pop();
  }
  if (!stack.empty())
    result = stack.top();
  else
    valid_expression_ = false;
  // std::cout << "is valid = " << valid_expression_ << "\n";
  return std::pair<bool, double>(valid_expression_, result);
}

} // namespace s21