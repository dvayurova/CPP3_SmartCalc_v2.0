#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>

#include "../Controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

class View : public QMainWindow {
  Q_OBJECT

public:
  View(s21::Controller *c, QWidget *parent = nullptr);
  ~View();

private:
  Ui::View *ui;
  s21::Controller *controller_;

 private slots:
     void ButtonPressed();
     void ButtonEqualPressed();
};
#endif // VIEW_H
