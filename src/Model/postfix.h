#ifndef SRC_MODEL_POSTFIX_H_
#define SRC_MODEL_POSTFIX_H_

#include "infix.h"
#include "lexeme.h"
#include <map>
#include <queue>
#include <stack>

#include <iostream> // delete

namespace s21 {
class PostfixExpression {
public:
  PostfixExpression() {}
  std::queue<Lexeme> ConvertToPostfix(std::string &expression);

  void Print(); // tmp

private:
  std::queue<Lexeme> postfix_;
  bool valid_expression_;
  Infix infix_;

  void FromStackToPostfix(std::stack<Lexeme> &stack);
};
} // namespace s21

#include "postfix.cc"
#endif //  SRC_MODEL_POSTFIX_H_