#include "credit_calc.h"

#include <cmath>

namespace s21 {

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

double CreditCalc::GetMonthlyPayment() { return monthly_payment_; }
double CreditCalc::GetOverpayment() { return overpayment_; }
double CreditCalc::GetTotalPayment() { return total_payment_; }
double CreditCalc::GetFirstPayment() { return monthly_payment_first_; }
double CreditCalc::GetLastPayment() { return monthly_payment_last_; }

}  // namespace s21