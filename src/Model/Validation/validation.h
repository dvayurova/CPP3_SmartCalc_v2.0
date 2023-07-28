#ifndef CPP3_SMARTCALC_V2_MODEL_VALIDATION_VALIDATION_H_
#define CPP3_SMARTCALC_V2_MODEL_VALIDATION_VALIDATION_H_

#include <stack>

#include "../infix.h"
#include "../lexeme.h"

namespace s21 {

class Validation {
 public:
  Validation() {}
  bool IsValid(std::string &expression, std::string &x_value);

 private:
  Infix infix_;
  std::string expression_;
  std::stack<Lexeme> stack_;
  void ReplaceXToValue();
  void PrepareExpression();
  void AddAsterisk(size_t &i);
  void AddZeroToUnarySign(size_t &i);
  bool CheckBrackets(size_t &i);
  bool IsOperation(size_t &i);
  bool CheckExtraBrackets();
  void ReplaceXToValue(std::string &x_value);
};

}  // namespace s21
// #include "validation.cc"
#endif  //  CPP3_SMARTCALC_V2_MODEL_VALIDATION_VALIDATION_H_