#ifndef SRC_MODEL_MODEL_H_
#define SRC_MODEL_MODEL_H_

#include <iostream> // delete
#include <queue>

#include "calculation.h"
#include "lexeme.h"
#include "postfix.h"
#include "validation.h"

namespace s21 {

class CalculatorModel {
public:
  CalculatorModel(std::string expression) : expression_(expression){};

  std::pair<bool, double> GetResult() {
    bool is_valid = validation_.IsValid(expression_);
    // std::cout << "\n string after valid = " << expression_ << "\n";
    if (!is_valid) {
      return std::pair<bool, double>(is_valid, 0);
    }
    return calculation_.GetCalcResult(postfix_.ConvertToPostfix(expression_));
  }

private:
  std::string expression_;
  Validation validation_;
  PostfixExpression postfix_;
  Calculation calculation_;
};

} // namespace s21

#endif //  SRC_MODEL_MODEL_H_