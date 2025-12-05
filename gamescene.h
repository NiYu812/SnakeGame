#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QList>
#include <QPoint>
#include <QBrush>
#include <QPen>

class GameScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit GameScene(QObject *parent = nullptr);
    ~GameScene() override;

    void updateScene(const QList<QPoint> &snake, const QPoint &food, int gridSize);

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;

private:
    void drawGrid(QPainter *painter, const QRectF &rect);
    void drawSnake(QPainter *painter);
    void drawFood(QPainter *painter);
    
    QList<QPoint> m_snake;
    QPoint m_food;
    int m_gridSize;
    
    QBrush m_snakeHeadBrush;
    QBrush m_snakeBodyBrush;
    QBrush m_foodBrush;
    QPen m_gridPen;
};

#endif // GAMESCENE_H