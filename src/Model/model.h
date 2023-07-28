#ifndef CPP3_SMARTCALC_V2_MODEL_MODEL_H_
#define CPP3_SMARTCALC_V2_MODEL_MODEL_H_

#include <queue>

#include "Calculation/calculation.h"

namespace s21 {

class CalculatorModel {
 public:
  CalculatorModel(){};

  std::pair<bool, double> GetResult(std::string& expression,
                                    std::string& x_value) {
    bool is_valid = validation_.IsValid(expression, x_value);
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

}  // namespace s21

#endif  //  CPP3_SMARTCALC_V2_MODEL_MODEL_H_
