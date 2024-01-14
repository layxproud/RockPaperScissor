#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QMap>

class Game : public QObject
{
    Q_OBJECT

public:
    Game(QObject *parent = nullptr);
    QMap<int, QString> images;
    int determineWinner(int playerIdx, int opponentIdx);

    int currentWinStreak;
    int bestWinStreak;
    int wins;
    int losses;
    int ties;

};

#endif // GAME_H
