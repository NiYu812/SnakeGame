#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QTimer>
#include <QList>
#include <QPointF>

enum Direction { Up, Down, Left, Right };

class SnakeGame : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit SnakeGame(QObject *parent = 0);
    ~SnakeGame();

    void start();
    void pause();
    void reset();
    bool isPaused() const;
    int getScore() const;

signals:
    void scoreChanged(int score);
    void gameOver(int finalScore);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void moveSnake();
    void spawnFood();

private:
    QTimer *gameTimer;
    QList<QGraphicsRectItem*> snake;
    QGraphicsRectItem *food;
    Direction direction;
    Direction nextDirection;
    bool paused;
    int score;
    const int gridSize = 20;
    const int cellSize = 20;
    const int initialSpeed = 150;
    int currentSpeed;

    void initSnake();
    void checkCollision();
    bool isSnakeAtPosition(const QPointF &pos);
    void growSnake();
    void updateSpeed();
};

#endif // SNAKEGAME_H