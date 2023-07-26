#ifndef SRC_MODEL_CALCULATION_H_
#define SRC_MODEL_CALCULATION_H_

#include "lexeme.h"
#include <cmath>
#include <queue>
#include <stack>

namespace s21 {

class Calculation {
public:
  Calculation() {}
  std::pair<bool, double> GetCalcResult(std::queue<Lexeme> postfix);

private:
  double CalculateArithmetic(std::string operation, double first,
                             double second);
  double GetArithmeticResult(std::queue<Lexeme> &postfix,
                             std::stack<double> &stack);
  double GetFunctionResult(std::queue<Lexeme> &postfix,
                           std::stack<double> &stack);
  bool NeedTwoArguments(std::string &operation);

  bool valid_expression_;
};

} // namespace s21

#include "calculation.cc"
#endif //  SRC_MODEL_MODEL_H_