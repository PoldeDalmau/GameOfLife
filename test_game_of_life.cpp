#include <gtest/gtest.h>
#include "src/GameOfLifeModel.h"

TEST(GameOfLifeModelTest, InitialState) {
    GameOfLifeModel model(20, 20);
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            EXPECT_FALSE(model.getCell(i, j)) << "Cell (" << i << ", " << j << ") should be dead initially.";
        }
    }
}

TEST(GameOfLifeModelTest, UpdateState) {
    GameOfLifeModel model(5, 5);
    // Set up an initial state with a glider
    model.setCell(1, 0, true);
    model.setCell(2, 1, true);
    model.setCell(0, 2, true);
    model.setCell(1, 2, true);
    model.setCell(2, 2, true);

    // Update the model
    model.update();

    // Check the new state
    EXPECT_FALSE(model.getCell(0, 0));
    EXPECT_FALSE(model.getCell(1, 0));
    EXPECT_FALSE(model.getCell(2, 0));
    EXPECT_TRUE(model.getCell(0, 1));
    EXPECT_FALSE(model.getCell(1, 1));
    EXPECT_TRUE(model.getCell(2, 1));
    EXPECT_FALSE(model.getCell(0, 2));
    EXPECT_TRUE(model.getCell(1, 2));
    EXPECT_TRUE(model.getCell(2, 2));
}

TEST(GameOfLifeModelTest, BoundaryConditions) {
    GameOfLifeModel model(5, 5);
    // Set up cells at the boundary
    model.setCell(0, 0, true);
    model.setCell(4, 4, true);

    // Update the model
    model.update();

    // Check the new state
    EXPECT_FALSE(model.getCell(0, 0));
    EXPECT_FALSE(model.getCell(4, 4));
}

TEST(GameOfLifeModelTest, CellState) {
    GameOfLifeModel model(5, 5);
    model.setCell(2, 2, true);
    EXPECT_TRUE(model.getCell(2, 2)) << "Cell (2, 2) should be alive.";
    model.setCell(2, 2, false);
    EXPECT_FALSE(model.getCell(2, 2)) << "Cell (2, 2) should be dead.";
}