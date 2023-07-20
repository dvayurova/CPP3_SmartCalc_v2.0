#ifndef SRC_MODEL_MODEL_H_
#define SRC_MODEL_MODEL_H_

#include <regex>
#include <stack>
#include <string>

// namespace s21 {

class Model {
public:
  Model() : expression_(""), result_(0) {}
  Model(std::string input_string) : expression_(input_string), result_(0) {}
  void Parser();
  void GetNumber();

private:
  std::string expression_;
  double result_;
  // std::stack<double> number_stack_;
  // std::stack<std::string> operator_stack_;
};

#include "model.cc"
// } // namespace s21
#endif //  SRC_MODEL_MODEL_H_