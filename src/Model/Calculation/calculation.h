#ifndef CPP3_SMARTCALC_V2_MODEL_CALCULATION_CALCULATION_H_
#define CPP3_SMARTCALC_V2_MODEL_CALCULATION_CALCULATION_H_

#include "../Postfix/postfix.h"
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

#endif //  CPP3_SMARTCALC_V2_MODEL_CALCULATION_CALCULATION_H_