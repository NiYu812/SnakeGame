#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QKeyEvent>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>

class SnakeGame;
class GameScene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void startGame();
    void pauseGame();
    void gameOver(int score);
    void updateScore(int score);

private:
    void initUI();
    void createMenu();
    void createStatusBar();

    SnakeGame *m_snakeGame;
    GameScene *m_gameScene;
    QGraphicsView *m_graphicsView;
    
    QLabel *m_scoreLabel;
    QLabel *m_statusLabel;
    QPushButton *m_startButton;
    QPushButton *m_pauseButton;
    QPushButton *m_quitButton;
    
    bool m_isPaused;
};

#endif // MAINWINDOW_H