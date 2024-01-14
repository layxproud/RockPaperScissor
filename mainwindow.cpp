#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include "statsdialog.h"
#include <QRandomGenerator>

extern Game *game;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(624, 442);

    // Setup view
    playerView = new GameView(this);
    opponentView = new GameView(this);

    // Add views to UI
    ui->sceneLayout->addWidget(playerView);
    ui->sceneLayout->addWidget(opponentView);

    // Fill combobox
    QStringList list;
    list << "Камень" << "Ножницы" << "Бумага";
    ui->selectMoveCombo->addItems(list);

    // Make connects
    connect(ui->makeMoveButton, &QPushButton::clicked, this, &MainWindow::onMakeMoveButtonClicked);
    connect(ui->statsAction, &QAction::triggered, this, &MainWindow::onStatsActionTriggered);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayResults(int result)
{
    QPalette palette = ui->gameResult->palette();

    switch (result) {
    case 0:
        palette.setColor(ui->gameResult->foregroundRole(), Qt::darkYellow);
        ui->gameResult->setPalette(palette);
        ui->gameResult->setText("НИЧЬЯ");
        break;
    case 1:
        palette.setColor(ui->gameResult->foregroundRole(), Qt::darkGreen);
        ui->gameResult->setPalette(palette);
        ui->gameResult->setText("ПОБЕДА");
        break;
    case 2:
        palette.setColor(ui->gameResult->foregroundRole(), Qt::darkRed);
        ui->gameResult->setPalette(palette);
        ui->gameResult->setText("ПОРАЖЕНИЕ");
        break;
    default:
        break;
    }
}

void MainWindow::onMakeMoveButtonClicked()
{
    int playerMove = ui->selectMoveCombo->currentIndex();
    playerView->showImage(playerMove);
    int opponentMove = QRandomGenerator::global()->generate() % 3;
    opponentView->showImage(opponentMove);

    int result = game->determineWinner(playerMove, opponentMove);
    displayResults(result);
}

void MainWindow::onStatsActionTriggered()
{
    StatsDialog d;
    d.exec();
}

