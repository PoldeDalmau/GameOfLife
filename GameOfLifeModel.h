#ifndef GAMEOFLIFEMODEL_H
#define GAMEOFLIFEMODEL_H

#include <vector>
#include <cstdlib>

class GameOfLifeModel {
public:
    GameOfLifeModel(int width, int height);

    void update();
    bool getCell(int x, int y) const;
    int getWidth() const;
    int getHeight() const;
    void setCell(int x, int y, bool state);
    int get_max_pixel_side() const;
    void initializeGlider();
    void initializeBlinker();
    void initializeGliderGun();
    void initializeRandom();

private:
    int width, height;
    int max_pixel_side = 700;
    std::vector<std::vector<bool>> grid;

    int countNeighbors(int x, int y) const;
};

#endif // GAMEOFLIFEMODEL_H
