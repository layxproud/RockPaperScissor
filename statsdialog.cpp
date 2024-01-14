#include "statsdialog.h"
#include "ui_statsdialog.h"
#include "game.h"
#include <QDebug>

extern Game *game;

StatsDialog::StatsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatsDialog)
{
    ui->setupUi(this);

    setFixedSize(139, 122);

    ui->winsValue->setText(QString::number(game->wins));
    ui->lossesValue->setText(QString::number(game->losses));
    ui->tiesValue->setText(QString::number(game->ties));
    ui->bestWinStreakValue->setText(QString::number(game->bestWinStreak));
    ui->currWinStreakValue->setText(QString::number(game->currentWinStreak));
}

StatsDialog::~StatsDialog()
{
    delete ui;
}
