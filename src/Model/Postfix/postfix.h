#ifndef CPP3_SMARTCALC_V2_MODEL_POSTFIX_POSTFIX_H_
#define CPP3_SMARTCALC_V2_MODEL_POSTFIX_POSTFIX_H_

#include <queue>
#include <stack>

#include "../Validation/validation.h"

namespace s21 {

class PostfixExpression {
 public:
  PostfixExpression() {}
  std::queue<Lexeme> ConvertToPostfix(std::string &expression,
                                      std::string &x_value);

 private:
  std::queue<Lexeme> postfix_;
  Infix infix_;
  std::stack<Lexeme> stack_;

  void FromStackToPostfix();
  void ParseBrackets(size_t &i);
  void ParseOperation(size_t &i);
  bool CheckOperationPriority(std::string &operation);
};

}  // namespace s21

#endif  //  CPP3_SMARTCALC_V2_MODEL_POSTFIX_POSTFIX_H_