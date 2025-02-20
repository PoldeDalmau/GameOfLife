#include "GameOfLifeModel.h"

GameOfLifeModel::GameOfLifeModel(int width, int height)
    : width(width), height(height), grid(height, std::vector<bool>(width, false)) {
    
    // initial state from wiki  
    // grid[59][59] = true; grid[60][58] = true; grid[60][59] = true; grid[61][59] = true; grid[61][60] = true;
    
    // initial state Blinker:
    // grid[5][2] = true; grid[6][2] = true; grid[7][2] = true;
}

void GameOfLifeModel::initializeGlider(){
    grid[5][8] = true; grid[6][6] = true; grid[6][8] = true; grid[7][7] = true; grid[7][8] = true;
}

void GameOfLifeModel::initializeBlinker(){
    grid[5][2] = true; grid[6][2] = true; grid[7][2] = true;
}

void GameOfLifeModel::initializeGliderGun(){
    // gosper glider gun
    //(24, 0)(22, 1)(24, 1)(12, 2)(13, 2)(20, 2)(21, 2)(12, 3)(16, 3)(20, 3)(21, 3)(0, 4)(1, 4)(9, 4)(15, 4)(20, 4)(1, 5)(9, 5)(13, 5)(14, 5)(18, 5)(22, 5)(9, 6)(15, 6)(9, 7)(13, 7)(12, 8)
    grid[24][0] = true; grid[22][1] = true; grid[24][1] = true; grid[12][2] = true; grid[13][2] = true; grid[20][2] = true; grid[21][2] = true; grid[12][3] = true; grid[16][3] = true; grid[20][3] = true; grid[21][3] = true; grid[0][4] = true; grid[1][4] = true; grid[9][4] = true; grid[15][4] = true; grid[20][4] = true; grid[1][5] = true; grid[9][5] = true; grid[13][5] = true; grid[14][5] = true; grid[18][5] = true; grid[22][5] = true; grid[9][6] = true; grid[15][6] = true; grid[9][7] = true; grid[13][7] = true; grid[12][8] = true;

}

void GameOfLifeModel::initializeRandom(){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = std::rand() % 2;
        }
    }
}


void GameOfLifeModel::update() {
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

bool GameOfLifeModel::getCell(int x, int y) const {
    return grid[x][y];
}

int GameOfLifeModel::getWidth() const {
    return width;
}

int GameOfLifeModel::getHeight() const {
    return height;
}

int GameOfLifeModel::get_max_pixel_side() const {
    return max_pixel_side;
}

void GameOfLifeModel::setCell(int x, int y, bool state) {
    grid[x][y] = state;
}

int GameOfLifeModel::countNeighbors(int x, int y) const {
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
