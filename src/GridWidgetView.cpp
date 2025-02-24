#include "GridWidgetView.h"

GridWidgetView::GridWidgetView(GameOfLifeModel* model, QWidget *parent)
    : model(model), QWidget(parent) {
    }
    
    void GridWidgetView::paintEvent(QPaintEvent *event) {
    // resize the grid to fit the window
    setFixedSize(model->get_max_pixel_side() * model->getWidth()/std::max(model->getWidth(), model->getHeight()), model->get_max_pixel_side() * model->getHeight()/std::max(model->getWidth(), model->getHeight()));
        
    QPainter painter(this);
    int cellSize = model->get_max_pixel_side() / std::max(model->getWidth(), model->getHeight());
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

void GridWidgetView::drawButton() {
    QPushButton* button = new QPushButton("Click Me", this);
    button->setGeometry(QRect(QPoint(10, 10), QSize(80, 30)));

    connect(button, &QPushButton::clicked, this, &GridWidgetView::handleButtonClick);
}

void GridWidgetView::handleButtonClick() {
    // Emit the startGame signal
    emit startGame();
}