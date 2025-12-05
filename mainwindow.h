#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include "snakegame.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startButton_clicked();
    void on_pauseButton_clicked();
    void on_resetButton_clicked();
    void updateScore();
    void gameOver();

private:
    Ui::MainWindow *ui;
    SnakeGame *gameScene;
    QTimer *gameTimer;
    QLabel *scoreLabel;
    QLabel *highScoreLabel;
    int highScore;

    void keyPressEvent(QKeyEvent *event) override;
    void loadHighScore();
    void saveHighScore();
};

#endif // MAINWINDOW_H