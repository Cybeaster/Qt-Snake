#include "snakemove.h"

Snakemove::Snakemove(QObject *parent) : QObject(parent)
{
	head = new Snakehead(this);
	head->setPos(0,0);
	head->setdirection(Snakehead::DOWN);
	body = new Snakebody(this);
	body->setPos(0,0);
}

