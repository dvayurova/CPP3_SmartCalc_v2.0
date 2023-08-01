QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../main.cc \
    Graph/graphwidget.cc \
    qcustomplot.cc \
    view.cc \
    ../Model/Calculation/calculation.cc \
    ../Model/Postfix/postfix.cc \
    ../Model/Validation/validation.cc \
    ../Model/infix.cc \
    ../Model/model.cc \
    ../Model/Credit/credit_calc.cc

HEADERS += \
    Graph/graphwidget.h \
    qcustomplot.h \
    view.h \
    ../Controller/controller.h \
    ../Model/Calculation/calculation.h \
    ../Model/Postfix/postfix.h \
    ../Model/Validation/validation.h \
    ../Model/infix.h \
    ../Model/lexeme.h \
    ../Model/model.h \
    ../Model/Credit/credit_calc.h

FORMS += \
    Graph/graphwidget.ui \
    view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
