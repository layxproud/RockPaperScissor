#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "gameview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void displayResults(int result);

private:
    Ui::MainWindow *ui;
    GameView *playerView;
    GameView *opponentView;

public slots:
    void onMakeMoveButtonClicked();
    void onStatsActionTriggered();
};
#endif // MAINWINDOW_H
