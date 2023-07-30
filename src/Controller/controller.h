#ifndef CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H
#define CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H

#include "../Model/model.h"

#include <iostream>

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

private:
  CalculatorModel *model_;
};

} // namespace s21
#endif // CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H
