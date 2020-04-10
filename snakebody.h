#ifndef SNAKEBODY_H
#define SNAKEBODY_H
#include <snakehead.h>
#include <QList>
#include <QListIterator>
class Snakebody : public QGraphicsRectItem
{
	public:
		Snakebody(QObject* parents = nullptr);
		QRectF boundingRect() const;

};

#endif // SNAKEBODY_H
