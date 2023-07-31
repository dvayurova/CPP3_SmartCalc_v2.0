#include "graphwidget.h"

#include "ui_graphwidget.h"
#include <math.h>

namespace s21 {
GraphWidget::GraphWidget(Controller *controller, QWidget *parent)
    : QWidget(parent), ui(new Ui::GraphWidget), controller_(controller) {
  ui->setupUi(this);
}

void GraphWidget::GraphSlot(double x_min, double x_max, double y_min,
                            double y_max, std::string expression) {

  ui->widget->clearGraphs();
  ui->widget->xAxis->setRange(x_min, x_max);
  ui->widget->yAxis->setRange(y_min, y_max);

  std::pair<std::vector<double>, std::vector<double>> coordinates =
      controller_->GetCoordinates(x_min, x_max, expression);
  QVector<double> x_vector(coordinates.first.begin(), coordinates.first.end());
  QVector<double> y_vector(coordinates.second.begin(),
                           coordinates.second.end());
  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x_vector, y_vector);
  ui->widget->replot();
  x_vector.clear();
  y_vector.clear();
}

GraphWidget::~GraphWidget() { delete ui; }
} // namespace s21
