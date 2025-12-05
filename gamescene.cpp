#include "gamescene.h"
#include <QPainter>
#include <QColor>

GameScene::GameScene(QObject *parent)
    : QGraphicsScene(parent), m_gridSize(20)
{
    // 设置场景大小
    setSceneRect(0, 0, 580, 580);
    
    // 初始化颜色和画笔
    m_snakeHeadBrush = QBrush(QColor(0, 200, 0)); // 深绿色头部
    m_snakeBodyBrush = QBrush(QColor(0, 255, 0)); // 浅绿色身体
    m_foodBrush = QBrush(QColor(255, 0, 0));      // 红色食物
    m_gridPen = QPen(QColor(200, 200, 200));      // 浅灰色网格线
}

GameScene::~GameScene() override
{
}

void GameScene::updateScene(const QList<QPoint> &snake, const QPoint &food, int gridSize)
{
    m_snake = snake;
    m_food = food;
    m_gridSize = gridSize;
    invalidate(); // 触发重绘
}

void GameScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    // 调用父类绘制背景
    QGraphicsScene::drawBackground(painter, rect);
    
    // 绘制网格
    drawGrid(painter, rect);
    
    // 绘制食物
    drawFood(painter);
    
    // 绘制蛇
    drawSnake(painter);
}

void GameScene::drawGrid(QPainter *painter, const QRectF &rect)
{
    painter->save();
    painter->setPen(m_gridPen);
    
    // 绘制垂直线
    for (int x = 0; x <= sceneRect().width(); x += m_gridSize) {
        painter->drawLine(x, 0, x, sceneRect().height());
    }
    
    // 绘制水平线
    for (int y = 0; y <= sceneRect().height(); y += m_gridSize) {
        painter->drawLine(0, y, sceneRect().width(), y);
    }
    
    painter->restore();
}

void GameScene::drawSnake(QPainter *painter)
{
    if (m_snake.isEmpty()) return;
    
    painter->save();
    
    // 绘制蛇头
    QPoint head = m_snake.first();
    qreal x = head.x() * m_gridSize + 1;
    qreal y = head.y() * m_gridSize + 1;
    qreal size = m_gridSize - 2;
    
    painter->setBrush(m_snakeHeadBrush);
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(x, y, size, size);
    
    // 绘制蛇身
    painter->setBrush(m_snakeBodyBrush);
    for (int i = 1; i < m_snake.size(); ++i) {
        QPoint bodyPart = m_snake[i];
        x = bodyPart.x() * m_gridSize + 2;
        y = bodyPart.y() * m_gridSize + 2;
        size = m_gridSize - 4;
        painter->drawRect(x, y, size, size);
    }
    
    painter->restore();
}

void GameScene::drawFood(QPainter *painter)
{
    painter->save();
    
    qreal x = m_food.x() * m_gridSize + 3;
    qreal y = m_food.y() * m_gridSize + 3;
    qreal size = m_gridSize - 6;
    
    painter->setBrush(m_foodBrush);
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(x, y, size, size);
    
    painter->restore();
}