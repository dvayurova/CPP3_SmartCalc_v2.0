#ifndef CPP3_SMARTCALC_V2_MODEL_CREDIT_CREDIT_CALC_H_
#define CPP3_SMARTCALC_V2_MODEL_CREDIT_CREDIT_CALC_H_

#include <string>

namespace s21 {

class CreditCalc {
public:
  CreditCalc(double amount, int term, double rate)
      : amount_(amount), term_(term), rate_(rate), monthly_payment_first_(0),
        monthly_payment_last_(0), monthly_payment_(0), overpayment_(0),
        total_payment_(0) {}
  double GetMonthlyPayment();
  double GetOverpayment();
  double GetTotalPayment();
  double GetFirstPayment();
  double GetLastPayment();
  void CalcAnnuityPayment();
  void CalcDifferPayment();

private:
  double amount_;
  int term_;
  double rate_;
  double monthly_payment_first_;
  double monthly_payment_last_;
  double monthly_payment_;
  double overpayment_;
  double total_payment_;
};

} // namespace s21

#endif //  CPP3_SMARTCALC_V2_MODEL_CREDIT_CREDIT_CALC_H_