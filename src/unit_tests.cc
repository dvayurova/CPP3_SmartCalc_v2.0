#include <gtest/gtest.h>

#include <cmath>
#include <string>

#include "Model/Credit/credit_calc.h" // delete
#include "Model/model.h"

TEST(ModelTest, Case0) {
  std::string expression = "2^3^2";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_DOUBLE_EQ(512, model.GetResult(expression, x_value).second);
}

TEST(ModelTest, Case1) {
  std::string expression = "289.1+234.2*4";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_DOUBLE_EQ(1225.9, model.GetResult(expression, x_value).second);
}

TEST(ModelTest, Case2) {
  std::string expression = "-2^2^2^(-4/5)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_DOUBLE_EQ(-2.8069543430559577,
                   model.GetResult(expression, x_value).second);
}

TEST(ModelTest, Case3) {
  std::string expression = "2.5-0.5";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_DOUBLE_EQ(2.0, model.GetResult(expression, x_value).second);
}

TEST(ModelTest, Case4) {
  std::string expression = "-1.9+(-777.1)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_DOUBLE_EQ(-779, model.GetResult(expression, x_value).second);
}

TEST(ModelTest, Case5) {
  std::string expression = "-2.12345-1000.000003";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_DOUBLE_EQ(-1002.123453, model.GetResult(expression, x_value).second);
}

TEST(ModelTest, Case6) {
  std::string expression = "-2.78941-(-995.258964)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_DOUBLE_EQ(992.469554, model.GetResult(expression, x_value).second);
}

TEST(ModelTest, Case7) {
  std::string expression = "100000-(-20249.654684)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_DOUBLE_EQ(120249.654684, model.GetResult(expression, x_value).second);
}

TEST(ModelTest, Case8) {
  std::string expression = "122.1*82327.9";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_DOUBLE_EQ(10052236.59, model.GetResult(expression, x_value).second);
}

TEST(ModelTest, Case9) {
  std::string expression = "-1.9*(-13227.1)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_DOUBLE_EQ(25131.49, model.GetResult(expression, x_value).second);
}

TEST(ModelTest, Case10) {
  std::string expression = "1+0.4";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_DOUBLE_EQ(1.4, model.GetResult(expression, x_value).second);
}

TEST(ModelTest, Case11) {
  std::string expression = "25/5";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_DOUBLE_EQ(5, model.GetResult(expression, x_value).second);
}

TEST(ModelTest, Case12) {
  std::string expression = "22^3";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_DOUBLE_EQ(10648, model.GetResult(expression, x_value).second);
}

TEST(ModelTest, Case13) {
  std::string expression = "10mod3";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_DOUBLE_EQ(1, model.GetResult(expression, x_value).second);
}

TEST(ModelTest, Case14) {
  std::string expression = "cos(30)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_NEAR(0.154251449888, model.GetResult(expression, x_value).second,
              1e-6);
}

TEST(ModelTest, Case15) {
  std::string expression = "sin(45)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_NEAR(0.850903524534, model.GetResult(expression, x_value).second,
              1e-6);
}

TEST(ModelTest, Case16) {
  std::string expression = "tan(90)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_NEAR(-1.995200412208, model.GetResult(expression, x_value).second,
              1e-6);
}

TEST(ModelTest, Case17) {
  std::string expression = "acos(-0.3)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_NEAR(1.8754889, model.GetResult(expression, x_value).second, 1e-6);
}

TEST(ModelTest, Case18) {
  std::string expression = "asin(0.5)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_NEAR(0.5235988, model.GetResult(expression, x_value).second, 1e-6);
}

TEST(ModelTest, Case19) {
  std::string expression = "atan(1)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_NEAR(0.7853981, model.GetResult(expression, x_value).second, 1e-6);
}

TEST(ModelTest, Case20) {
  std::string expression = "sqrt(9)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_DOUBLE_EQ(3, model.GetResult(expression, x_value).second);
}

TEST(ModelTest, Case21) {
  std::string expression = "ln(99)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_NEAR(4.5951198, model.GetResult(expression, x_value).second, 1e-6);
}

TEST(ModelTest, Case22) {
  std::string expression = "log(100)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_NEAR(2, model.GetResult(expression, x_value).second, 1e-6);
}

TEST(ModelTest, Case23) {
  std::string expression =
      "(-0.5-0.375)/1/8-(-9.125*(-0.21))+(345000125-315752568)/"
      "(-458.3258)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_NEAR(-63815.9261298373886, model.GetResult(expression, x_value).second,
              1e-6);
}

TEST(ModelTest, Case24) {
  std::string expression =
      "(17*1/5*0.125-(2*32/45-1/7/60))*(11/40/4*7/12+2.64)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_NEAR(-2.666278232473545, model.GetResult(expression, x_value).second,
              1e-6);
}

TEST(ModelTest, Case25) {
  std::string expression = "log(2)+(-1/2)*log(8)-ln(4*sqrt(8))";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_NEAR(-2.57653012979, model.GetResult(expression, x_value).second,
              1e-6);
}

TEST(ModelTest, Case26) {
  std::string expression =
      "(cos(70)+cos(50))*(cos(310)+cos(290))-(sin(-40)+sin(-60))";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_NEAR(0.49956901475, model.GetResult(expression, x_value).second, 1e-6);
}

TEST(ModelTest, Case27) {
  std::string expression = "sin(cos(ln(sqrt(4))))";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_NEAR(0.69558863622, model.GetResult(expression, x_value).second, 1e-6);
}

