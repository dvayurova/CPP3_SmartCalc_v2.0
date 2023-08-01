#ifndef CPP3_SMARTCALC_V2_MODEL_MODEL_H_
#define CPP3_SMARTCALC_V2_MODEL_MODEL_H_

#include "Calculation/calculation.h"
#include "Credit/credit_calc.h"

namespace s21 {

class CalculatorModel {
 public:
  CalculatorModel(){};

  std::pair<bool, double> GetResult(std::string &expression,
                                    std::string &x_value);
  bool IsValidExpression(std::string &expression, std::string &x_value);
  double GetYForPlot(double x, std::string &expression);
  std::pair<std::vector<double>, std::vector<double>> GetCoordinates(
      double x_min, double x_max, std::string &expression);
  void CalcAnnuityPayment(CreditCalc &credit);
  void CalcDifferPayment(CreditCalc &credit);
};

}  // namespace s21

#endif  //  CPP3_SMARTCALC_V2_MODEL_MODEL_H_
