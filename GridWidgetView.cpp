#include "GridWidgetView.h"

GridWidgetView::GridWidgetView(GameOfLifeModel* model, QWidget *parent)
    : model(model), QWidget(parent) {}

void GridWidgetView::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    int cellSize = 20;
    int rows = model->getHeight();
    int cols = model->getWidth();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (model->getCell(i, j)) {
                painter.setBrush(Qt::black);  // Live cell
            } else {
                painter.setBrush(Qt::lightGray); // Dead cell
            }
            int x = j * cellSize;
            int y = i * cellSize;
            painter.drawRect(x, y, cellSize, cellSize);  // Draw cell
        }
    }
}
