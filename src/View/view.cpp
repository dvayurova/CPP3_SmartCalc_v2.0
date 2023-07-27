#include "view.h"
#include "ui_view.h"

View::View(s21::Controller *c, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::View), controller_(c) {
  ui->setupUi(this);

  ui->lineEdit->setPlaceholderText("0.00");
   ui->lineEdit->setFocus();

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
     connect(ui->PushButtonBracOpen, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
     connect(ui->PushButtonBracClose, SIGNAL(clicked()), this, SLOT(ButtonPressed()));
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

     connect(ui->PushButtonEqual, SIGNAL(clicked()), this, SLOT(ButtonEqualPressed()));


}

View::~View() { delete ui; }


void View::ButtonPressed(){
    QPushButton *button = (QPushButton *)sender();
      QString button_text = button->text();
      QString numbers = "0123456789.- ";
      if (ui->lineEdit->hasFocus()) {
        ui->lineEdit->setText(ui->lineEdit->text() += button_text);
      } else if (ui->lineEdit_X->hasFocus() &&
                 numbers.contains(button_text, Qt::CaseInsensitive)) {
        ui->lineEdit_X->setText(ui->lineEdit_X->text() += button_text);
      }
}

void View::ButtonEqualPressed() {

    // в модель перенести
  std::string expression = ui->lineEdit->text().toStdString();
  std::string x_value = ui->lineEdit_X->text().toStdString();
  size_t pos;
     while ((pos = expression.find("X")) != std::string::npos) {
         expression.replace(pos, 1, x_value);
     }

  std::pair<bool, double> result =  controller_->GetMainCalcResult(expression);
  if(result.first) {
      ui->lineEdit->setText(QString::number(result.second, 'g', 16));
  } else {
      ui->lineEdit->setText("ERROR! INCORRECT EXPRESSION");
  }

}

