#include "credit_calc.h"

namespace s21 {
void CreditCalc::GetCreditResult(double amount, int term, double rate,
                                 std::string type) {  // term in month
  amount_ = amount;
  term_ = term;
  rate_ = rate;
  if (type == "annuity") CalcAnnuityPayment();
  if (type == "differ") CalcDifferPayment();
}

void CreditCalc::CalcAnnuityPayment() {
  rate_ /= 12;
  monthly_payment_ = amount_ * ((rate_ * pow((1 + rate_), term_)) /
                                (pow((1 + rate_), term_) - 1));
  overpayment_ = monthly_payment_ * term_ - amount_;
  total_payment_ = amount_ + overpayment_;
}

void CreditCalc::CalcDifferPayment() {
  double month_principal_pay = 0;
  month_principal_pay = amount_ / term_;
  for (int i = 0; i < term_; i++) {
    monthly_payment_ = (amount_ - (month_principal_pay * i)) * rate_ / 12 +
                       month_principal_pay;
    total_payment_ += monthly_payment_;
  }
  monthly_payment_first_ =
      (amount_ - (month_principal_pay * 0)) * rate_ / 12 + month_principal_pay;
  monthly_payment_last_ =
      (amount_ - (month_principal_pay * (term_ - 1))) * rate_ / 12 +
      month_principal_pay;
  overpayment_ = total_payment_ - amount_;
}

}  // namespace s21