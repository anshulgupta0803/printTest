QT       += widgets printsupport

TARGET = printTest
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++14

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CPD_LIB_PATH = $$absolute_path($$PWD/../common-print-dialog)
QMAKE_LFLAGS = -Wl,-rpath,$$CPD_LIB_PATH

LIBS += -L$${CPD_LIB_PATH} -lQCPDialog

INCLUDEPATH += $${CPD_LIB_PATH}/app
DEPENDPATH += $${CPD_LIB_PATH}
