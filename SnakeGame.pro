QT += widgets

TARGET = SnakeGame
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    snakegame.cpp

HEADERS += \
    mainwindow.h \
    snakegame.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    resources.qrc

QMAKE_CXXFLAGS += -std=c++11