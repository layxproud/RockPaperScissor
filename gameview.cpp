#include "gameview.h"
#include "game.h"
#include <QGraphicsPixmapItem>

extern Game *game;

#define WIDTH 300
#define HEIGHT 300

GameView::GameView(QWidget *parent)
    : QGraphicsView{parent}
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, WIDTH, HEIGHT);
    setFixedSize(WIDTH, HEIGHT);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setScene(scene);

    image = nullptr;
}

void GameView::showImage(int index)
{
    if (image){
        scene->removeItem(image);
        delete image;
    }
    image = new QGraphicsPixmapItem();
    image->setPixmap(QPixmap(game->images[index]));
    scene->addItem(image);
}
