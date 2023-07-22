#include "model.h"

namespace s21 {

void Model::InfixToPostfix() {
  std::queue<Lexeme> output;
  for (size_t i = 0; i < expression_.length(); i++) {
    if (std::isdigit(expression_[i])) {
      output.push(s21::Lexeme(GetNumber(i), DEFAULT));
    }
  }
  while (!output.empty()) {
    std::cout << "number_ = " << output.front().number_ << "\n";
    output.pop();
  }
}

void Model::CalculatePostfix() {}

double Model::GetNumber(size_t &index) {
  std::regex double_regex("[-+]?\\d+([.]\\d+)?(e[-+]?\\d+)?");
  std::regex_token_iterator<std::string::iterator> next(
      expression_.begin() + index, expression_.end(), double_regex);
  index += next->length();
  return std::stod(*next);
}

} // namespace s21