#include "model.h"

namespace s21 {

std::pair<bool, double> CalculatorModel::GetResult(std::string &expression,
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

bool CalculatorModel::IsValidExpression(std::string &expression,
                                        std::string &x_value) {
  Validation validation{};
  return validation.IsValid(expression, x_value);
}

double CalculatorModel::GetYForPlot(double x, std::string &expression) {
  PostfixExpression postfix{};
  Calculation calculation{};
  std::string x_value = std::to_string(x);
  return calculation
      .GetCalcResult(postfix.ConvertToPostfix(expression, x_value))
      .second;
}

std::pair<std::vector<double>, std::vector<double>>
CalculatorModel::GetCoordinates(double x_min, double x_max,
                                std::string &expression) {
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

void CalculatorModel::CalcAnnuityPayment(CreditCalc &credit) {
  credit.CalcAnnuityPayment();
}
void CalculatorModel::CalcDifferPayment(CreditCalc &credit) {
  credit.CalcDifferPayment();
}

}  // namespace s21