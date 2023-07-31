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
  std::stack<Lexeme> stack_;
  void PrepareExpression(std::string &expression);
  void AddAsterisk(std::string &expression, size_t &i);
  void AddZeroToUnarySign(std::string &expression, size_t &i);
  bool CheckBrackets(size_t &i);
  bool IsOperation(size_t &i);
  bool CheckExtraBrackets();
  void ReplaceXToValue(std::string &expression, std::string &x_value);
  bool CheckXValue(std::string &x_value);
};

} // namespace s21

#endif //  CPP3_SMARTCALC_V2_MODEL_VALIDATION_VALIDATION_H_