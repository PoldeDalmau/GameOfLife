#include <iostream>
#include <vector>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif // _WIN32

///////////////////////////
// MODEL
///////////////////////////
class GameOfLifeModel {
public:
    GameOfLifeModel(int width, int height)
        : width(width), height(height), grid(height, std::vector<bool>(width, false)) {
        // Initial state: Glider
        grid[5][8] = true;
        grid[6][6] = true;
        grid[6][8] = true;
        grid[7][7] = true;
        grid[7][8] = true;
        // initial state from wiki
        // grid[9][9] = true;
        // grid[10][8] = true;
        // grid[10][9] = true;
        // grid[11][9] = true;
        // grid[11][10] = true;

        // initial state Blinker:
        //grid[5][2] = true;
        // grid[6][2] = true;
        // grid[7][2] = true;

    }

    void update() {
        std::vector<std::vector<bool>> newGrid = grid;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int neighbors = countNeighbors(i, j);
                if (grid[i][j]) {
                    newGrid[i][j] = (neighbors == 2 || neighbors == 3);
                } else {
                    newGrid[i][j] = (neighbors == 3);
                }
            }
        }
        grid = newGrid;
    }

    bool getCell(int x, int y) const {
        return grid[x][y];
    }

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

private:
    int width, height;
    std::vector<std::vector<bool>> grid;

    int countNeighbors(int x, int y) const {
        int neighbors = 0;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;
                int nx = (x + dx + height) % height;
                int ny = (y + dy + width) % width;
                neighbors += grid[nx][ny];
            }
        }
        return neighbors;
    }
};

///////////////////////////
// VIEW
///////////////////////////
class GameOfLifeView {
public:
    GameOfLifeView(GameOfLifeModel* model) : model(model) {}

    void display(int num_ticks) const {
        system("clear");
        std::cout << "Tick: " << num_ticks << "\n";
        for (int i = 0; i < model->getHeight(); i++) {
            for (int j = 0; j < model->getWidth(); j++) {
                std::cout << (model->getCell(i, j) ? "O" : ".") << " ";
            }
            std::cout << "\n";
        }
    }
    
    void sleepcp(int milliseconds) const {
        #ifdef _WIN32
            Sleep(milliseconds);
        #else
            usleep(milliseconds * 1000);
        #endif // _WIN32
    }

private:
    GameOfLifeModel* model;
};

///////////////////////////
// CONTROLLER
///////////////////////////
class GameOfLifeController {
public:
    GameOfLifeController(GameOfLifeModel* model, GameOfLifeView* view)
        : model(model), view(view) {}

    void run() {
        int num_ticks = 0;
        while (true) {
            view->display(num_ticks++);
            model->update();
            view->sleepcp(200);
        }
    }

private:
    GameOfLifeModel* model;
    GameOfLifeView* view;
};

///////////////////////////
// MAIN FUNCTION
///////////////////////////
int main() {
    
    // Screen Dimensions
    const int screen_width = 10;
    const int screen_height = 10;
    
    GameOfLifeModel model(screen_width, screen_height);
    GameOfLifeView view(&model);
    GameOfLifeController controller(&model, &view);

    controller.run();
    return 0;
}
