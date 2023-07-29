#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CREDIT_CREDIT_CALC_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CREDIT_CREDIT_CALC_H_

#include <cmath>
#include <string>

namespace s21 {

class CreditCalc {
 public:
  CreditCalc() {}
  void GetCreditResult(double amount, int term, double rate, std::string type);

 private:
  double amount_;
  int term_;
  double rate_;
  double monthly_payment_;
  double monthly_payment_first_;
  double monthly_payment_last_;

  double monthly_payment_;
  double overpayment_;
  double total_payment_;

  // Выход: ежемесячный платеж, переплата по кредиту, общая выплата
  void CalcAnnuityPayment();
  void CalcDifferPayment();
};

}  // namespace s21

#endif  //  CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CREDIT_CREDIT_CALC_H_