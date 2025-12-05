#include "mainwindow.h"
#include "snakegame.h"
#include "gamescene.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), m_isPaused(false)
{
    initUI();
    createMenu();
    createStatusBar();
}

MainWindow::~MainWindow() override
{
    delete m_snakeGame;
}

void MainWindow::initUI()
{
    setWindowTitle("贪吃蛇游戏");
    setFixedSize(600, 700);

    // 创建游戏场景
    m_gameScene = new GameScene(this);
    m_graphicsView = new QGraphicsView(m_gameScene);
    m_graphicsView->setFixedSize(580, 580);
    m_graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // 创建控制面板
    QWidget *controlWidget = new QWidget();
    QHBoxLayout *controlLayout = new QHBoxLayout(controlWidget);

    m_startButton = new QPushButton("开始游戏");
    m_pauseButton = new QPushButton("暂停");
    m_quitButton = new QPushButton("退出");

    m_pauseButton->setEnabled(false);

    controlLayout->addWidget(m_startButton);
    controlLayout->addWidget(m_pauseButton);
    controlLayout->addWidget(m_quitButton);

    // 创建主布局
    QWidget *centralWidget = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addWidget(m_graphicsView);
    mainLayout->addWidget(controlWidget);

    setCentralWidget(centralWidget);

    // 连接信号槽
    connect(m_startButton, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(m_pauseButton, &QPushButton::clicked, this, &MainWindow::pauseGame);
    connect(m_quitButton, &QPushButton::clicked, this, &QMainWindow::close);
}

void MainWindow::createMenu()
{
    QMenu *fileMenu = menuBar()->addMenu("文件");
    QAction *newAction = fileMenu->addAction("新游戏");
    QAction *quitAction = fileMenu->addAction("退出");

    QMenu *helpMenu = menuBar()->addMenu("帮助");
    QAction *aboutAction = helpMenu->addAction("关于");

    connect(newAction, &QAction::triggered, this, &MainWindow::startGame);
    connect(quitAction, &QAction::triggered, this, &QMainWindow::close);
    connect(aboutAction, &QAction::triggered, [this]() {
        QMessageBox::about(this, "关于贪吃蛇", "贪吃蛇游戏 v1.0\n使用Qt和C++开发");
    });
}

void MainWindow::createStatusBar()
{
    m_scoreLabel = new QLabel("得分: 0");
    m_statusLabel = new QLabel("准备开始游戏");

    statusBar()->addWidget(m_scoreLabel);
    statusBar()->addWidget(m_statusLabel, 1);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (m_snakeGame && !m_isPaused) {
        switch (event->key()) {
        case Qt::Key_Up:
            m_snakeGame->changeDirection(SnakeGame::Up);
            break;
        case Qt::Key_Down:
            m_snakeGame->changeDirection(SnakeGame::Down);
            break;
        case Qt::Key_Left:
            m_snakeGame->changeDirection(SnakeGame::Left);
            break;
        case Qt::Key_Right:
            m_snakeGame->changeDirection(SnakeGame::Right);
            break;
        case Qt::Key_Space:
            pauseGame();
            break;
        default:
            QMainWindow::keyPressEvent(event);
        }
    }
}

void MainWindow::startGame()
{
    if (m_snakeGame) {
        delete m_snakeGame;
    }

    m_snakeGame = new SnakeGame(m_gameScene, this);
    m_isPaused = false;
    
    m_startButton->setEnabled(false);
    m_pauseButton->setEnabled(true);
    m_statusLabel->setText("游戏进行中...");
    m_scoreLabel->setText("得分: 0");

    connect(m_snakeGame, &SnakeGame::scoreChanged, this, &MainWindow::updateScore);
    connect(m_snakeGame, &SnakeGame::gameOver, this, &MainWindow::gameOver);

    m_snakeGame->start();
}

void MainWindow::pauseGame()
{
    if (!m_snakeGame) return;

    m_isPaused = !m_isPaused;
    
    if (m_isPaused) {
        m_snakeGame->pause();
        m_pauseButton->setText("继续");
        m_statusLabel->setText("游戏已暂停");
    } else {
        m_snakeGame->resume();
        m_pauseButton->setText("暂停");
        m_statusLabel->setText("游戏进行中...");
    }
}

void MainWindow::gameOver(int score)
{
    m_startButton->setEnabled(true);
    m_pauseButton->setEnabled(false);
    m_statusLabel->setText("游戏结束");

    QMessageBox::information(this, "游戏结束", 
                           QString("你的得分: %1\n\n是否开始新游戏?").arg(score),
                           QMessageBox::Yes | QMessageBox::No,
                           QMessageBox::Yes);
}

void MainWindow::updateScore(int score)
{
    m_scoreLabel->setText(QString("得分: %1").arg(score));
}