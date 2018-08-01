#include "Pipe.h"


Pipe::Pipe(qreal height)
{
    pipeShape = QRectF(0,0,60,height);
}

QRectF Pipe::boundingRect() const {
    return pipeShape;
}

QPainterPath Pipe::shape() const {
    QPainterPath path;
    path.addRect(pipeShape);
    return path;
}

void Pipe::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::green);
    painter->drawRoundedRect(pipeShape, 2.0, 2.0);
}

void Pipe::advance(int step) {
    if(!step)
    {
        return;
    }

    moveBy(-5, 0);
}

