#ifndef SRC_MODEL_MODEL_H_
#define SRC_MODEL_MODEL_H_

#include <cmath>
#include <iostream> // delete
#include <map>
#include <queue>
#include <regex>
#include <stack>
#include <string>

namespace s21 {
enum Priority { DEFAULT, LOW, MEDIUM, HIGH, UNARY };

class Lexeme {
public:
  Lexeme() {}
  Lexeme(double number) : is_number_(true), number_(number), operation_(0){};
  Lexeme(char operation)
      : is_number_(false), number_(0), operation_(operation){};
  bool is_number_;
  double number_;
  char operation_;
};

class RPN {
public:
  RPN(std::string expression);
  std::queue<Lexeme> InfixToPostfix();
  void Print();
  double Calculation(char operation, double first, double second);
  double GetCalcResult();

private:
  std::string infix_;
  std::queue<Lexeme> postfix_;
  std::map<char, Priority> operation_priority = {
      {'(', DEFAULT}, {'+', LOW},  {'-', LOW},  {'*', MEDIUM},
      {'/', MEDIUM},  {'^', HIGH}, {'~', UNARY} // Унарный минус
  };

  double GetNumber(size_t &index);
};

} // namespace s21

#include "model.cc"
#endif //  SRC_MODEL_MODEL_H_