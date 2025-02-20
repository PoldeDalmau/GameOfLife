#include "GameOfLifeController.h"

GameOfLifeController::GameOfLifeController(GameOfLifeModel* model, GridWidgetView* view)
    : model(model), view(view) {
    
    // Create QTimer and set 1-second interval
    QTimer* timer = new QTimer(this);
    timer->setInterval(100);  // 1000 ms = 1 second
    
    // Connect QTimer's timeout signal to the update slot
    connect(timer, &QTimer::timeout, this, &GameOfLifeController::updateGame);
    
    // Start the timer
    timer->start();
}

void GameOfLifeController::updateGame() {
    // Update the model state
    model->update();

    // Redraw the GridWidgetView
    view->update();
}
