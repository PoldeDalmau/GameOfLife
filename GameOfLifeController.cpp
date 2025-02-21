#include "GameOfLifeController.h"

GameOfLifeController::GameOfLifeController(GameOfLifeModel* model, GridWidgetView* view)
    : model(model), view(view) {
    timer = new QTimer(this);
    timer->setInterval(100);  // 100 ms interval
    connect(timer, &QTimer::timeout, this, &GameOfLifeController::updateGame);
}

void GameOfLifeController::updateGame() {
    // Update the model state
    model->update();

    // Redraw the GridWidgetView
    view->update();
}

void GameOfLifeController::startGameLoop() {
    // Start the timer
    timer->start();
}