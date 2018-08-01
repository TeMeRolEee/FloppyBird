#pragma once


#include <QtWidgets/QGraphicsPixmapItem>
#include <QPainter>

class Bird : public QGraphicsPixmapItem
{
public:
    Bird();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

protected:
    void advance(int step);
};

