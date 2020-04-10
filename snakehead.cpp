#include "snakehead.h"

Snakehead::Snakehead(QObject *parent)
{

	setRect(0,0,50,50);
	QBrush brush;
	brush.setColor(Qt::blue);
	brush.setStyle(Qt::Dense1Pattern);
	setBrush(brush);
	setFlag(QGraphicsItem::ItemIsFocusable);
	dir = DOWN;


}

QRectF Snakehead::boundingRect() const
{
	return QRectF(0,0,50,50);
}

void Snakehead::setdirection(Snakehead::Direction direction)
{
	dir = direction;
}

Snakehead::Direction Snakehead::getdirection()
{
	return dir;
}

void Snakehead::keyPressEvent(QKeyEvent *event)
{
	//qDebug()<<getdirection();
	if((event->key() == Qt::Key_W || event->key() == Qt::Key_Up) && getdirection() != Snakehead::DOWN)
		{
			setdirection(Snakehead::UP);
		}
	if((event->key() == Qt::Key_S || event->key() == Qt::Key_Down) && getdirection() != Snakehead::UP)
		{
			setdirection(Snakehead::DOWN);

		}
	if((event->key() == Qt::Key_A || event->key() == Qt::Key_Left) && getdirection() != Snakehead::RIGHT)
		{
			setdirection(Snakehead::LEFT);

		}
	if((event->key() == Qt::Key_D || event->key() == Qt::Key_Right) && getdirection() != Snakehead::LEFT)
		{
			setdirection(Snakehead::RIGHT);
		}

}





