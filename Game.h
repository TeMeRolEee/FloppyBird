#pragma once


#include <QtCore/QObject>
#include <QtWidgets/QGraphicsScene>
#include <QtCore/QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <QDialog>

#include "Bird.h"


class Game: public QObject
{
Q_OBJECT
public:
    Game(QGraphicsScene &scene);

protected:
    void loop_slot();
    void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    QGraphicsScene &scene;
    Bird *bird = nullptr;
    QTimer mainLoopTimer;
    int loopCounter;
};


