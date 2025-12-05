# 简化版Qt项目配置文件
# 适用于快速测试和编译

QT += core gui widgets

TARGET = SnakeGame
TEMPLATE = app

# C++标准
CONFIG += c++11

# 源文件
SOURCES += \
        main.cpp \
        mainwindow.cpp \
        snakegame.cpp \
        gamescene.cpp

# 头文件
HEADERS += \
        mainwindow.h \
        snakegame.h \
        gamescene.h

# 输出目录
DESTDIR = ./bin
OBJECTS_DIR = ./obj
MOC_DIR = ./moc

# 编译选项
QMAKE_CXXFLAGS += -Wall

# 调试模式
CONFIG(debug, debug|release) {
    DEFINES += DEBUG
}

# 发布模式
CONFIG(release, debug|release) {
    DEFINES += NDEBUG
    QMAKE_CXXFLAGS += -O2
}