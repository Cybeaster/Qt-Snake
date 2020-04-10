#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H
#include <QBrush>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <fruit.h>
#include <snakebody.h>



class Snakehead : public QGraphicsRectItem
{
public:
	Snakehead(QObject *parent = nullptr);
	QRectF boundingRect() const;
	enum  Direction
	{UP,DOWN,LEFT,RIGHT,STOP};
	void setdirection(Direction direction);
	Direction getdirection();
	void keyPressEvent(QKeyEvent *event);
	private:
	QPoint prevpos;
	Direction dir;





};

#endif // SNAKEHEAD_H