TEST(ModelTest, Case28) {
  std::string expression = "-1.0/(-3.0)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_NEAR(0.3333333333333333, model.GetResult(expression, x_value).second,
              1e-6);
}

TEST(ModelTest, Case29) {
  std::string expression = "tan(-85)*tan(15)+asin(0.8)-acos(1)/"
                           "atan(0.5)+acos(-0.3)+asin(-0.7)*atan(-0.5)";
  std::string x_value = "";
  s21::CalculatorModel model;
  ASSERT_NEAR(3.31540708, model.GetResult(expression, x_value).second, 1e-6);
}

TEST(ModelTest, Case30) {
  std::string expression = "(2^8+2^(-5))*(sqrt(144)/(-2))";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_NEAR(-1536.1875, model.GetResult(expression, x_value).second, 1e-6);
}

TEST(ModelTest, Case31) {
  std::string expression = "((4.625-13/18*9/26)/2*0.25+2*0.5/1.25/6*3/4)/53/68";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_NEAR(0.00017948806, model.GetResult(expression, x_value).second, 1e-6);
}

TEST(ModelTest, Case32) {
  std::string expression = "4";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_DOUBLE_EQ(4, model.GetResult(expression, x_value).second);
}

TEST(ModelTest, Case33) {
  std::string expression = "2(5)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_DOUBLE_EQ(10, model.GetResult(expression, x_value).second);
}

TEST(ModelTest, CaseExtraParenthesis) {
  std::string expression = "sin(1)^2+cos(2)^2)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression1) {
  std::string expression = "error:expression-incorrect";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression2) {
  std::string expression = "+";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression3) {
  std::string expression = "4x*2)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression4) {
  std::string expression = "log(x/)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression5) {
  std::string expression = "log(10+)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression6) {
  std::string expression = "atan(1)^/2";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression7) {
  std::string expression = "tan(1)*+2";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression8) {
  std::string expression = "10mod)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression9) {
  std::string expression = "sqrt(*x)^2+cos(x)^2)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression10) {
  std::string expression = "asin-x)^2+cos(x)^2)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression11) {
  std::string expression = "acos(x)^2+aspos(x)^2)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression12) {
  std::string expression = "ton(x)^2+cos(x)^2)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression13) {
  std::string expression = "sin+x^2+cos(x)^2)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression14) {
  std::string expression = "sin(x)^2+cos*x)^2)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression15) {
  std::string expression = "sin(x)^2+cosx)^2)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression16) {
  std::string expression = "sim(1)";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression17) {
  std::string expression = ".-2";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression18) {
  std::string expression = "53435..345-2";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression19) {
  std::string expression = "2.2324.243+5";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression20) {
  std::string expression = "sin()";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression21) {
  std::string expression = "()";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression22) {
  std::string expression = "1.2.3+3";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, IncorrectExpression23) {
  std::string expression = "+-+-+-+-+-+-";
  std::string x_value = "0";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, CaseX1) {
  std::string expression = "(x^2+x^3+x^4+x^5+x^6+x^7+x^8+x^9)*5/(sqrt(900))";
  std::string x_value = "1.56";
  s21::CalculatorModel model;
  ASSERT_NEAR(24.679983485, model.GetResult(expression, x_value).second, 1e-6);
}

TEST(ModelTest, CaseX2) {
  std::string expression = "(-x-(-x))*x-(x)/x+1";
  std::string x_value = "5";
  s21::CalculatorModel model;
  ASSERT_NEAR(0, model.GetResult(expression, x_value).second, 1e-6);
}

TEST(ModelTest, CaseX3) {
  std::string expression = "sin(x)^2+cos(x)^2";
  std::string x_value = "1";
  s21::CalculatorModel model;
  ASSERT_NEAR(1, model.GetResult(expression, x_value).second, 1e-6);
}

TEST(ModelTest, CaseX4) {
  std::string expression = "x*x";
  std::string x_value = "2";
  s21::CalculatorModel model;
  ASSERT_NEAR(4, model.GetResult(expression, x_value).second, 1e-6);
}

TEST(ModelTest, CaseX5) {
  std::string expression = "3*x";
  std::string x_value = "2";
  s21::CalculatorModel model;
  ASSERT_NEAR(6, model.GetResult(expression, x_value).second, 1e-6);
}

TEST(ModelTest, CaseXIncorrect1) {
  std::string expression = "sin(x)^2+cos(x)^2)";
  std::string x_value = "1";
  s21::CalculatorModel model;
  ASSERT_FALSE(model.GetResult(expression, x_value).first);
}

TEST(ModelTest, Case55) {
  std::string expression = "x^2";
  std::string x_value = "-5";
  s21::CalculatorModel model;
  ASSERT_TRUE(model.GetResult(expression, x_value).first);
  ASSERT_DOUBLE_EQ(25, model.GetResult(expression, x_value).second);
}

TEST(ModelTest, CreditCalc1) {
  s21::CreditCalc credit(150000, 7 * 12, 0.16, "annuity");
  credit.CalcAnnuityPayment();
  ASSERT_NEAR(credit.GetMonthlyPayment(), 2979.31, 1e-1);
  ASSERT_NEAR(credit.GetOverpayment(), 100262.04, 1e-1);
  ASSERT_NEAR(credit.GetTotalPayment(), 250262.04, 1e-1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
