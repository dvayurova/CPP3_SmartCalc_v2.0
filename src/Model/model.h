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
    if (is_valid) {
      // std::cout << "is_valid: " << is_valid << "\n";
      return calculation_.GetCalcResult(postfix_.ConvertToPostfix(expression_));
    }
    return std::pair<bool, double>(is_valid, 0);
  }

private:
  std::string expression_;
  Validation validation_;
  PostfixExpression postfix_;
  Calculation calculation_;
};

} // namespace s21

#endif //  SRC_MODEL_MODEL_H_