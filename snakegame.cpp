#include "snakegame.h"
#include "gamescene.h"

SnakeGame::SnakeGame(GameScene *scene, QObject *parent)
    : QObject(parent), m_scene(scene), m_score(0), m_gameState(GameOver)
{
    m_gameTimer = new QTimer(this);
    connect(m_gameTimer, &QTimer::timeout, this, &SnakeGame::updateGame);
}

SnakeGame::~SnakeGame() override
{
    m_gameTimer->stop();
}

void SnakeGame::start()
{
    initGame();
    m_gameState = Running;
    m_gameTimer->start(m_updateInterval);
}

void SnakeGame::pause()
{
    if (m_gameState == Running) {
        m_gameState = Paused;
        m_gameTimer->stop();
    }
}

void SnakeGame::resume()
{
    if (m_gameState == Paused) {
        m_gameState = Running;
        m_gameTimer->start(m_updateInterval);
    }
}

void SnakeGame::stop()
{
    m_gameState = GameOver;
    m_gameTimer->stop();
    emit gameOver(m_score);
}

void SnakeGame::changeDirection(Direction newDirection)
{
    // 防止蛇直接反向移动
    if ((m_currentDirection == Up && newDirection == Down) ||
        (m_currentDirection == Down && newDirection == Up) ||
        (m_currentDirection == Left && newDirection == Right) ||
        (m_currentDirection == Right && newDirection == Left)) {
        return;
    }
    m_nextDirection = newDirection;
}

void SnakeGame::initGame()
{
    m_snake.clear();
    m_score = 0;
    m_currentDirection = Right;
    m_nextDirection = Right;
    
    createSnake();
    generateFood();
    
    emit scoreChanged(m_score);
    emit gameUpdated();
}

void SnakeGame::createSnake()
{
    // 初始化蛇的位置（屏幕中央）
    int centerX = (m_sceneWidth / m_gridSize) / 2;
    int centerY = (m_sceneHeight / m_gridSize) / 2;
    
    for (int i = 0; i < 3; ++i) {
        m_snake.append(QPoint(centerX - i, centerY));
    }
}

void SnakeGame::generateFood()
{
    int maxX = m_sceneWidth / m_gridSize;
    int maxY = m_sceneHeight / m_gridSize;
    
    do {
        // 使用QRandomGenerator生成随机位置
        int x = QRandomGenerator::global()->bounded(maxX);
        int y = QRandomGenerator::global()->bounded(maxY);
        m_food = QPoint(x, y);
    } while (m_snake.contains(m_food)); // 确保食物不在蛇身上
}

bool SnakeGame::checkCollision(const QPoint &head) const
{
    // 检查是否撞墙
    if (head.x() < 0 || head.x() >= m_sceneWidth / m_gridSize ||
        head.y() < 0 || head.y() >= m_sceneHeight / m_gridSize) {
        return true;
    }
    
    // 检查是否撞到自己
    for (int i = 1; i < m_snake.size(); ++i) {
        if (head == m_snake[i]) {
            return true;
        }
    }
    
    return false;
}

void SnakeGame::moveSnake()
{
    m_currentDirection = m_nextDirection;
    
    QPoint head = m_snake.first();
    
    // 根据方向移动头部
    switch (m_currentDirection) {
    case Up:
        head.setY(head.y() - 1);
        break;
    case Down:
        head.setY(head.y() + 1);
        break;
    case Left:
        head.setX(head.x() - 1);
        break;
    case Right:
        head.setX(head.x() + 1);
        break;
    }
    
    // 检查碰撞
    if (checkCollision(head)) {
        stop();
        return;
    }
    
    // 添加新头部
    m_snake.prepend(head);
    
    // 检查是否吃到食物
    if (!eatFood()) {
        // 没吃到食物，移除尾部
        m_snake.removeLast();
    }
}

bool SnakeGame::eatFood()
{
    if (m_snake.first() == m_food) {
        m_score += 10;
        emit scoreChanged(m_score);
        generateFood();
        return true;
    }
    return false;
}

void SnakeGame::updateScene()
{
    if (m_scene) {
        m_scene->updateScene(m_snake, m_food, m_gridSize);
    }
}

void SnakeGame::updateGame()
{
    if (m_gameState != Running) return;
    
    moveSnake();
    updateScene();
}