#ifndef CPP3_SMARTCALC_V2_VIEW_GRAPHWIDGET_H_
#define CPP3_SMARTCALC_V2_VIEW_GRAPHWIDGET_H_

#include <QWidget>

#include "../../Controller/controller.h"

namespace Ui {
class GraphWidget;
}

namespace s21 {
class GraphWidget : public QWidget {
  Q_OBJECT

 public:
  explicit GraphWidget(Controller *controller, QWidget *parent = nullptr);
  ~GraphWidget();

 private:
  Ui::GraphWidget *ui;
  Controller *controller_;

 public slots:
  void GraphSlot(double x_min, double x_max, double y_min, double y_max,
                 std::string expression);
};
}  // namespace s21
#endif  // CPP3_SMARTCALC_V2_VIEW_GRAPHWIDGET_H_
