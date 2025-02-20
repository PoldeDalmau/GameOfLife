#include <QApplication>
#include <iostream>
#include "GameOfLifeModel.h"
#include "GridWidgetView.h"
#include "GameOfLifeController.h"  // Include the new header file

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif // _WIN32

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    
    // Field Dimensions
    const int screen_width = 50;
    const int screen_height = 50;
    
    GameOfLifeModel model(screen_width, screen_height);
    GridWidgetView grid(&model);
    GameOfLifeController controller(&model, &grid);

    // // Create Grid Widget and Display Initial State
    
    // Optional: run controller in background to update game state
    // controller.run();
    grid.resize(screen_width * 20, screen_height * 20);  // Adjust size based on grid dimensions
    grid.show();

    return a.exec();
}