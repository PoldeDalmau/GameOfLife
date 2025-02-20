#ifndef GAMEOFLIFECONTROLLER_H
#define GAMEOFLIFECONTROLLER_H

#include <QObject>
#include <QTimer>
#include "GameOfLifeModel.h"
#include "GridWidgetView.h"

class GameOfLifeController : public QObject {
    Q_OBJECT
public:
    GameOfLifeController(GameOfLifeModel* model, GridWidgetView* view);

public slots:
    void updateGame();

private:
    GameOfLifeModel* model;
    GridWidgetView* view;
};

#endif // GAMEOFLIFECONTROLLER_H
