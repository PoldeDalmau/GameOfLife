#include "GameOfLifeModel.h"

GameOfLifeModel::GameOfLifeModel(int width, int height)
    : width(width), height(height), grid(height, std::vector<bool>(width, false)) {
    // Initial state: Glider 
    grid[5][8] = true; grid[6][6] = true; grid[6][8] = true; grid[7][7] = true; grid[7][8] = true;

    // initial state from wiki  
    // grid[9][9] = true; grid[10][8] = true; grid[10][9] = true; grid[11][9] = true; grid[11][10] = true;
    
    // initial state Blinker:
    // grid[5][2] = true; grid[6][2] = true; grid[7][2] = true;
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
