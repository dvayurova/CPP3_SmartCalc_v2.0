#ifndef CPP3_SMARTCALC_V2_CONTROLLER_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_CONTROLLER_CONTROLLER_H_

#include "../Model/model.h"

namespace s21 {

class Controller {
public:
  Controller(CalculatorModel *model) : model_(model) {}

  std::pair<bool, double> GetMainCalcResult(std::string expression,
                                            std::string x_value) {
    std::pair<bool, double> res = {0, 0};
    res = model_->GetResult(expression, x_value);
    return res;
  }

  std::pair<std::vector<double>, std::vector<double>>
  GetCoordinates(double x_min, double x_max, std::string &expression) {
    return model_->GetCoordinates(x_min, x_max, expression);
  }

  void GetAnnuityPayment(CreditCalc &credit) {
    model_->CalcAnnuityPayment(credit);
  }

  void GetDifferPayment(CreditCalc &credit) {
    model_->CalcDifferPayment(credit);
  }

private:
  CalculatorModel *model_;
};

} // namespace s21
#endif // CPP3_SMARTCALC_V2_CONTROLLER_CONTROLLER_H_
