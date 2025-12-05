#include "snakegame.h"
#include <QRandomGenerator>
#include <QBrush>
#include <QColor>
#include <QKeyEvent>

SnakeGame::SnakeGame(QObject *parent)
    : QGraphicsScene(parent)
    , gameTimer(new QTimer(this))
    , direction(Right)
    , nextDirection(Right)
    , paused(false)
    , score(0)
    , currentSpeed(initialSpeed)
{
    // 设置场景大小
    setSceneRect(0, 0, gridSize * cellSize, gridSize * cellSize);
    
    // 设置背景
    setBackgroundBrush(QBrush(QColor(240, 240, 240)));
    
    // 连接定时器
    connect(gameTimer, &QTimer::timeout, this, &SnakeGame::moveSnake);
    
    // 初始化游戏
    initSnake();
    spawnFood();
}

SnakeGame::~SnakeGame()
{
    delete gameTimer;
}

void SnakeGame::start()
{
    if (!paused) {
        // 首次开始
        reset();
    }
    paused = false;
    gameTimer->start(currentSpeed);
}

void SnakeGame::pause()
{
    paused = !paused;
    if (paused) {
        gameTimer->stop();
    } else {
        gameTimer->start(currentSpeed);
    }
}

void SnakeGame::reset()
{
    // 清除所有项目
    clear();
    snake.clear();
    score = 0;
    direction = Right;
    nextDirection = Right;
    currentSpeed = initialSpeed;
    paused = false;
    
    // 重新初始化
    initSnake();
    spawnFood();
    emit scoreChanged(score);
}

bool SnakeGame::isPaused() const
{
    return paused;
}

int SnakeGame::getScore() const
{
    return score;
}

void SnakeGame::keyPressEvent(QKeyEvent *event)
{
    if (paused) {
        return;
    }
    
    switch (event->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
        if (direction != Down) {
            nextDirection = Up;
        }
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        if (direction != Up) {
            nextDirection = Down;
        }
        break;
    case Qt::Key_Left:
    case Qt::Key_A:
        if (direction != Right) {
            nextDirection = Left;
        }
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        if (direction != Left) {
            nextDirection = Right;
        }
        break;
    default:
        QGraphicsScene::keyPressEvent(event);
        break;
    }
}

void SnakeGame::moveSnake()
{
    if (paused) {
        return;
    }
    
    direction = nextDirection;
    
    // 获取蛇头位置
    QPointF headPos = snake.first()->pos();
    QPointF newHeadPos = headPos;
    
    // 计算新位置
    switch (direction) {
    case Up:
        newHeadPos.setY(headPos.y() - cellSize);
        break;
    case Down:
        newHeadPos.setY(headPos.y() + cellSize);
        break;
    case Left:
        newHeadPos.setX(headPos.x() - cellSize);
        break;
    case Right:
        newHeadPos.setX(headPos.x() + cellSize);
        break;
    }
    
    // 检查边界碰撞
    if (newHeadPos.x() < 0 || newHeadPos.x() >= gridSize * cellSize ||
        newHeadPos.y() < 0 || newHeadPos.y() >= gridSize * cellSize) {
        gameTimer->stop();
        emit gameOver(score);
        return;
    }
    
    // 检查自身碰撞
    if (isSnakeAtPosition(newHeadPos)) {
        gameTimer->stop();
        emit gameOver(score);
        return;
    }
    
    // 创建新蛇头
    QGraphicsRectItem *newHead = new QGraphicsRectItem(0, 0, cellSize - 2, cellSize - 2);
    newHead->setPos(newHeadPos);
    newHead->setBrush(QBrush(QColor(0, 200, 0)));
    addItem(newHead);
    snake.prepend(newHead);
    
    // 检查是否吃到食物
    if (newHeadPos == food->pos()) {
        // 增加分数
        score += 10;
        emit scoreChanged(score);
        
        // 更新速度
        updateSpeed();
        
        // 移除旧食物并生成新食物
        removeItem(food);
        delete food;
        spawnFood();
    } else {
        // 移除蛇尾
        QGraphicsRectItem *tail = snake.takeLast();
        removeItem(tail);
        delete tail;
    }
}

void SnakeGame::spawnFood()
{
    // 随机生成食物位置
    int x, y;
    do {
        x = QRandomGenerator::global()->bounded(gridSize);
        y = QRandomGenerator::global()->bounded(gridSize);
    } while (isSnakeAtPosition(QPointF(x * cellSize, y * cellSize)));
    
    // 创建食物
    food = new QGraphicsRectItem(0, 0, cellSize - 2, cellSize - 2);
    food->setPos(x * cellSize, y * cellSize);
    food->setBrush(QBrush(QColor(255, 0, 0)));
    addItem(food);
}

void SnakeGame::initSnake()
{
    // 创建初始蛇（3个身体段）
    for (int i = 0; i < 3; ++i) {
        QGraphicsRectItem *segment = new QGraphicsRectItem(0, 0, cellSize - 2, cellSize - 2);
        segment->setPos((5 - i) * cellSize, 5 * cellSize);
        segment->setBrush(QBrush(QColor(0, 200, 0)));
        addItem(segment);
        snake.append(segment);
    }
}

void SnakeGame::checkCollision()
{
    // 已在moveSnake中处理
}

bool SnakeGame::isSnakeAtPosition(const QPointF &pos)
{
    for (const auto &segment : snake) {
        if (segment->pos() == pos) {
            return true;
        }
    }
    return false;
}

void SnakeGame::growSnake()
{
    // 已在moveSnake中处理
}

void SnakeGame::updateSpeed()
{
    // 每吃10个食物，速度增加10%
    if (score % 100 == 0 && currentSpeed > 50) {
        currentSpeed *= 0.9;
        gameTimer->setInterval(currentSpeed);
    }
}