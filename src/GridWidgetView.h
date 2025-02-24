#ifndef GRIDWIDGETVIEW_H
#define GRIDWIDGETVIEW_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include <QMessageBox>
#include "GameOfLifeModel.h"

class GridWidgetView : public QWidget {
    Q_OBJECT
public:
    GridWidgetView(GameOfLifeModel* model, QWidget *parent = nullptr);
    void drawButton();
    void handleButtonClick();

    signals:
    void startGame();

    protected:
    void paintEvent(QPaintEvent *event) override;

private:
    GameOfLifeModel* model;
};

#endif // GRIDWIDGETVIEW_H
