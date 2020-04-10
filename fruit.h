#ifndef FRUIT_H
#define FRUIT_H
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QBrush>
#include <QGradient>
class Fruit : public QGraphicsEllipseItem
{
	public:
		Fruit(QObject* parent = nullptr);
		QRectF boundingRect() const override;
};

#endif // FRUIT_H
