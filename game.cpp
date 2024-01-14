#include "game.h"

Game::Game(QObject *parent)
    : QObject{parent}
{
    // Create map of images
    images = {{0, ":/images/rock.png"},
              {1, ":/images/scissors.png"},
              {2, ":/images/paper.png"}};

    // Init values
    currentWinStreak = 0;
    bestWinStreak = 0;
    wins = 0;
    losses = 0;
    ties = 0;
}

int Game::determineWinner(int playerIdx, int opponentIdx)
{
    if (playerIdx == opponentIdx){
        ties++;
        return 0;
    }
    else if ((playerIdx == 0 && opponentIdx == 1) ||
             (playerIdx == 1 && opponentIdx == 2) ||
             (playerIdx == 2 && opponentIdx == 0)){
        wins++;
        currentWinStreak++;
        return 1;
    }
    else{
        losses++;
        if (currentWinStreak > bestWinStreak){
            bestWinStreak = currentWinStreak;
        }
        currentWinStreak = 0;
        return 2;
    }
}
