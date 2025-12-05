#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gameScene(new SnakeGame(this))
    , gameTimer(new QTimer(this))
    , highScore(0)
{
    ui->setupUi(this);
    
    // 设置窗口属性
    setWindowTitle("贪吃蛇游戏");
    setFixedSize(800, 600);
    
    // 初始化游戏场景
    ui->graphicsView->setScene(gameScene);
    ui->graphicsView->setFixedSize(420, 420);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    
    // 创建分数标签
    scoreLabel = new QLabel("分数: 0", this);
    scoreLabel->setGeometry(500, 100, 200, 30);
    scoreLabel->setStyleSheet("font-size: 20px; font-weight: bold;");
    
    highScoreLabel = new QLabel("最高分: 0", this);
    highScoreLabel->setGeometry(500, 150, 200, 30);
    highScoreLabel->setStyleSheet("font-size: 20px; font-weight: bold;");
    
    // 加载最高分
    loadHighScore();
    highScoreLabel->setText(QString("最高分: %1").arg(highScore));
    
    // 连接信号槽
    connect(gameScene, &SnakeGame::scoreChanged, this, &MainWindow::updateScore);
    connect(gameScene, &SnakeGame::gameOver, this, &MainWindow::gameOver);
    
    // 初始化按钮状态
    ui->pauseButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    if (gameScene->isPaused()) {
        gameScene->pause(); // 继续游戏
        ui->startButton->setText("暂停");
        ui->pauseButton->setEnabled(true);
    } else {
        gameScene->start();
        ui->startButton->setText("暂停");
        ui->pauseButton->setEnabled(true);
    }
}

void MainWindow::on_pauseButton_clicked()
{
    gameScene->pause();
    ui->startButton->setText("开始");
    ui->pauseButton->setEnabled(false);
}

void MainWindow::on_resetButton_clicked()
{
    gameScene->reset();
    ui->startButton->setText("开始");
    ui->pauseButton->setEnabled(false);
    scoreLabel->setText("分数: 0");
}

void MainWindow::updateScore()
{
    scoreLabel->setText(QString("分数: %1").arg(gameScene->getScore()));
}

void MainWindow::gameOver()
{
    int finalScore = gameScene->getScore();
    
    // 更新最高分
    if (finalScore > highScore) {
        highScore = finalScore;
        highScoreLabel->setText(QString("最高分: %1").arg(highScore));
        saveHighScore();
        
        QMessageBox::information(this, "游戏结束", 
            QString("恭喜!新纪录: %1分!").arg(finalScore));
    } else {
        QMessageBox::information(this, "游戏结束", 
            QString("游戏结束!您的分数: %1分\n最高分: %2分").arg(finalScore).arg(highScore));
    }
    
    ui->startButton->setText("开始");
    ui->pauseButton->setEnabled(false);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // 将键盘事件传递给游戏场景
    gameScene->keyPressEvent(event);
    QMainWindow::keyPressEvent(event);
}

void MainWindow::loadHighScore()
{
    QFile file("highscore.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        in >> highScore;
        file.close();
    }
}

void MainWindow::saveHighScore()
{
    QFile file("highscore.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << highScore;
        file.close();
    }
}