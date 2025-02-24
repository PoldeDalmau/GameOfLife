#include <QApplication>
// #include <iostream>
#include "src/GameOfLifeModel.h"
#include "src/GridWidgetView.h"
#include "src/GameOfLifeController.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif // _WIN32

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    
    // Field Dimensions
    const int screen_width = 150;
    const int screen_height = 150;
    
    GameOfLifeModel model(screen_width, screen_height);
    model.initializeGliderGun();
    GridWidgetView grid(&model);
    GameOfLifeController controller(&model, &grid);
    // Connect the startGame signal to the startGameLoop slot
    QObject::connect(&grid, &GridWidgetView::startGame, &controller, &GameOfLifeController::startGameLoop);
    // handle the button click event
    grid.drawButton();

    grid.show();

    return a.exec();
}