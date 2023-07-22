#ifndef SRC_MODEL_MODEL_H_
#define SRC_MODEL_MODEL_H_

#include <iostream> // delete
#include <queue>
#include <regex>
#include <stack>
#include <string>

namespace s21 {
enum Priority { DEFAULT, LOW, MEDIUM, HIGH };

class Lexeme {

public:
  Lexeme() {}
  Lexeme(double number)
      : is_number_(true), number_(number), operation_(""), priority_(DEFAULT){};
  Lexeme(std::string operation)
      : is_number_(false), number_(0), operation_(operation),
        priority_(MEDIUM){};
  Lexeme(std::string operation, Priority priority)
      : is_number_(false), number_(0), operation_(operation),
        priority_(priority){};
  bool is_number_;
  double number_;
  std::string operation_;
  Priority priority_;
};

class Model {

public:
  Model() : expression_(""), result_(0) {}
  Model(std::string input_string) : expression_(input_string), result_(0) {}

  void InfixToPostfix();
  void CalculatePostfix();
  double GetNumber(size_t &index);
  std::string GetFunction(size_t &index);
  void GetOperation(size_t &index, std::queue<Lexeme> &output);
  void PushOperator(size_t &index, std::queue<Lexeme> &output);

private:
  std::string expression_;
  double result_;
};

} // namespace s21

#include "model.cc"
#endif //  SRC_MODEL_MODEL_H_