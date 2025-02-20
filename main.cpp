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
    const int screen_width = 70;
    const int screen_height = 70;
    
    GameOfLifeModel model(screen_width, screen_height);
    model.initializeGliderGun();
    GridWidgetView grid(&model);
    GameOfLifeController controller(&model, &grid);

    grid.show();

    return a.exec();
}