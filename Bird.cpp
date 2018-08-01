#include "Bird.h"

void Bird::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QPixmap floppy("floppy.png");
	floppy.scaled(QSize(40,40), Qt::KeepAspectRatio);
	painter->drawPixmap(0,0,40,50,floppy);
}

QRectF Bird::boundingRect() const {
	QRect rect(0,0,40,50);
	return rect;
}

QPainterPath Bird::shape() const {
	QPainterPath pointerPath;
	pointerPath.addEllipse(0,0,40,50);
	return pointerPath;
}

Bird::Bird() {

}

void Bird::advance(int step)
{
	if(!step)
	{
		return;
	}
	setPos(mapToParent(0,5));
}
