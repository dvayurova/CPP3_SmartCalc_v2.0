#ifndef CPP3_SMARTCALC_V2_VIEW_VIEW_H_
#define CPP3_SMARTCALC_V2_VIEW_VIEW_H_

#include <QMainWindow>
#include <QVector>
#include <Graph/graphwidget.h>

#include "../Controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

namespace s21 {
class View : public QMainWindow {
  Q_OBJECT

public:
  View(Controller *c, QWidget *parent = nullptr);
  ~View();

private:
  Ui::View *ui;
  GraphWidget *graph;
  Controller *controller_;
  void SetDefaultValues();

signals:
  void GraphSignal(double x_min, double x_max, double y_min, double y_max,
                   std::string expression);

private slots:
  void ButtonPressed();
  void ButtonEqualPressed();
  void ButtonDelPressed();
  void ButtonACPressed();
  void GraphingButtonPressed();
  void CreditCalc();
};
} // namespace s21
#endif // CPP3_SMARTCALC_V2_VIEW_VIEW_H_
