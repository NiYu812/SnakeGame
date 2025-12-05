/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *resetButton;
    QSpacerItem *verticalSpacer;
    QLabel *instructionsLabel;
    QLabel *instructionsLabel_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setMinimumSize(QSize(400, 400));
        graphicsView->setMaximumSize(QSize(400, 400));

        horizontalLayout->addWidget(graphicsView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(centralWidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 24px; font-weight: bold; color: #333;"));

        verticalLayout->addWidget(titleLabel);

        startButton = new QPushButton(centralWidget);
        startButton->setObjectName("startButton");
        startButton->setMinimumSize(QSize(120, 40));
        startButton->setStyleSheet(QString::fromUtf8("font-size: 16px;"));

        verticalLayout->addWidget(startButton);

        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setMinimumSize(QSize(120, 40));
        pauseButton->setStyleSheet(QString::fromUtf8("font-size: 16px;"));

        verticalLayout->addWidget(pauseButton);

        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName("resetButton");
        resetButton->setMinimumSize(QSize(120, 40));
        resetButton->setStyleSheet(QString::fromUtf8("font-size: 16px;"));

        verticalLayout->addWidget(resetButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        instructionsLabel = new QLabel(centralWidget);
        instructionsLabel->setObjectName("instructionsLabel");
        instructionsLabel->setAlignment(Qt::AlignCenter);
        instructionsLabel->setWordWrap(true);
        instructionsLabel->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #666;"));

        verticalLayout->addWidget(instructionsLabel);

        instructionsLabel_2 = new QLabel(centralWidget);
        instructionsLabel_2->setObjectName("instructionsLabel_2");
        instructionsLabel_2->setAlignment(Qt::AlignCenter);
        instructionsLabel_2->setWordWrap(true);
        instructionsLabel_2->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #666;"));

        verticalLayout->addWidget(instructionsLabel_2);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\264\252\345\220\203\350\233\207\346\270\270\346\210\217", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "\350\264\252\345\220\203\350\233\207\346\270\270\346\210\217", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "\351\207\215\347\275\256", nullptr));
        instructionsLabel->setText(QCoreApplication::translate("MainWindow", "\344\275\277\347\224\250\346\226\271\345\220\221\351\224\256\346\210\226WASD\346\216\247\345\210\266\350\233\207\347\232\204\347\247\273\345\212\250", nullptr));
        instructionsLabel_2->setText(QCoreApplication::translate("MainWindow", "\345\220\203\345\210\260\347\272\242\350\211\262\351\243\237\347\211\251\345\276\227\345\210\206\357\274\214\346\222\236\345\242\231\346\210\226\346\222\236\345\210\260\350\207\252\345\267\261\346\270\270\346\210\217\347\273\223\346\235\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
