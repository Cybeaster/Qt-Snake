#include "snakebody.h"
#include <snakehead.h>


Snakebody::Snakebody (QObject* parents)
{
	setRect(0,0,50,50);
	QBrush brush;
	brush.setColor(Qt::green);
	brush.setStyle(Qt::Dense2Pattern);
	setBrush(brush);


}

QRectF Snakebody::boundingRect() const
{
	return QRectF(0,0,50,50);
}

