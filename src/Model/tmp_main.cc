#include "model.h"

int main() {
  s21::Model model("155 + 1.56 + 2.88 - 1.32e+12-sin+ 4.0 - 1e-10 + ln10");
  model.InfixToPostfix();
  return 0;
}