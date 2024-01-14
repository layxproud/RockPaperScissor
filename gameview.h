#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>

class GameView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GameView(QWidget *parent = nullptr);
    void showImage(int index);

private:
    QGraphicsScene *scene;
    QGraphicsPixmapItem *image;
};

#endif // GAMEVIEW_H
