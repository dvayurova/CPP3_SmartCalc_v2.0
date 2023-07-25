#ifndef SRC_MODEL_MODEL_H_
#define SRC_MODEL_MODEL_H_

#include <cmath>
#include <iostream>  // delete
#include <map>
#include <queue>
#include <regex>
#include <stack>
#include <string>

namespace s21 {
enum Priority { DEFAULT, LOW, MEDIUM, HIGH };

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
  double GetCalculationResult();

  void Print();  // tmp

 private:
  std::string infix_;
  std::queue<Lexeme> postfix_;
  std::map<char, Priority> operation_priority = {{'(', DEFAULT}, {'+', LOW},
                                                 {'-', LOW},     {'*', MEDIUM},
                                                 {'/', MEDIUM},  {'^', HIGH}};

  double GetNumber(size_t &index);
  void FromStackToPostfix(std::queue<Lexeme> &postfix,
                          std::stack<Lexeme> &stack);
  void ValidateInfix();
  std::queue<Lexeme> InfixToPostfix();
  double Calculate(char operation, double first, double second);
};

}  // namespace s21

#include "model.cc"
#endif  //  SRC_MODEL_MODEL_H_