#ifndef SNAKEMOVE_H
#define SNAKEMOVE_H
#include <snakehead.h>
#include <snakebody.h>
#include <QTimer>
#include <QObject>
#include <QDebug>

class Snakemove : public QObject
{
		Q_OBJECT
	public:
		explicit Snakemove(QObject *parent = nullptr);
	Snakehead* head;
	Snakebody* body;


	signals:

	public slots:



};

#endif // SNAKEMOVE_H
