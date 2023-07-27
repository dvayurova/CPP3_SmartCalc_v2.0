#include "calculation.h"

namespace s21 {

double Calculation::CalculateArithmetic(std::string operation, double first,
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

bool Calculation::NeedTwoArguments(std::string &operation) {
  Lexeme lexeme;
  if (lexeme.operation_priority[operation] == FUNCTION) {
    return false;
  }
  return true;
}

double Calculation::GetArithmeticResult(std::queue<Lexeme> &postfix,
                                        std::stack<double> &stack) {
  double result = 0.0;
  double second = 0.0;
  double first = 0.0;
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
  result = CalculateArithmetic(postfix.front().operation_, first, second);
  return result;
}

double Calculation::GetFunctionResult(std::queue<Lexeme> &postfix,
                                      std::stack<double> &stack) {
  double result, number = 0;
  if (!stack.empty()) {
    number = stack.top();
    stack.pop();
  } else
    valid_expression_ = false;
  if (postfix.front().operation_ == "cos") {
    result = std::cos(number);
  } else if (postfix.front().operation_ == "sin") {
    result = std::sin(number);
  } else if (postfix.front().operation_ == "tan") {
    result = std::tan(number);
  } else if (postfix.front().operation_ == "acos") {
    result = std::acos(number);
  } else if (postfix.front().operation_ == "asin") {
    result = std::asin(number);
  } else if (postfix.front().operation_ == "atan") {
    result = std::atan(number);
  } else if (postfix.front().operation_ == "sqrt") {
    result = std::sqrt(number);
  } else if (postfix.front().operation_ == "ln") {
    result = std::log(number);
  } else if (postfix.front().operation_ == "log") {
    result = std::log10(number);
  }
  return result;
}

std::pair<bool, double> Calculation::GetCalcResult(std::queue<Lexeme> postfix) {
  double result = 0;
  valid_expression_ = true;
  std::stack<double> stack;

  while (!postfix.empty() && valid_expression_) {
    if (postfix.front().is_number_) {
      stack.push(postfix.front().number_);
    } else if (NeedTwoArguments(postfix.front().operation_)) {
      stack.push(GetArithmeticResult(postfix, stack));
    } else {
      stack.push(GetFunctionResult(postfix, stack));
    }
    postfix.pop();
  }
  if (!stack.empty())
    result = stack.top();
  return std::pair<bool, double>(valid_expression_, result);
}

} // namespace s21