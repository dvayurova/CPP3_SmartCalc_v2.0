#include "model.h"

int main() {
  // s21::RPN model("155 + 1.56 + 2.88 - 1.32e+12-sin+ 4.0 - 1e-10 + ln10");
  // s21::RPN model("-1 - 5 / 6 * 2 + (-9 -3) * 2^4^0.5 ");
  // s21::RPN model("15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
  //                "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))");
  s21::RPN model("-2^2^2^(-4/5) ");
  // model.Print();
  std::cout << "\n res = " << model.GetCalculationResult();
  return 0;
}