#include "fruit.h"

Fruit::Fruit(QObject* parent)
{
	setRect(0,0,35,35);
	QRadialGradient radi;
	radi.setRadius(50);
	radi.setColorAt(0,Qt::red);
	radi.setColorAt(1,Qt::blue);
	setBrush(radi);

}

QRectF Fruit::boundingRect() const
{
	return QRectF(0,0,35,35);
}

