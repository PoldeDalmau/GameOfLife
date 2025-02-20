#include <gtest/gtest.h>
#include "GameOfLifeModel.h"

TEST(GameOfLifeModelTest, InitialState) {
    GameOfLifeModel model(20, 20);
    EXPECT_FALSE(model.getCell(0, 0));
    EXPECT_FALSE(model.getCell(9, 9));
    EXPECT_FALSE(model.getCell(10, 8));
    EXPECT_FALSE(model.getCell(10, 9));
    EXPECT_FALSE(model.getCell(11, 9));
    EXPECT_FALSE(model.getCell(11, 10));
}

// TEST(GameOfLifeModelTest, UpdateState) {
//     GameOfLifeModel model(5, 5);
//     model.update();
//     EXPECT_FALSE(model.getCell(9, 9));
//     EXPECT_FALSE(model.getCell(10, 8));
//     EXPECT_TRUE(model.getCell(10, 9));
//     EXPECT_TRUE(model.getCell(11, 9));
//     EXPECT_FALSE(model.getCell(11, 10));
// }