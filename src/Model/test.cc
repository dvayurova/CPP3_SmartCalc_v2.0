#include "model.h"

int main() {
  // s21::RPN model("155 + 1.56 + 2.88 - 1.32e+12 - sin+ 4.0 - 1e-10 + ln10");
  // s21::RPN model("-(1 - 5 / 6 * 2 + (-9 -3)) * 2^4^0.5 ");
  // s21::RPN model("15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
  //                "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))");
  // s21::RPN model(
  //     " 2.34/(2.12))+2.3@/(2..7-(2.5.6-1.9..7)))^2.32^2.666 + sin(0)");
  // model.Print();

  // s21::CalculatorModel model("sin(20)");

  // s21::CalculatorModel model("289.1 + 234.2 * 4");
  s21::CalculatorModel model("+");
  std::pair<bool, double> res = model.GetResult();
  std::cout << "\n res = " << res.second;
  std::cout << "\n res valid = " << res.first;
  return 0;
}

// #include <iostream>
// #include <string>

// int main() {
//   std::string str = "1+ 2 - 5";
//   for (int i = 0; i < str.length(); i++) {
//     std::string tmp{};
//     tmp.push_back(str[i]);
//     std::cout << "i = " << i << " str: " << tmp << "\n";
//   }
//   return 0;
// }