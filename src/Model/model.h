#ifndef CPP3_SMARTCALC_V2_MODEL_MODEL_H_
#define CPP3_SMARTCALC_V2_MODEL_MODEL_H_

#include "Calculation/calculation.h"
#include "Credit/credit_calc.h"

namespace s21 {

class CalculatorModel {
public:
  CalculatorModel(){};

  std::pair<bool, double> GetResult(std::string &expression,
                                    std::string &x_value) {
    PostfixExpression postfix{};
    Calculation calculation{};
    bool is_valid = IsValidExpression(expression, x_value);
    if (!is_valid) {
      return std::pair<bool, double>(is_valid, 0);
    }

    return calculation.GetCalcResult(
        postfix.ConvertToPostfix(expression, x_value));
  }

  bool IsValidExpression(std::string &expression, std::string &x_value) {
    Validation validation{};
    return validation.IsValid(expression, x_value);
  }

  double GetYForPlot(double x, std::string &expression) {
    PostfixExpression postfix{};
    Calculation calculation{};
    std::string x_value = std::to_string(x);
    return calculation
        .GetCalcResult(postfix.ConvertToPostfix(expression, x_value))
        .second;
  }

  std::pair<std::vector<double>, std::vector<double>>
  GetCoordinates(double x_min, double x_max, std::string &expression) {
    std::pair<std::vector<double>, std::vector<double>> coordinates{};
    std::string x_value = "1";
    double step = (x_max - x_min) / 1000.0;
    if (IsValidExpression(expression, x_value)) {
      for (double x = x_min; x <= x_max; x += step) {
        double y = GetYForPlot(x, expression);
        coordinates.first.push_back(x);
        coordinates.second.push_back(y);
      }
    }
    return coordinates;
  }

  void CalcAnnuityPayment(CreditCalc &credit) { credit.CalcAnnuityPayment(); }
  void CalcDifferPayment(CreditCalc &credit) { credit.CalcDifferPayment(); }
};

} // namespace s21

#endif //  CPP3_SMARTCALC_V2_MODEL_MODEL_H_
