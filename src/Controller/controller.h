#ifndef CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H
#define CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H

#include "../Model/model.h"

namespace s21 {

class Controller {
public:
  Controller(CalculatorModel *model) : model_(model) {}
  std::pair<bool, double> GetMainCalcResult(std::string expression) {
    return model_->GetResult(expression);
  }

private:
  CalculatorModel *model_;
};

} // namespace s21
#endif // CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H
