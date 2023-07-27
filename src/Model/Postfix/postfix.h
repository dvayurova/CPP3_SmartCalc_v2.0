#ifndef CPP3_SMARTCALC_V2_MODEL_POSTFIX_POSTFIX_H_
#define CPP3_SMARTCALC_V2_MODEL_POSTFIX_POSTFIX_H_

// #include "../infix.h"
// #include "../lexeme.h"
#include "../Validation/validation.h"
#include <map>
#include <queue>
#include <stack>

namespace s21 {

class PostfixExpression {
public:
  PostfixExpression() {}
  std::queue<Lexeme> ConvertToPostfix(std::string &expression);

private:
  std::queue<Lexeme> postfix_;
  Infix infix_;
  std::stack<Lexeme> stack_;

  void FromStackToPostfix();
  void ParseBrackets(size_t &i);
  void ParseOperation(size_t &i);
};

} // namespace s21

// #include "postfix.cc"
#endif //  CPP3_SMARTCALC_V2_MODEL_POSTFIX_POSTFIX_H_