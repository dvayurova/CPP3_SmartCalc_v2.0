#include "view.h"

#include "ui_view.h"

namespace s21 {
View::View(Controller *c, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::View), controller_(c) {
  ui->setupUi(this);
  SetDefaultValues();
  graph = new GraphWidget(controller_);
  connect(this, &View::GraphSignal, graph, &GraphWidget::GraphSlot);
  connect(ui->PushButton0, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButton1, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButton2, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButton3, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButton4, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButton5, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButton6, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButton7, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButton8, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButton9, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButtonBracOpen, SIGNAL(clicked()), this,
          SLOT(ButtonPressed()));
  connect(ui->PushButtonBracClose, SIGNAL(clicked()), this,
          SLOT(ButtonPressed()));
  connect(ui->PushButtonX, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButtonCos, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButtonAcos, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButtonSin, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButtonAsin, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButtonMod, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButtonTan, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButtonAtan, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButtonExp, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButtonLn, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButtonLog, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButtonSqrt, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButtonDiv, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButtonMult, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButtonMinus, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButtonPlus, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
  connect(ui->PushButtonDot, SIGNAL(clicked()), this, SLOT(ButtonPressed()));

  connect(ui->PushButtonDel, SIGNAL(clicked()), this, SLOT(ButtonDelPressed()));
  connect(ui->PushButtonAC, SIGNAL(clicked()), this, SLOT(ButtonACPressed()));

  connect(ui->PushButtonGraph, SIGNAL(clicked()), this,
          SLOT(GraphingButtonPressed()));

  connect(ui->PushButtonEqual, SIGNAL(clicked()), this,
          SLOT(ButtonEqualPressed()));

  connect(ui->pushButtonCreditCalc, SIGNAL(clicked()), this,
          SLOT(CreditCalc()));
}

View::~View() {
  delete graph;
  delete ui;
}

void View::ButtonPressed() {
  QPushButton *button = (QPushButton *)sender();
  QString button_text = button->text();
  if (ui->expression->hasFocus()) {
    ui->expression->setText(ui->expression->text() += button_text);
  } else if (ui->x_value->hasFocus()) {
    ui->x_value->setText(ui->x_value->text() += button_text);
  }
}

void View::ButtonEqualPressed() {
  std::pair<bool, double> result = {0, 0};
  result = controller_->GetMainCalcResult(ui->expression->text().toStdString(),
                                          ui->x_value->text().toStdString());

  if (result.first) {
    ui->expression->setText(QString::number(result.second, 'g', 16));
  } else {
    ui->expression->setText("error:expression-incorrect");
  }
}

void View::ButtonDelPressed() {
  QString tmp = "";
  if (ui->expression->hasFocus()) {
    tmp = ui->expression->text();
    tmp.chop(1);
    ui->expression->setText(tmp);
  } else if (ui->x_value->hasFocus()) {
    tmp = ui->x_value->text();
    tmp.chop(1);
    ui->x_value->setText(tmp);
  }
}

void View::ButtonACPressed() {
  if (ui->expression->hasFocus()) {
    ui->expression->clear();
  } else if (ui->x_value->hasFocus()) {
    ui->x_value->clear();
  }
}

void View::GraphingButtonPressed() {
  graph->show();
  double x_min = ui->lineEditXmin->text().toDouble();
  double x_max = ui->lineEditXmax->text().toDouble();
  double y_min = ui->lineEditYmin->text().toDouble();
  double y_max = ui->lineEditYmax->text().toDouble();
  emit GraphSignal(x_min, x_max, y_min, y_max,
                   ui->expression->text().toStdString());
}

void View::CreditCalc() {
  double amount = ui->lineEditLoanSum->text().toDouble();
  int term = ui->Term->value();
  double rate = ui->Rate->value();
  if (ui->comboBoxTerm->currentText() == "лет") {
    term *= 12;
  }
  s21::CreditCalc credit(amount, term, rate / 100);
  if (ui->radioButtonAnnuitet->isChecked() == true) {
    controller_->GetAnnuityPayment(credit);
  }
  if (ui->radioButtonDifferent->isChecked() == true) {
    controller_->GetDifferPayment(credit);
  }

  if (ui->radioButtonDifferent->isChecked() == true) {
    ui->labelPayment->setText(
        QString::number(credit.GetFirstPayment(), 'f', 2) + " ... " +
        QString::number(credit.GetLastPayment(), 'f', 2) + " руб.");
  }
  if (ui->radioButtonAnnuitet->isChecked() == true) {
    ui->labelPayment->setText(
        QString::number(credit.GetMonthlyPayment(), 'f', 2) + " руб.");
  }
  ui->labelOverpay->setText(QString::number(credit.GetOverpayment(), 'f', 2) +
                            " руб.");
  ui->labelTotal->setText(QString::number(credit.GetTotalPayment(), 'f', 2) +
                          " руб.");
}

void View::SetDefaultValues() {
  ui->expression->setPlaceholderText("0.00");
  ui->expression->setFocus();
  ui->radioButtonAnnuitet->setChecked(true);
  ui->expression->setReadOnly(true);
}

}  // namespace s21
