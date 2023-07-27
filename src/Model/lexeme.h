#ifndef SRC_MODEL_LEXEME_H_
#define SRC_MODEL_LEXEME_H_

#include <map>
#include <string>

namespace s21 {

enum Priority { DEFAULT, LOW, MEDIUM, MOD = 2, HIGH, FUNCTION };

class Lexeme {
public:
  Lexeme() {}
  Lexeme(double number) : is_number_(true), number_(number), operation_(""){};
  Lexeme(std::string operation)
      : is_number_(false), number_(0), operation_(operation){};

private:
  bool is_number_;
  double number_;
  std::string operation_;
  std::map<std::string, Priority> operation_priority = {
      {"(", DEFAULT},     {"+", LOW},         {"-", LOW},
      {"*", MEDIUM},      {"/", MEDIUM},      {"^", HIGH},
      {"cos", FUNCTION},  {"sin", FUNCTION},  {"tan", FUNCTION},
      {"acos", FUNCTION}, {"asin", FUNCTION}, {"atan", FUNCTION},
      {"sqrt", FUNCTION}, {"ln", FUNCTION},   {"log", FUNCTION},
      {"mod", MOD}};

  friend class Calculation;
  friend class PostfixExpression;
  friend class Validation;
};
} // namespace s21

#endif //  SRC_MODEL_LEXEME_H_