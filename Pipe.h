#pragma once


#include <QtWidgets/QGraphicsItem>
#include <QPainter>

class Pipe: public QGraphicsItem
{
public:
    Pipe(qreal height);

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void advance(int step);

private:
    QRectF pipeShape;
};

