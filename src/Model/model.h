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
enum Priority { DEFAULT, LOW, MEDIUM, MOD = 2, HIGH, FUNCTION };

class Lexeme {
public:
  Lexeme() {}
  Lexeme(double number) : is_number_(true), number_(number), operation_(""){};
  Lexeme(std::string operation)
      : is_number_(false), number_(0), operation_(operation){};
  bool is_number_;
  double number_;
  std::string operation_;
};

class RPN {
public:
  RPN(std::string expression);
  double GetCalculationResult();

  void Print(); // tmp

private:
  std::string infix_;
  std::queue<Lexeme> postfix_;
  std::map<std::string, Priority> operation_priority = {
      {"(", DEFAULT},     {"+", LOW},         {"-", LOW},
      {"*", MEDIUM},      {"/", MEDIUM},      {"^", HIGH},
      {"cos", FUNCTION},  {"sin", FUNCTION},  {"tan", FUNCTION},
      {"acos", FUNCTION}, {"asin", FUNCTION}, {"atan", FUNCTION},
      {"sqrt", FUNCTION}, {"ln", FUNCTION},   {"log", FUNCTION},
      {"mod", MOD}};

  double GetNumber(size_t &index);
  std::string GetFunction(size_t &index);
  void FromStackToPostfix(std::queue<Lexeme> &postfix,
                          std::stack<Lexeme> &stack);
  void ValidateInfix();
  std::queue<Lexeme> InfixToPostfix();
  double Calculate(std::string operation, double first, double second);
  double GetArithmeticResult(std::stack<double> &stack);
  double GetFunctionResult(std::stack<double> &stack);
  bool NeedTwoArguments(std::string &operation);
};

} // namespace s21

#include "model.cc"
#endif //  SRC_MODEL_MODEL_H_