#ifndef GAMEOFLIFEMODEL_H
#define GAMEOFLIFEMODEL_H

#include <vector>

class GameOfLifeModel {
public:
    GameOfLifeModel(int width, int height);

    void update();
    bool getCell(int x, int y) const;
    int getWidth() const;
    int getHeight() const;

private:
    int width, height;
    std::vector<std::vector<bool>> grid;

    int countNeighbors(int x, int y) const;
};

#endif // GAMEOFLIFEMODEL_H
