#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <QObject>
#include <QTimer>
#include <QList>
#include <QPoint>
#include <QRandomGenerator>
#include <QGraphicsScene>

class GameScene;

class SnakeGame : public QObject
{
    Q_OBJECT

public:
    enum Direction { Up, Down, Left, Right };
    enum GameState { Running, Paused, GameOver };

    explicit SnakeGame(GameScene *scene, QObject *parent = nullptr);
    ~SnakeGame() override;

    void start();
    void pause();
    void resume();
    void stop();
    void changeDirection(Direction newDirection);

    int score() const { return m_score; }
    GameState gameState() const { return m_gameState; }

signals:
    void scoreChanged(int score);
    void gameOver(int finalScore);
    void gameUpdated();

private slots:
    void updateGame();

private:
    void initGame();
    void createSnake();
    void generateFood();
    bool checkCollision(const QPoint &head) const;
    void moveSnake();
    bool eatFood();
    void updateScene();

    GameScene *m_scene;
    QTimer *m_gameTimer;
    
    QList<QPoint> m_snake;
    Direction m_currentDirection;
    Direction m_nextDirection;
    QPoint m_food;
    
    int m_score;
    GameState m_gameState;
    
    const int m_gridSize = 20;
    const int m_sceneWidth = 580;
    const int m_sceneHeight = 580;
    const int m_updateInterval = 150; // 毫秒
};

#endif // SNAKEGAME_H