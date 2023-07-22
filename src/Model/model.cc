#include "model.h"

namespace s21 {

void Model::InfixToPostfix() {
  std::queue<Lexeme> output;
  for (size_t i = 0; i < expression_.length(); i++) {
    if (std::isdigit(expression_[i])) {
      output.push(Lexeme(GetNumber(i)));
    } else {
      PushOperator(i, output);
    }
  }
  while (!output.empty()) {
    if (output.front().is_number_) {
      std::cout << output.front().number_ << "\n";
    } else
      std::cout << output.front().operation_ << "\n";
    output.pop();
  }
}

void Model::CalculatePostfix() {}

double Model::GetNumber(size_t &index) {
  std::regex double_regex("[-+]?\\d+([.]\\d+)?(e[-+]?\\d+)?");
  std::regex_token_iterator<std::string::iterator> next(
      expression_.begin() + index, expression_.end(), double_regex);
  index += next->length() - 1;
  return std::stod(*next);
}

std::string Model::GetFunction(size_t &index) {
  std::regex function_regex("([a-z]+)");
  std::regex_token_iterator<std::string::iterator> next(
      expression_.begin() + index, expression_.end(), function_regex);
  index += next->length() - 1;
  return *next;
}

void Model::GetOperation(size_t &index, std::queue<Lexeme> &output) {
  if (expression_[index] == '+')
    output.push(Lexeme("+", LOW));
  if (expression_[index] == '-')
    output.push(Lexeme("-", LOW));
  if (expression_[index] == '*')
    output.push(Lexeme("*", MEDIUM));
  if (expression_[index] == '/')
    output.push(Lexeme("/", MEDIUM));
  if (expression_[index] == '^')
    output.push(Lexeme("^", HIGH));
}

void Model::PushOperator(size_t &index, std::queue<Lexeme> &output) {
  if (std::isalpha(expression_[index])) {
    Lexeme tmp(GetFunction(index));
    output.push(tmp);
  } else {
    GetOperation(index, output);
  }
}
} // namespace s21