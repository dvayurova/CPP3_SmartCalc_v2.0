#ifndef CPP3_SMARTCALC_V2_MODEL_MODEL_H_
#define CPP3_SMARTCALC_V2_MODEL_MODEL_H_

#include <iostream> // delete
#include <queue>

#include "Calculation/calculation.h"
#include "Postfix/postfix.h"
#include "Validation/validation.h"
#include "lexeme.h"

namespace s21 {

class CalculatorModel {
public:
  CalculatorModel(){};

  std::pair<bool, double> GetResult(std::string &expression) {
    bool is_valid = validation_.IsValid(expression);
    if (!is_valid) {
      return std::pair<bool, double>(is_valid, 0);
    }
    return calculation_.GetCalcResult(postfix_.ConvertToPostfix(expression));
  }

private:
  Validation validation_;
  PostfixExpression postfix_;
  Calculation calculation_;
};

} // namespace s21

#endif //  CPP3_SMARTCALC_V2_MODEL_MODEL_H_
