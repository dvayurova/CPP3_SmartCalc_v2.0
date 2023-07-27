#include "View/view.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  s21::CalculatorModel m;
  s21::Controller c(&m);
  View w(&c);

  w.show();
  return a.exec();
}
