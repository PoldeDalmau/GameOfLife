#include "GameOfLifeModel.h"

GameOfLifeModel::GameOfLifeModel(int width, int height)
    : width(width), height(height), grid(height, std::vector<bool>(width, false)) {}

void GameOfLifeModel::initializeGlider(){
    grid[5][8] = true; grid[6][6] = true; grid[6][8] = true; grid[7][7] = true; grid[7][8] = true;
}

void GameOfLifeModel::initializeBlinker(){
    grid[5][2] = true; grid[6][2] = true; grid[7][2] = true;
}

void GameOfLifeModel::initializeGliderGun(){
    // gosper glider gun
    grid[0+50][25+50] = true;   grid[1+50][23+50] = true;  grid[1+50][25+50] = true; grid[2+50][13+50] = true;    grid[2+50][14+50] = true;   grid[2+50][21+50] = true;  grid[2+50][22+50] = true; grid[2+50][35+50] = true;    grid[2+50][36+50] = true;   grid[3+50][12+50] = true;  grid[3+50][16+50] = true; grid[3+50][21+50] = true;    grid[3+50][22+50] = true;   grid[3+50][35+50] = true;  grid[3+50][36+50] = true; grid[4+50][1+50] = true; grid[4+50][2+50] = true; grid[4+50][11+50] = true;    grid[4+50][17+50] = true;   grid[4+50][21+50] = true;  grid[4+50][22+50] = true; grid[5+50][1+50] = true; grid[5+50][2+50] = true; grid[5+50][11+50] = true;    grid[5+50][15+50] = true;   grid[5+50][17+50] = true;  grid[5+50][18+50] = true; grid[5+50][23+50] = true;    grid[5+50][25+50] = true;   grid[6+50][11+50] = true;  grid[6+50][17+50] = true; grid[6+50][25+50] = true;    grid[7+50][12+50] = true;   grid[7+50][16+50] = true;  grid[8+50][13+50] = true; grid[8+50][14+50] = true;

}
void GameOfLifeModel::initializeStableEnd(){
    grid[59][59] = true; grid[60][58] = true; grid[60][59] = true; grid[61][59] = true; grid[61][60] = true;
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
