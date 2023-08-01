#ifndef CPP3_SMARTCALC_V2_MODEL_INFIX_H_
#define CPP3_SMARTCALC_V2_MODEL_INFIX_H_

#include <string>

namespace s21 {

class Infix {
 public:
  Infix() {}
  Infix(std::string str) : infix_(str) {}
  Infix(const Infix &other) { infix_ = other.infix_; }
  Infix(Infix &&other) { infix_ = other.infix_; }
  ~Infix() {}

  double GetNumber(size_t &index);
  double GetX(std::string &number, bool &is_nimber);

  std::string GetFunction(size_t &index);

  size_t GetLength();
  char &operator[](size_t i);
  std::string &operator=(std::string &str);
  std::string &operator=(std::string &&str) {
    infix_ = str;
    return infix_;
  }
  std::string &GetString();
  std::string GetOperation(size_t &index);

 private:
  std::string infix_;
};

}  // namespace s21

#endif  //  CPP3_SMARTCALC_V2_MODEL_SUPPORT_INFIX_H_